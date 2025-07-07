#include "../includes/AAnimal.class.hpp"
#include "Dog.class.hpp"
#include "Cat.class.hpp"
#include "util.hpp"

int main( void )
{
	int	n = 10;
	AAnimal *animals[n];

	// Can't instanciate
	// AAnimal *a = new Animal();

	for (int i = 0; i < n; i++)
	{
		if (i & 0b1)
			animals[i] = new Dog();
		else
			animals[i] = new Cat();
	}
	dynamic_cast<Cat *>(animals[6])->getBrain()->setIdea(1, "good idea");
	std::cout << dynamic_cast<Cat *>(animals[6])->getBrain()->getIdeaByIndex(3) << std::endl;
	for (int i = 0; i < n; i++)
	{
		delete animals[i];
	}
}