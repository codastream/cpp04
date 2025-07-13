#include "Ice.class.hpp"
#include "util.hpp"

Ice::Ice(void): AMateria()
{
	std::cout << "default constructor called for " <<  BLUE << "Ice class" \
		<< NC << std::endl;
	_type = "ice";
}

Ice::Ice(const Ice& inst) : AMateria(inst)
{
	std::cout << "copy constructor called for " <<  BLUE << "Ice class" \
		<< NC << std::endl;
	this->_type = inst.getType();
}

Ice::Ice(const std::string& type)
{
	std::cout << "param type constructor called for " <<  BLUE << "Ice class" \
		<< NC << std::endl;
	this->_type = type;
}

Ice::~Ice(void)
{
	std::cout << "destructor called for " <<  BLUE << "Ice class" \
		<< NC << std::endl;
}

Ice& Ice::operator=(const Ice& inst)
{
	Ice	*copied;
	if (this == &inst)
		return (*this);
	else
	{
		copied = new Ice(inst);
		return (*copied);
	}
}

AMateria* Ice::clone(void) const
{
	Ice		*newinst;
	newinst = new Ice(*this);
	return (newinst);
}
