#include <stdlib.h>
#include "dog.h"

/**
  * init_dog - a function to initialize a dog structure
  * @d: A dog structure.
  * @name: The name of the dog.
  * @age: The age of the dog.
  * @owner: The owner of the dog.
  *
  * Return: Nothing
  */

void init_dog(struct dog *d, char *name, float age, char *owner)
{
	int i;
	int name_length = 0;
	int owner_length = 0;

	while (name[name_length] != '\0')
		name_length++;
	while (owner[owner_length] != '\0')
		owner_length++;

	d->name = (char *)malloc((name_length + 1) * sizeof(char));
	d->owner = (char *)malloc((owner_length + 1) * sizeof(char));

	for (i = 0; i <= name_length; i++)
		d->name[i] = name[i];

	for (i = 0; i <= owner_length; i++)
		d->owner[i] = owner[i];

	d->age = age;
}
