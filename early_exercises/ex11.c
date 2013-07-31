#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[]) {

	// Lets look at each string in argv.
	int i = 0;
	while(i < argc) {
		printf("arg %d: %s\n", i, argv[i]);
		i++;
	}

	// Again with our own array.
	char *transit_means[] = {
		"car", "bus", "train", "plane", "rocket"
	};

	int num_transit_means = 5;
	i = 0; // Reset our universal incrementer. :P
	while(i < num_transit_means) {
		printf("transport %d: %s\n", i, transit_means[i]);
		i++;
	}

	// Lets be fancy here with macro from stdlib.h!
	return EXIT_SUCCESS;
}