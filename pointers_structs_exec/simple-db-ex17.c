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

	// TODO Carry on from here...

}