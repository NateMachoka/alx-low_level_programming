#include <stdio.h>
#include <stdlib.h>
#include "dog.h"

/**
  * print_dog - Prints all the info of a dog
  * @d: A dog structure
  *
  * Return: Nothing
  */

void print_dog(struct dog *d)
{
	if (d == NULL)
	{
		return;
	}

	printf("Name: %s\n", (d->name) != NULL ? d->name : "(nil)");
	printf("Age: %.1f\n", (d->age) ? d->age : 0);
	printf("Owner: %s\n", (d->owner) != NULL ? d->owner : "(nil)");
}
