#include <stdio.h>

int main(int argc, char *argv[]) {

	int i = 0;

	// Answer: skipping argv[0] since it'll be simply be the name of the 
	// invoking app.
	for (i = 1; i < argc; i++) {
		printf("arg %d: %s\n", i, argv[i]);
	}

	// Our own array of strings.
	char *provinces[] = {
		"Ontario", "British Columbia", "Nova Scotia", "Quebec"
	};
	int num_provinces = 4;

	// Note: the madness is that an array out-of-bounds or printing a NULL
	// is all fine and well.
	for (i = 0; i < num_provinces; i++) {
		printf("province %d: %s\n", i, provinces[i]);
	}

	return 0;
}