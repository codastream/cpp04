#include "Cat.class.hpp"
#include "Brain.class.hpp"
#include "util.hpp"

Cat::Cat(void) : Animal("Cat"), _brain(new Brain())
{
	std::cout << "default constructor called for " <<  BLUE << "Cat class" \
	<< NC << std::endl;
}

Cat::Cat(const Cat& o)
{
	std::cout << "copy constructor called for " <<  BLUE << "Cat class" \
	<< NC << std::endl;
	if (this != &o)
	{
		Animal::operator=(o);
		_brain = new Brain(*o._brain);
	}
}

Cat::~Cat(void) 
{
	std::cout << "destructor called for " <<  BLUE << "Cat class" \
	<< NC << std::endl;
	delete _brain;
}

Cat& Cat::operator=(const Cat &o)
{
	if (this != &o)
	{
		Animal::operator=(o);
		delete _brain;
		_brain = new Brain(*o._brain);
	}
	return (*this);
}

void	Cat::makeSound( void ) const
{
	putcol(BLUE, "Meow 😺");
}

Brain* 		Cat::getBrain( void )
{
	return (_brain);
}