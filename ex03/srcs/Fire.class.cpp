#include "Fire.class.hpp"
#include "util.hpp"

/************************************************************
*				🥚 CONSTRUCTORS & DESTRUCTOR				*
************************************************************/

Fire::Fire(void): AMateria("fire")
{
	std::cout << "default constructor called for " <<  ORANGE << "Fire class" \
		<< NC << std::endl;
}

Fire::Fire(const Fire& inst): AMateria(inst)
{
	std::cout << "copy constructor called for " <<  ORANGE << "Fire class" \
		<< NC << std::endl;
}

Fire::~Fire(void)
{
	std::cout << "destructor called for " <<  ORANGE << "Fire class" \
		<< NC << std::endl;
}

/************************************************************
*				➕ OPERATORS									*
************************************************************/

Fire& Fire::operator=(const Fire& inst)
{
	Fire	*copied;

	if (this == &inst)
		return (*this);
	else
	{
		copied = new Fire(inst);
		return (*copied);
	}
}

/*************************************************************
*				🛠️ FUNCTIONS									*
*************************************************************/

AMateria*	Fire::clone(void) const
{
	Fire	*newinst;
	newinst = new Fire(*this);
	return (newinst);
}

void		Fire::use(ICharacter& target)
{
		std::cout << ORANGE << "* shoots a fireball at " << target.getName() << " *" << std::endl;
}
