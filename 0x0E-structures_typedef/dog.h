#ifndef _HEADER_
#define _HEADER_

/**
 * struct dog - attributes of dog
 * @name: dog's name
 * @age: dog's age
 * @owner: dog's owner
 * Description: attributes of the dog
 */

struct dog
{
	char *name;
	float age;
	char *owner;
};

/**
 * dog_t - Typedef for dog structure
 */
typedef struct dog dog_t;

void init_dog(struct dog *d, char *name, float age, char *owner);
void print_dog(struct dog *d);


#endif
