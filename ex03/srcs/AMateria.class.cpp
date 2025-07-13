#include "AMateria.class.hpp"

AMateria::AMateria( void )
{
	std::cout << "default constructor called for " <<  BLUE << "AMateria class" \
		<< NC << std::endl;
}

AMateria::AMateria(const AMateria &inst) : _type(inst.getType())
{
	std::cout << "copy constructor called for " <<  BLUE << "AMateria class" \
		<< NC << std::endl;
}
AMateria::~AMateria(void)
{
	std::cout << "destructor called for " <<  BLUE << "AMateria class" \
	<< NC << std::endl;
}

AMateria& AMateria::operator=(const AMateria& inst)
{
	if (this != &inst)
		_type = inst.getType();
	return (*this);
}

const std::string& AMateria::getType(void) const
{
	return (_type);
}

void AMateria::use(ICharacter& target)
{
	if (!_type.compare("ice"))
		std::cout << "* shoots an ice bolt at " << target.getName() << std::endl;
	else if (!_type.compare("cure"))
		std::cout << "* heals " << target.getName() << "'s wounds *" << std::endl;
}