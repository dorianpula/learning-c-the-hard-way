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
	// Setup the default functions in case they are not set...
	if(!proto.init) proto.init = Object_init;
	if(!proto.describe) proto.describe = Object_describe;
	if(!proto.destroy) proto.destroy = Object_destroy;
	if(!proto.attack) proto.attack = Object_attack;
	if(!proto.move) proto.move = Object_move;

	// Seems weird to make a struct of one size, then point a different pointer
	// at it to "cast" it.
	Object *el = calloc(1, size);
	*el = proto;

	// Copy the description
	el->description = strdup(description);

	// Initialize this to whatever init we were given.
	if (!el->init(el)) {
		// Crap not properly init'ed.
		el->destroy(el);
		return NULL;
	} else {
		// Done.  We make an object of any type.
		return el;
	}
}