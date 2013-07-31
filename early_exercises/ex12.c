#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[]) {

	int i = 0;

	if (argc == 1) {
		printf("You only have one argument. Not cool bro. \n");
	} else if (argc > 1 && argc < 4) {
		printf("Here are your arguments:\n");

		for (i = 0; i < argc; i++) {
			printf("%s ", argv[i]);
		}

		printf("\n");
	} else {
		printf("You have too many arguments. Dude, use less next time.\n");
	}

	return EXIT_SUCCESS;
}