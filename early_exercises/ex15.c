#include <stdio.h>

// Lets talk about pointers... *feeling chills coming down my spine*.
int main(int argc, char *argv[])
{
	/* code */
	// Creating two arrays we want to mess around with.
	int ages[] = {23, 43, 12, 89, 2};
	char *names[] = {
		"Alan", "Don", "Grace", "Linus", "Ada"
	};
 
 	// Safely get the size of the arrays.
 	int count = sizeof(ages) /sizeof(int);
 	int i = 0;

 	// First lets use indexing to access the array.
 	for (i = 0; i < count; i++) {
 		printf("%s is %d years old. \n", names[i], ages[i]);
 	}

 	printf("---\n");

 	// Setup some pointers to the start of the arrays.
 	int *curr_age = ages;
 	char **curr_name = names;

 	// Second way is to using pointer addition.
 	for (i = 0; i < count; i++) {
 		printf("%s is %d years old. \n", *(curr_name + i), *(curr_age + i));	
 	}

 	printf("---\n");

 	// Third way, pointers are just arrays...?
 	for (i = 0; i < count; i++) {
 		printf("%s is %d years old. \n", curr_name[i], curr_age[i]);	
 	}

 	printf("---\n");

 	// Fourth way with pointers... in a stupid complex way involving creeping pointers.
 	for (curr_name = names, curr_age = ages; 
 		(curr_age - ages) < count; 
 		curr_name++, curr_age++) {

 		printf("%s lived %d years so far. \n", *curr_name, *curr_age);
 	}

	return 0;
}