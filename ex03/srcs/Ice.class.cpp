#include "Ice.class.hpp"
#include "util.hpp"

Ice::Ice(void)
{
	std::cout << "default constructor called for " <<  BLUE << "Ice class" \
		<< NC << std::endl;
	_type = "ice";
}

Ice::Ice(const Ice& inst)
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
	if (this != &inst)
	{
	}
}

const std::string& AMateria::getType(void) const{
	return (_type);
}

AMateria*	AMateria::clone(void) const
{
	Ice	*newinst;
	newinst = new Ice();
	return (newinst);
}

void	AMateria::use(ICharacter& target)
{
	std::cout << "* shoots an ice bolt at " << target.getName() << std::endl;
}