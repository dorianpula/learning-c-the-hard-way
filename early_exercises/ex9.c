int main(int argc, char *argv[]) {

    int numbers[4] = {0};
    char name[4] = {'a'};

    // First print them out raw
    printf("numbers: %d %d %d %d\n", numbers[0], numbers[1], numbers[2], numbers[3]);
    printf("name: %c %c %c %c\n", name[0], name[1], name[2], name[3]);

    printf("name: %s\n", name);

    // Setup numbers
    int i = 0;
    for(i = 0; i < 4; i++) {
	numbers[i] = i + 1;
    }

    // Setup name
    name[0] = 'Z';
    name[1] = 'e';
    name[2] = 'd';
    name[3] = '\0';

    // Print the initialized variables again...
    printf("numbers: %d %d %d %d\n", numbers[0], numbers[1], numbers[2], numbers[3]);
    printf("names: %c %c %c %c\n", name[0], name[1], name[2], name[3]);

    printf("name: %s\n", name);

    // another way to create a string
    char *another = "Dorian";
    printf("another: %s\n", another);
    printf("another each: %c %c %c %c %c %c %c\n",
	    another[0], another[1], another[2], another[3], another[4], another[5],
	    another[6], another[7]);
	    
    return 0;
}
