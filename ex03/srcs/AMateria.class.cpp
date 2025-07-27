#include "AMateria.class.hpp"

/************************************************************
*				🥚 CONSTRUCTORS & DESTRUCTOR				*
************************************************************/

AMateria::AMateria(void) : _type("default amateria")
{
	std::cout << "default constructor called for " <<  AMAT << "AMateria class" \
		<< NC << std::endl;
}

AMateria::AMateria(const std::string& type) : _type(type)
{
	std::cout << "param constructor type called for " <<  AMAT << "AMateria class" \
		<< NC << std::endl;
}

AMateria::AMateria(const AMateria &inst) : _type(inst.getType())
{
	std::cout << "copy constructor called for " <<  AMAT << "AMateria class" \
		<< NC << std::endl;
}
AMateria::~AMateria(void)
{
	std::cout << "destructor called for " <<  AMAT << "AMateria class" \
	<< NC << std::endl;
}

/************************************************************
*				➕ OPERATORS									*
************************************************************/

std::ostream& operator<<(std::ostream& os, const AMateria& o)
{
	os << AMAT << "AMateria @ address " << &o << " with type " << o.getType() << NC << std::endl;
	return os;
}

AMateria& AMateria::operator=(const AMateria& inst)
{
	if (this != &inst)
		_type = inst.getType();
	return (*this);
}

/*************************************************************
*				👁️‍ GETTERS and SETTERS						*
*************************************************************/

const std::string& AMateria::getType(void) const
{
	return (_type);
}

/*************************************************************
*				🛠️ FUNCTIONS									*
*************************************************************/

void		AMateria::use(ICharacter& target)
{
	std::cout << AMAT << "called AMateria::use for target " << target.getName() << NC << std::endl;
}