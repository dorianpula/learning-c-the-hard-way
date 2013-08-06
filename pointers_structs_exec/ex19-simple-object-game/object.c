#include <stdio.h>
#include <string.h>
#include "object.h"
#include <assert.h>

void Object_destroy(void *self)
{
	Object *obj = self;

	if (obj) {
		if (obj->description) free(obj->description);
		free(obj);
	}
}

void Object_describe(void *self)
{
	Object *obj = self;
	printf("%s.\n", obj->description);
}

int Object_init(void *self)
{
	// do nothing
	return 1;
}

void *Object_move(void *self, Direction direction)
{
	// A default implementation of a moving an object.
	printf("You can't go that direction. \n");
	return 0;
}

int Object_attack(void *self, int damage)
{
	// Again a default implementation.
	printf("You can't attack that. \n");
	return 0;
}

void *Object_new(size_t size, Object proto, char *description)
{
	// TODO Complete me.
}