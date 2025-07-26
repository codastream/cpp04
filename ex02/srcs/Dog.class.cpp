#include "Dog.class.hpp"
#include "util.hpp"

Dog::Dog(void) : _brain(new Brain())
{
	std::cout << "default constructor called for " <<  GREEN << "Dog class" \
	<< NC << std::endl;
}

Dog::Dog(const Dog& o)
{
	std::cout << "copy constructor called for " <<  GREEN << "Dog class" \
	<< NC << std::endl;
	if (this != &o)
	{
		AAnimal::operator=(o);
		_brain = new Brain(*o._brain);
	}
}

Dog::~Dog(void) 
{
	std::cout << "destructor called for " <<  GREEN << "Dog class" \
	<< NC << std::endl;
	delete _brain;
}

Dog& Dog::operator=(const Dog &o)
{
	if (this != &o)
	{
		AAnimal::operator=(o);
		delete _brain;
		_brain = new Brain(*o._brain);
	}
	return (*this);
}

void	Dog::makeSound(void) const
{
	putcol(GREEN, "Wah 🐶");
}

Brain* 		Dog::getBrain( void )
{
	return (_brain);
}