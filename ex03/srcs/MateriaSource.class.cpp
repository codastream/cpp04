#include "MateriaSource.class.hpp"
#include "Ice.class.hpp"
#include "Cure.class.hpp"

MateriaSource::MateriaSource(void){}
MateriaSource::~MateriaSource(void){}
MateriaSource::MateriaSource(MateriaSource& inst)
{}
MateriaSource& MateriaSource::operator=(MateriaSource& inst){}


void	IMateriaSource::learnMateria(AMateria* param)
{
	AMateria *mat = param;
}

AMateria*	IMateriaSource::createMateria(const std::string& type)
{
	AMateria* ret;

	if (type == "ice")
		ret = new Ice("ice");
	else if (type == "cure")
		ret = new Cure("cure");
	else
	{
		std::cout << "unknown type" << std::endl;
	}
	return (ret);
}