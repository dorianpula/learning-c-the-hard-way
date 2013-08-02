#include <stdio.h>
#include <assert.h>
#include <stdlib.h>
#include <errno.h>
#include <string.h>

// w00t!  Pre-processor macros!
#define MAX_DATA 512
#define MAX_ROWS 100

// Structures.
struct Address {
	int id;
	int set;
	char name[MAX_DATA];
	char email[MAX_DATA];
};

struct Database
{
	struct Address rows[MAX_ROWS];
};

struct Connection
{
	FILE *file;
	struct Database *db;
};

// Simulate the database.
void die(const char *message) 
{
	if(errno) {
		perror(message);
	} else {
		printf("ERROR: %s\n", message);
	}

	exit(EXIT_FAILURE);
}

// Print the addresses.
void Address_print(struct Address *addr) 
{
	printf("%d %s %s\n", addr->id, addr->name, addr->email);
}

// Load the database from a file.
void Database_load(struct Connection *conn)
{
	// Read file conn->file with the size of the datbase structure 
	// into the pointer conn->db 
	int ret_code = fread(conn->db, sizeof(struct Database), 1, conn->file);
	if(ret_code != 1) die("Failed to load database.");
}

// Open the database...
struct Connection *Database_open(const char *filename, char mode) 
{
	struct Connection *conn = malloc(sizeof(struct Connection));
	if(!conn) die("Memory error");

	// Attempt to initialize the database in memory.
	conn->db = malloc(sizeof(struct Database));
	if (!conn->db) die("Memory error when initializing database.");

	// Open the file in write or read depending on the mode.
	if (mode == 'c') {
		conn->file = fopen(filename, "w");
	} else {
		conn->file = fopen(filename, "r+");

		if (conn->file) {
			Database_load(conn);
		}
	}

	if (!conn->file) die("Failed to open the file.");

	return conn;
}

// Close the database Connection
void Database_close(struct Connection *conn)
{
	if (conn) {
		if (conn->file) fclose(conn->file);
		if (conn->db) free(conn->db);
		free(conn);
	}
}

// Write to the database
void Database_write(struct Connection *conn)
{
	// Rewinds the file.
	rewind(conn->file);

	int ret_code = fwrite(conn->db, sizeof(struct Database), 1, conn->file);
	if (ret_code != 1) die("Failed to write database.");

	// Flush the remaining user space buffers into the file.
	ret_code = fflush(conn->file);
	if (ret_code == -1) die("Cannot flush database.");
}

// Create the database.
void Database_create(struct Connection *conn)
{
	int i = 0;

	for (i = 0; i < MAX_ROWS; i++){
		// Makes a prototype and initializes it.
		struct Address addr = {.id = i, .set = 0};
		// Then assign it.
		conn->db->rows[i] = addr;
	}
}

// Sets values in the database.
void Database_set(struct Connection *conn, int id, const char *name, const char *email)
{
	// Set the pointer of an address to the row in the database we want to set.
	struct Address *addr = &conn->db->rows[id];
	if (addr->set) die("Alreadt set, delete it first.");

	addr->set = 1;
	// WARNING: bug, fix it.
	// char *res = strncpy(addr->name, name, MAX_DATA);
	// // demostrate the strncpy bug.
	// if (!res) die("Name copy failed.");
	 
	// 	TODO: Note that strncpy simply copies the string by n-bytes.  
	// 	If string < n, fill with null-terminating characters.
	// 	If string > n, then the string will not have a null-terminator at the end!
	

	// res = strncpy(addr->email, email, MAX_DATA);
	// if (!res) die("Email copy failed.");

	// Now with a half-decent fix.
	char *res = strncpy(addr->name, name, MAX_DATA);
	res[MAX_DATA - 1] = '\0'; 

	// demostrate the strncpy bug.
	if (!res) die("Name copy failed.");
	/* 
		TODO: Note that strncpy simply copies the string by n-bytes.  
		If string < n, fill with null-terminating characters.
		If string > n, then the string will not have a null-terminator at the end!
		So we need to fix that.
	*/

	res = strncpy(addr->email, email, MAX_DATA);
	res[MAX_DATA - 1] = '\0';
	if (!res) die("Email copy failed.");
}

// Get a particular value from the database.
void Database_get(struct Connection *conn, int id)
{
	struct Address *addr = &conn->db->rows[id];

	if (addr->set) {
		Address_print(addr);
	} else {
		die("ID is not set.");
	}
}

// "Deletes" a particular value from the database
void Database_delete(struct Connection *conn, int id)
{
	struct Address addr = {.id = id, .set = 0};
	conn->db->rows[id] = addr;
}

void Database_list(struct Connection *conn)
{
	int i = 0;
	struct Database *db = conn->db;

	for (i = 0; i < MAX_ROWS; i++) {
		struct Address *current = &db->rows[i];
		if (current->set) {
			Address_print(current);
		}
	}
}

int main(int argc, char *argv[])
{
	/* code */
	if (argc < 3) die("USAGE: simple-db-ex17 <dbfile> <action> [action params]");

	// Handle the parameters given.
	char *filename = argv[1];
	char action = argv[2][0]; // single letter actions.

	struct Connection *conn = Database_open(filename, action);
	int id = 0;

	// atoi(const char *nmr) in stdlib.h converts *nmr into an int.
	if(argc > 3) id = atoi(argv[3]); // Get the ID argument.
	if(id >= MAX_ROWS) die("There is not that many records.");

	switch(action) {
		case 'c':
			Database_create(conn);
			Database_write(conn);
			break;

		case 'g':
			if(argc != 4) die("Need an id to get.");
			
			Database_get(conn, id);
			break;

		case 's':
			if(argc != 6) die("Need id, name, email to set");
			
			Database_set(conn, id, argv[4], argv[5]);
			Database_write(conn);
			break;

		case 'd':
			if (argc != 4) die("Need id to delete");

			Database_delete(conn, id);
			Database_write(conn);
			break;

		case 'l':
			Database_list(conn);
			break;

		default:
			die("Invalid action, only: c=create, g=get, s=set, d=delete, l=list");
	}

	Database_close(conn);

	return EXIT_SUCCESS;
}