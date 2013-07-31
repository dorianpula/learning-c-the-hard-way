#include <stdio.h>

int main(int argc, char *argv[]) {

	int i = 0;

	// Answer: skipping argv[0] since it'll be simply be the name of the invoking app.
	for (i = 1; i < argc; i++) {
		printf("arg %d: %s\n", i, argv[i]);
	}

	// Our own array of strings.
	char *provinces[] = {
		"Ontario", "British Columbia", "Nova Scotia", "Quebec"
	};

	return 0;
}