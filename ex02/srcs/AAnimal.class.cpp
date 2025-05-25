#include "../includes/AAnimal.class.hpp"
#include "util.hpp"

AAnimal::AAnimal( void ) 
{
	std::cout << "default constructor called for " <<  BLUE << "AAnimal class" \
		<< NC << std::endl;
}

AAnimal::AAnimal( const std::string &type ) : _type(type)
{
	std::cout << "parameter type constructor called for " <<  BLUE << "AAnimal class" \
		<< NC << std::endl;
}


AAnimal::AAnimal( const AAnimal& o ) : _type(o.getType())
{
	std::cout << "copy constructor called for " <<  BLUE << "AAnimal class" \
		<< NC << std::endl;
}
AAnimal::~AAnimal( void ) 
{
	std::cout << "destructor called for " <<  BLUE << "AAnimal class" \
		<< NC << std::endl;
}

AAnimal& AAnimal::operator=( const AAnimal& o )
{
	if (this != &o)
		_type = o._type;
	return (*this);
}

const std::string AAnimal::getType( void ) const
{
	return (_type);
}

void	AAnimal::setType( const std::string &type )
{
	_type = type;
}

std::ostream &operator<<(std::ostream &os, const AAnimal &a)
{
	os << YELLOW << "animal at add" << &a << " [type:" << a.getType() << "]" << NC;
	return (os);
}

void	AAnimal::makeSound( void ) const
{
	put_nl("Animal 🦄");
}