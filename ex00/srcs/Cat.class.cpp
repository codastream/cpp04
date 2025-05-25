#include "Cat.class.hpp"
#include "util.hpp"

Cat::Cat( void ) : Animal("Cat")
{
	// _type = "Cat";
	std::cout << "default constructor called for " <<  BLUE << "Cat class" \
	<< NC << std::endl;
}

Cat::Cat( const Cat& o ) : Animal(o.getType())
{
	std::cout << "copy constructor called for " <<  BLUE << "Cat class" \
	<< NC << std::endl;
}

Cat::~Cat( void ) 
{
	std::cout << "destructor called for " <<  BLUE << "Cat class" \
	<< NC << std::endl;
}

Cat& Cat::operator=( const Cat &o )
{
	if (this != &o)
		_type = o._type;
	return (*this);
}

void	Cat::makeSound( void ) const
{
	put_nl("Meow 😺");
}