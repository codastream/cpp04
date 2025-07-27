#include "Cure.class.hpp"
#include "util.hpp"

/************************************************************
*				🥚 CONSTRUCTORS & DESTRUCTOR				*
************************************************************/

Cure::Cure(void): AMateria("cure")
{
	std::cout << "default constructor called for " <<  GREEN << "Cure class" \
		<< NC << std::endl;
}

Cure::Cure(const Cure& inst): AMateria(inst)
{
	std::cout << "copy constructor called for " <<  GREEN << "Cure class" \
		<< NC << std::endl;
}

Cure::~Cure(void)
{
	std::cout << "destructor called for " <<  GREEN << "Cure class" \
		<< NC << std::endl;
}

/************************************************************
*				➕ OPERATORS									*
************************************************************/

Cure& Cure::operator=(const Cure& inst)
{
	Cure	*copied;

	if (this == &inst)
		return (*this);
	else
	{
		copied = new Cure(inst);
		return (*copied);
	}
}

/*************************************************************
*				🛠️ FUNCTIONS									*
*************************************************************/

AMateria*	Cure::clone(void) const
{
	Cure	*newinst;
	newinst = new Cure(*this);
	return (newinst);
}

void		Cure::use(ICharacter& target)
{
		std::cout << GREEN << "* heals " << target.getName() << "'s wounds *" << std::endl;
}
