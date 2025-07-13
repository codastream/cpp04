#include "Cure.class.hpp"
#include "util.hpp"

// necessaire d appeler le const du parent ?
Cure::Cure(void): AMateria()
{
	std::cout << "default constructor called for " <<  BLUE << "Cure class" \
		<< NC << std::endl;
	_type = "ice";
}

Cure::Cure(const Cure& inst): AMateria(inst)
{
	std::cout << "copy constructor called for " <<  BLUE << "Cure class" \
		<< NC << std::endl;
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
	Cure	*copied;

	if (this == &inst)
		return (*this);
	else
	{
		copied = new Cure(inst);
		return (*copied);
	}
}

AMateria*	Cure::clone(void) const
{
	Cure	*newinst;
	newinst = new Cure(*this);
	return (newinst);
}
