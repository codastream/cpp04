#include "AMateria.class.hpp"
#include "util.hpp"

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
	std::cout << "use called for " <<  BLUE << "AMateria class" \
	<< NC << std::endl;
}