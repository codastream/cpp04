#include "Cure.class.hpp"
#include "util.hpp"

Cure::Cure(void)
{
	std::cout << "default constructor called for " <<  BLUE << "Cure class" \
		<< NC << std::endl;
	_type = "ice";
}

Cure::Cure(const Cure& inst)
{
	std::cout << "copy constructor called for " <<  BLUE << "Cure class" \
		<< NC << std::endl;
	this->_type = inst.getType();
}

Cure::Cure(const std::string& type)
{
	std::cout << "param type constructor called for " <<  BLUE << "Cure class" \
		<< NC << std::endl;
	this->_type = type;
}

Cure::~Cure(void)
{
	std::cout << "destructor called for " <<  BLUE << "Cure class" \
		<< NC << std::endl;
}

Cure& Cure::operator=(const Cure& inst)
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
	Cure	*newinst;
	newinst = new Cure();
	return (newinst);
}

void	AMateria::use(ICharacter& target)
{
	std::cout << "* heals " << target.getName() << "'s wounds *" << std::endl;
}