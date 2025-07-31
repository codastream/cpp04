#include "WrongAnimal.class.hpp"
#include "util.hpp"

/************************************************************
 *				🥚 CONSTRUCTORS & DESTRUCTOR				*
 ************************************************************/

WrongAnimal::WrongAnimal(void) 
{
	std::cout << "default constructor called for " <<  RED << "WrongAnimal class" \
		<< NC << std::endl;
}

WrongAnimal::WrongAnimal(const std::string& type) : _type(type)
{
	std::cout << "parameter type constructor called for " <<  RED << "WrongAnimal class" \
		<< NC << std::endl;
}

WrongAnimal::WrongAnimal(const WrongAnimal& o)
{
	std::cout << "copy constructor called for " <<  RED << "WrongAnimal class" \
		<< NC << std::endl;
	*this = o;
}
WrongAnimal::~WrongAnimal(void) 
{
	std::cout << "destructor called for " <<  RED << "WrongAnimal class" \
		<< NC << std::endl;
}

/************************************************************
 *				➕ OPERATORS									*
 ************************************************************/

WrongAnimal& WrongAnimal::operator=(const WrongAnimal& o)
{
	if (this != &o)
		_type = o._type;
	return (*this);
}

std::ostream &operator<<(std::ostream& os, const WrongAnimal& a)
{
	os << RED << "animal at address " << &a << " [type:" << a.getType() << "]" << NC;
	return (os);
}

/*************************************************************
*				👁️‍ GETTERS and SETTERS						*
*************************************************************/


const std::string WrongAnimal::getType(void) const
{
	return (_type);
}

void	WrongAnimal::setType(const std::string& type)
{
	_type = type;
}



void	WrongAnimal::makeSound(void) const
{
	putcol(RED, "WrongAnimal 🐲");
}