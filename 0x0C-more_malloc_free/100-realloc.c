#include <stdlib.h>

/**
 * _realloc - reallocates a memory block using malloc and free
 * @ptr: a pointer to the memory previously allocated with a call to malloc
 * @old_size:  size, in bytes, of the allocated space for ptr
 * @new_size: size, in bytes of the new memory block
 * Return: ...
 */

void *_realloc(void *ptr, unsigned int old_size, unsigned int new_size)
{
	void *new_ptr;
	unsigned int i, copy_size;
	char *old_ptr;
	char *new_ptr_char;

	if (ptr == NULL)
	{
		return (malloc(new_size));
	}
	if (new_size == 0)
	{
		free(ptr);
		return (NULL);
	}

	if (new_size == old_size)
	{
		return (ptr);
	}

	new_ptr = malloc(new_size);

	if (new_ptr == NULL)
	{
		return (NULL);
	}

	old_ptr = (char *)ptr;
	new_ptr_char = (char *)new_ptr;
	copy_size = old_size < new_size ? old_size : new_size;

	for (i = 0; i < copy_size; i++)
	{
		new_ptr_char[i] = old_ptr[i];
	}

	free(ptr);

	return (new_ptr);
}
