#include "Animal.class.hpp"
#include "util.hpp"

/************************************************************
 *				🥚 CONSTRUCTORS & DESTRUCTOR				*
 ************************************************************/

Animal::Animal(void) 
{
	std::cout << "default constructor called for " << ORANGE << "Animal class" \
		<< NC << std::endl;
}

Animal::Animal(const std::string& type) : _type(type)
{
	std::cout << "parameter type constructor called for " <<  ORANGE << "Animal class" \
		<< NC << std::endl;
}

Animal::Animal(const Animal& o) : _type(o.getType())
{
	std::cout << "copy constructor called for " <<  ORANGE << "Animal class" \
		<< NC << std::endl;
}
Animal::~Animal(void) 
{
	std::cout << "destructor called for " <<  ORANGE << "Animal class" \
		<< NC << std::endl;
}

/************************************************************
 *				➕ OPERATORS									*
 ************************************************************/

Animal& Animal::operator=(const Animal& inst)
{
	if (this != &inst)
		_type = inst._type;
	return (*this);
}

std::ostream &operator<<(std::ostream& os, const Animal& a)
{
	os << YELLOW << "animal at add" << &a << " [type:" << a.getType() << "]" << NC;
	return (os);
}

/*************************************************************
 *				👁️‍ GETTERS and SETTERS						*
 *************************************************************/

const std::string Animal::getType(void) const
{
	return (_type);
}

void	Animal::setType(const std::string& type)
{
	_type = type;
}

/*************************************************************
 *				🛠️ FUNCTIONS									*
 *************************************************************/

void	Animal::makeSound(void) const
{
	put_nl("Animal 🦄");
}
