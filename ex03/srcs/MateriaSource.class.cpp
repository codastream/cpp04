#include "MateriaSource.class.hpp"
#include "Ice.class.hpp"
#include "Cure.class.hpp"
#include "util.hpp"

/************************************************************
*				🥚 CONSTRUCTORS & DESTRUCTOR				*
************************************************************/

MateriaSource::MateriaSource(void) : _nbMateria(0)
{
	std::cout << "default constructor called for " <<  MATS << "MateriaSource class" \
		<< NC << std::endl;
}

MateriaSource::MateriaSource(MateriaSource& inst) : _nbMateria(inst._nbMateria)
{
	std::cout << "copy constructor called for " <<  MATS << "MateriaSource class" \
		<< NC << std::endl;
	for (int i = 0; i < inst._nbMateria; i++)
	{
		_materias[i] = inst._materias[i]->clone();
	}
}

MateriaSource::~MateriaSource(void)
{
	std::cout << "destructor called for " <<  MATS << "MateriaSource class" \
		<< NC << std::endl;
	for (int i = 0; i < _nbMateria; i++)
	{
		delete _materias[i];
	}
}

/************************************************************
*				➕ OPERATORS									*
************************************************************/

MateriaSource& MateriaSource::operator=(MateriaSource& inst)
{
	for (int i = 0; i < inst._nbMateria; i++)
	{
		delete _materias[i];
		_materias[i] = inst._materias[i]->clone();
		_nbMateria++;
	}
	return (*this);
}

std::ostream& operator<<(std::ostream& os, const MateriaSource& o)
{
	os << MATS << "Materia Source @ address " << &o << " with " << o.getNbMateria() << " materias : " << NC << std::endl;
	for (int i = 0; i < o.getNbMateria() ; i++)
	{
		os << "*" << (*o.getMateria(i));
	}
	return os;
}

/*************************************************************
*				👁️‍ GETTERS and SETTERS						*
*************************************************************/

AMateria* MateriaSource::getMateria(unsigned int idx) const
{
	if ((int) idx < _nbMateria)
	{
		return _materias[idx];
	}
	return (NULL);
}

int			MateriaSource::getNbMateria(void) const
{
	return _nbMateria;
}

/*************************************************************
*				🛠️ FUNCTIONS									*
*************************************************************/

void	MateriaSource::learnMateria(AMateria* param)
{
	if (_nbMateria < MAT_NB_SRC)
	{
		_materias[_nbMateria] = param->clone();
		_nbMateria++;
	}
	else
		std::cerr << RED << "no space left for learning materia" << NC << std::endl;
}

AMateria*	MateriaSource::createMateria(const std::string& type)
{
	AMateria* ret = 0;

	for (int i = 0; i < _nbMateria; i++)
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