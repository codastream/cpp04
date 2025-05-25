#include "Animal.class.hpp"
#include "Dog.class.hpp"
#include "Cat.class.hpp"
#include "util.hpp"

int main( void )
{
	int	n = 10;
	Animal *animals[n];

	for (int i = 0; i < n; i++)
	{
		if (i < (n / 2))
			animals[i] = new Dog();
		else
			animals[i] = new Cat();
	}
	std::cout << *animals[6] << std::endl;
	static_cast<Cat *>(animals[6])->getBrain()->setIdea(1, "good idea");
	std::cout << static_cast<Cat *>(animals[6])->getBrain()->getIdeaByIndex(3) << std::endl;
	for (int i = 0; i < n; i++)
	{
		delete animals[i];
	}
}