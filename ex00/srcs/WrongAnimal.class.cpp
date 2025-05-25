#include "WrongAnimal.class.hpp"
#include "util.hpp"

WrongAnimal::WrongAnimal( void ) 
{
	std::cout << "default constructor called for " <<  BLUE << "WrongAnimal class" \
		<< NC << std::endl;
}

WrongAnimal::WrongAnimal( const std::string &type ) : _type(type)
{
	std::cout << "parameter type constructor called for " <<  BLUE << "WrongAnimal class" \
		<< NC << std::endl;
}

WrongAnimal::WrongAnimal( const WrongAnimal& o ) : _type(o.getType())
{
	std::cout << "copy constructor called for " <<  BLUE << "WrongAnimal class" \
		<< NC << std::endl;
}
WrongAnimal::~WrongAnimal( void ) 
{
	std::cout << "destructor called for " <<  BLUE << "WrongAnimal class" \
		<< NC << std::endl;
}

WrongAnimal& WrongAnimal::operator=( const WrongAnimal& o )
{
	if (this != &o)
		_type = o._type;
	return (*this);
}

const std::string WrongAnimal::getType( void ) const
{
	return (_type);
}

void	WrongAnimal::setType( const std::string &type )
{
	_type = type;
}

std::ostream &operator<<(std::ostream &os, const WrongAnimal &a)
{
	os << YELLOW << "animal at add" << &a << " [type:" << a.getType() << "]" << NC;
	return (os);
}

void	WrongAnimal::makeSound( void ) const
{
	put_nl("WrongAnimal 🐲");
}