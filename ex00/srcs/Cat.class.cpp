#include "Cat.class.hpp"
#include "util.hpp"

Cat::Cat(void) : Animal("Cat")
{
	std::cout << "default constructor called for " <<  BLUE << "Cat class" \
	<< NC << std::endl;
}

Cat::Cat(const Cat& o) : Animal(o)
{
	std::cout << "copy constructor called for " <<  BLUE << "Cat class" \
	<< NC << std::endl;
}

Cat::~Cat(void) 
{
	std::cout << "destructor called for " <<  BLUE << "Cat class" \
	<< NC << std::endl;
}

Cat& Cat::operator=(const Cat& o)
{
	if (this != &o)
	{
		Animal::operator=(o);
	}
	return (*this);
}

void	Cat::makeSound(void) const
{
	putcol(BLUE, "Meow 😺");
}