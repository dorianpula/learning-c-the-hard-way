// Now we're getting a lot more exciting techniques.

#include <stdio.h>
#include <assert.h>
#include <stdlib.h>
#include <string.h>

struct Person {
	char *name;
	int age;
	int height;
	int weight;
};

// Constructor for the person.
struct Person *Person_create(char *name, int age, int height, int weight)
{
	// Nifty... allocating memory for a new struct.
	struct Person *who = malloc(sizeof(struct Person));
	assert(who != NULL);

	who->name = strdup(name); // Duplicate the string argument.
	who->age = age;
	who->height = height;
	who->weight = weight;

	return who;
};

// And a destructor... how very C++-ish
void Person_destroy(struct Person *who)
{
	assert(who != NULL);

	// Make sure we free all of the memory we grabbed for this struct.
	free(who->name);
	free(who);
}

// ...and a toString() equiv in C.
void Person_print(struct Person *who)
{
	printf("Name: %s\n", who->name);
	printf("\tAge: %d\n", who->age);
	printf("\tHeight: %d\n", who->height);
	printf("\tWeight: %d\n", who->weight);

}

int main(int argc, char *argv[])
{
	// Make two Persons...
	struct Person *joe = Person_create("Joe Doe", 32, 64, 140);
	struct Person *frank = Person_create("Frank Blank", 20, 72, 180);

	// Print out their memory address and their string repr.
	printf("Joe is at memory location %p: \n", joe);
	Person_print(joe);

	printf("Frank is at memory location %p: \n", frank);
	Person_print(frank);

	// Age them both by 20 years. :P
	joe->age += 20;
	joe->height -= 2;
	joe->weight += 40;
	Person_print(joe);

	frank->age += 20;
	frank->weight += 20;
	Person_print(frank);

	// Destroy them both, to recapture the memory and cleanup.
	Person_destroy(joe);
	Person_destroy(frank);

	return 0;
}