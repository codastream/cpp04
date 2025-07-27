#include "Ice.class.hpp"
#include "util.hpp"

/************************************************************
*				🥚 CONSTRUCTORS & DESTRUCTOR				*
************************************************************/

Ice::Ice(void): AMateria("ice")
{
	std::cout << "default constructor called for " <<  BLUE << "Ice class" \
		<< NC << std::endl;
}

Ice::Ice(const Ice& inst) : AMateria(inst)
{
	std::cout << "copy constructor called for " <<  BLUE << "Ice class" \
		<< NC << std::endl;
}

Ice::~Ice(void)
{
	std::cout << "destructor called for " <<  BLUE << "Ice class" \
		<< NC << std::endl;
}

/************************************************************
*				➕ OPERATORS									*
************************************************************/

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

/*************************************************************
*				🛠️ FUNCTIONS									*
*************************************************************/

AMateria* Ice::clone(void) const
{
	Ice		*newinst;
	newinst = new Ice(*this);
	return (newinst);
}

void	Ice::use(ICharacter& target)
{
	std::cout << BLUE << "* shoots an ice bolt at " << target.getName() << std::endl;
}