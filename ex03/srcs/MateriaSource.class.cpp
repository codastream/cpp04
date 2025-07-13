#include "MateriaSource.class.hpp"
#include "Ice.class.hpp"
#include "Cure.class.hpp"
#include "util.hpp"

MateriaSource::MateriaSource(void)
{
	std::cout << "default constructor called for " <<  BLUE << "MateriaSource class" \
		<< NC << std::endl;
	for (int i = 0; i < MAT_NB_SRC; i++)
	{
		this->_materias[i] = NULL;
	}
}

MateriaSource::~MateriaSource(void)
{
	std::cout << "destructor called for " <<  BLUE << "MateriaSource class" \
		<< NC << std::endl;
	for (int i = 0; i < MAT_NB_SRC; i++)
	{
		delete this->_materias[i];
	}
}

MateriaSource::MateriaSource(MateriaSource& inst)
{
	for (int i = 0; i < MAT_NB_SRC; i++)
	{
		this->_materias[i] = this->createMateria(inst._materias[i]->getType());
	}
}

MateriaSource& MateriaSource::operator=(MateriaSource& inst)
{
	for (int i = 0; i < MAT_NB_SRC; i++)
	{
		delete this->_materias[i];
		this->_materias[i] = this->createMateria(inst._materias[i]->getType());
	}
	return (*this);
}

void	MateriaSource::learnMateria(AMateria* param)
{
	for (int i = 0; i < MAT_NB_SRC; i++)
	{
		if (this->_materias[i] == NULL)
		{
			this->_materias[i] = this->createMateria(param->getType());
			return ;
		}
	}
	std::cout << RED << "no space left for Materia" << NC << std::endl;
}

AMateria*	MateriaSource::createMateria(const std::string& type)
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