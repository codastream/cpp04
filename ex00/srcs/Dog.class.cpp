#include "Dog.class.hpp"
#include "util.hpp"

Dog::Dog(void) : Animal("Dog")
{
	std::cout << "default constructor called for " <<  BLUE << "Dog class" \
	<< NC << std::endl;
}

Dog::Dog(const Dog& o) : Animal(o)
{
	std::cout << "copy constructor called for " <<  BLUE << "Dog class" \
	<< NC << std::endl;
}

Dog::~Dog(void) 
{
	std::cout << "destructor called for " <<  BLUE << "Dog class" \
	<< NC << std::endl;
}

Dog& Dog::operator=(const Dog &o)
{
	if (this != &o)
		_type = o._type;
	return (*this);
}

void	Dog::makeSound(void) const
{
	put_nl("Wouah 🐶");
}