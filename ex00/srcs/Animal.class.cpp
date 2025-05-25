#include "Animal.class.hpp"
#include "util.hpp"

Animal::Animal( void ) 
{
	std::cout << "default constructor called for " <<  BLUE << "Animal class" \
		<< NC << std::endl;
}

Animal::Animal( const std::string &type ) : _type(type)
{
	std::cout << "parameter type constructor called for " <<  BLUE << "Animal class" \
		<< NC << std::endl;
}


Animal::Animal( const Animal& o ) : _type(o.getType())
{
	std::cout << "copy constructor called for " <<  BLUE << "Animal class" \
		<< NC << std::endl;
}
Animal::~Animal( void ) 
{
	std::cout << "destructor called for " <<  BLUE << "Animal class" \
		<< NC << std::endl;
}

Animal& Animal::operator=( const Animal& o )
{
	if (this != &o)
		_type = o._type;
	return (*this);
}

const std::string Animal::getType( void ) const
{
	return (_type);
}

void	Animal::setType( const std::string &type )
{
	_type = type;
}

std::ostream &operator<<(std::ostream &os, const Animal &a)
{
	os << YELLOW << "animal at add" << &a << " [type:" << a.getType() << "]" << NC;
	return (os);
}

void	Animal::makeSound( void ) const
{
	put_nl("Animal 🦄");
}