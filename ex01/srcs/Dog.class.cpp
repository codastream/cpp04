#include "../includes/Dog.class.hpp"
#include "../includes/Brain.class.hpp"
#include "../includes/util.hpp"

Dog::Dog( void ) : Animal("Dog")
{
	std::cout << "default constructor called for " <<  BLUE << "Dog class" \
	<< NC << std::endl;
}

Dog::Dog( const Dog& o ) : Animal(o.getType())
{
	std::cout << "copy constructor called for " <<  BLUE << "Dog class" \
	<< NC << std::endl;
}

Dog::~Dog( void ) 
{
	std::cout << "destructor called for " <<  BLUE << "Dog class" \
	<< NC << std::endl;
	delete _brain;
}

Dog& Dog::operator=( const Dog &o )
{
	if (this != &o)
	{
		_type = o._type;
		_brain = o._brain;
	}
	return (*this);
}

void	Dog::makeSound( void ) const
{
	put_nl("Wouah 🐶");
}