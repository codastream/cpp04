#include "../includes/Cat.class.hpp"
#include "../includes/Brain.class.hpp"
#include "../includes/util.hpp"

Cat::Cat( void ) : Animal("Cat")
{
	std::cout << "default constructor called for " <<  BLUE << "Cat class" \
	<< NC << std::endl;
	_brain = new Brain();
}

Cat::Cat( const Cat& o ) : Animal(o.getType()), _brain(o._brain)
{
	std::cout << "copy constructor called for " <<  BLUE << "Cat class" \
	<< NC << std::endl;
}

Cat::~Cat( void ) 
{
	std::cout << "destructor called for " <<  BLUE << "Cat class" \
	<< NC << std::endl;
	delete _brain;
}

Cat& Cat::operator=( const Cat &o )
{
	if (this != &o)
	{
		_type = o._type;
		_brain = o._brain;
	}
	return (*this);
}

void	Cat::makeSound( void ) const
{
	put_nl("Meow 😺");
}