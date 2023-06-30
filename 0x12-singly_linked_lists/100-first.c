#include <stdio.h>
#include "lists.h"

void printStatement(void) __attribute__ ((constructor));
/**
  * printStatement - prints statements before main function is printed
  *
  * Return: Nothing.
  */

void printStatement(void)
{
	printf("You're beat! and yet, you must allow,\n");
	printf("I bore my house upon my back!\n");
}
