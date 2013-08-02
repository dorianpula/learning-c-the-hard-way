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

	if ret_code = fwrite(conn->db, sizeof(struct Database), 1, conn->file);
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

// TODO: Continue on from here...