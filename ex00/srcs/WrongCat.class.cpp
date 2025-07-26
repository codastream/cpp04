#include "WrongCat.class.hpp"
#include "util.hpp"

WrongCat::WrongCat(void) : WrongAnimal("WrongCat")
{
	// _type = "WrongCat";
	std::cout << "default constructor called for " <<  MAGENTA << "WrongCat class" \
	<< NC << std::endl;
}

WrongCat::WrongCat(const WrongCat& o) : WrongAnimal(o)
{
	std::cout << "copy constructor called for " <<  MAGENTA << "WrongCat class" \
	<< NC << std::endl;
}

WrongCat::~WrongCat(void) 
{
	std::cout << "destructor called for " <<  MAGENTA << "WrongCat class" \
	<< NC << std::endl;
}

WrongCat& WrongCat::operator=(const WrongCat& o)
{
	if (this != &o)
	{
		WrongAnimal::operator=(o);
	}
	return (*this);
}
