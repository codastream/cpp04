#include "Character.class.hpp"
#include "util.hpp"

/************************************************************
*				🥚 CONSTRUCTORS & DESTRUCTOR				*
************************************************************/

Character::Character (void): _name("default"), _nbMateria(0)
{
	std::cout << "default constructor called for " <<  CHAR << "Character class" \
		<< NC << std::endl;
	_initMaterias();
}

Character::Character(Character& inst): _name(inst.getName()), _nbMateria(inst._nbMateria)
{
	std::cout << "copy constructor called for " <<  CHAR << "Character class" \
		<< NC << std::endl;
	for (int i = 0; i < inst._nbMateria ; i++)
	{
		_materias[i] = inst.getMateria(i)->clone();
	}
}

Character::Character (const std::string& name): _name(name), _nbMateria(0)
{
	std::cout << "parameter name constructor called for " <<  CHAR << "Character class" \
		<< NC << std::endl;
	_initMaterias();
}

Character::~Character (void)
{
	std::cout << "destructor called for " <<  CHAR << "Character class" \
		<< NC << std::endl;
	for (int i = 0; i < MAT_NB ; i++)
	{
		if (_materias[i])
			unequip(i);
	}
}

/************************************************************
*				➕ OPERATORS									*
************************************************************/

Character& Character::operator=(const Character& inst) 
{
	for (int i = 0; i < MAT_NB; i++)
	{
		if (_materias[i])
			delete _materias[i];
		_materias[i] = inst.getMateria(i)->clone();
	}
	_nbMateria = inst._nbMateria;
	_name = inst.getName();
	return (*this);
}

std::ostream& operator<<(std::ostream& os, const Character& o)
{
	os << CHAR << "Character @ address " << &o << "with _name " << o.getName() \
	<< " and inventory: " << NC << std::endl;
	for (int i = 0; i < MAT_NB; i++)
	{
		if (o.getMateria(i))
			os << "slot#" << i << " => " << *(o.getMateria(i));
		else
			os << "slot#" << i << std::endl;
	}
	os << NC << std::endl;
	return os;
}

/*************************************************************
*				👁️‍ GETTERS and SETTERS						*
*************************************************************/

AMateria* Character::getMateria(unsigned int idx) const
{
	if ((int) idx < MAT_NB)
	{
		return (_materias[idx]);
	}
	else
		return (NULL);
}

const std::string& Character::getName() const
{
	return (this->_name);
}

/*************************************************************
*				🛠️ FUNCTIONS									*
*************************************************************/

void Character::_initMaterias(void)
{
	for (int i = 0; i < MAT_NB; i++)
	{
		_materias[i] = NULL;
	}
}

void	Character::equip(AMateria* m)
{
	for (int i = 0; i < MAT_NB; i++)
	{
		if (!_materias[i])
		{
			_materias[i] = m;
			_nbMateria++;
			return ;
		}
	}
}

void	Character::unequip(int idx)
{
	if (idx < 0 || idx >= MAT_NB || !_materias[idx])
		return ;
	_materias[idx] = NULL;
	_nbMateria--;
}

void	Character::use(int idx, ICharacter& target)
{
	if (idx < 0 || idx >= MAT_NB)
	{
		std::cerr << RED << "invalid index" << NC << std::endl;
		return;
	}
	if (!_materias[idx])
	{
		std::cerr << RED << "nothing at this index" << NC << std::endl;
		return;
	}
	_materias[idx]->use(target);
}
