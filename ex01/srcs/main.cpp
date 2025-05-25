#include "Animal.class.hpp"
#include "Dog.class.hpp"
#include "Cat.class.hpp"

int main( void )
{
	Animal *animals;

	for (int i = 0; i < 100; i++)
	{
		if (i < 50)
			animals[i] = new Dog();
		else
			animals[i] = new Cat();
	}
}