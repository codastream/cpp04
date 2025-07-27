#include "MateriaSource.class.hpp"
#include "Ice.class.hpp"
#include "Cure.class.hpp"
#include "util.hpp"

/************************************************************
*				🥚 CONSTRUCTORS & DESTRUCTOR				*
************************************************************/

MateriaSource::MateriaSource(void)
{
	std::cout << "default constructor called for " <<  MATS << "MateriaSource class" \
		<< NC << std::endl;
	for (int i = 0; i < MAT_NB_SRC; i++)
	{
		_materias[i] = NULL;
	}
}

MateriaSource::MateriaSource(MateriaSource& inst)
{
	std::cout << "copy constructor called for " <<  MATS << "MateriaSource class" \
		<< NC << std::endl;
	for (int i = 0; i < MAT_NB_SRC; i++)
	{
		_materias[i] = this->createMateria(inst._materias[i]->getType());
	}
}

MateriaSource::~MateriaSource(void)
{
	std::cout << "destructor called for " <<  MATS << "MateriaSource class" \
		<< NC << std::endl;
	for (int i = 0; i < MAT_NB_SRC; i++)
	{
		delete _materias[i];
	}
}

/************************************************************
*				➕ OPERATORS									*
************************************************************/

MateriaSource& MateriaSource::operator=(MateriaSource& inst)
{
	for (int i = 0; i < MAT_NB_SRC; i++)
	{
		delete _materias[i];
		_materias[i] = this->createMateria(inst._materias[i]->getType());
	}
	return (*this);
}

/*************************************************************
*				🛠️ FUNCTIONS									*
*************************************************************/

void	MateriaSource::learnMateria(AMateria* param)
{
	for (int i = 0; i < MAT_NB_SRC; i++)
	{
		if (_materias[i] == NULL)
		{
			_materias[i] = param;
			return ;
		}
	}
	std::cerr << RED << "no space left for learning materia" << NC << std::endl;
}

AMateria*	MateriaSource::createMateria(const std::string& type)
{
	AMateria* ret = 0;

	for (int i = 0; i < MAT_NB_SRC; i++)
	{
		if (_materias[i] && type == _materias[i]->getType())
		{
			ret = _materias[i]->clone();
			break ;
		}
	}
	if (ret == 0)
		std::cerr << RED << "unknown type" << NC << std::endl;
	return (ret);
}