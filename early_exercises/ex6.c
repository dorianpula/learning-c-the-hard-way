#include <stdio.h>

int main(int argc, char *argv[]) {
	
	int distance = 100;
	float pi = 3.1415f;
	double super_power = 56789.4532;

	char initial = 'A';
	char first_name[] = "Dorian";
	char last_name[] = "Pula";
	
	char emptiness[] = "";

	printf("You are %d kms away. \n", distance);
 	printf("PI is about %f.\n", pi);
	printf("Here is a double... %f. \n", super_power);

	printf("My name is %s %c. %s. \n", first_name, initial, last_name); 	

	printf("I'm an empty string: %s. \n", emptiness);

	return 0;	
	
}
