// Lets build something that is functional.
#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

// Forward declarations without dumping them into a header file.
int can_print_it(char ch);
void print_letters(char arg[]);

// Print out the arguments.
void print_arguments(int argc, char *argv[]) {
	
	int i = 0;

	for (i = 0; i < argc; i++) {
		print_letters(argv[i]);
	}
}

void print_letters(char arg[]) {

	int i = 0;

	for (i = 0; arg[i] != '\0'; i++) {

		char ch = arg[i];

		if (can_print_it(ch)) {
			printf("'%c' == %d ", ch, ch);
		}
	}

	printf("\n");
}

// Figures out if the character is a printable character as in alphanumeric.
int can_print_it(char ch) {
	return isalpha(ch) || isblank(ch);
}

int main(int argc, char *argv[]) {

	print_arguments(argc, argv);
	return 0;
}