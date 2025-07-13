#include "Character.class.hpp"
#include "util.hpp"

void Character::initMaterias(void)
{
	for (int i = 0; i < MAT_NB; i++)
	{
		this->_materias[i] = NULL;
	}
}

Character::Character (void): _name("default")
{
	std::cout << "default constructor called for " <<  BLUE << "Character class" \
		<< NC << std::endl;
	initMaterias();
}

Character::Character(Character& inst): _name(inst.getName())
{
	std::cout << "copyconstructor called for " <<  BLUE << "Character class" \
		<< NC << std::endl;
	for (int i = 0; i < MAT_NB; i++)
	{
		this->_materias[i] = inst.getMateria(i);
	}
}

Character::Character (const std::string& name): _name(name)
{
	std::cout << "parameter name constructor called for " <<  BLUE << "Character class" \
		<< NC << std::endl;
	initMaterias();
}

Character::~Character (void)
{
	std::cout << "destructor called for " <<  BLUE << "Character class" \
		<< NC << std::endl;
	for (int i = 0; i < MAT_NB; i++)
	{
		if (this->_materias[i])
			delete this->_materias[i];
	}
}

Character& Character::operator=(const Character& inst) 
{
	for (int i = 0; i < MAT_NB; i++)
	{
		delete this->_materias[i];
		this->_materias[i] = inst.getMateria(i);
	}
	this->_name = inst.getName();
	return (*this);
}

// member functions

AMateria* Character::getMateria(unsigned int idx) const
{
	if (idx < MAT_NB)
	{
		return (this->_materias[idx]);
	}
	else
		return (NULL);
}

const std::string& Character::getName() const
{
	return (this->_name);
}

// clone materia + free dans unequip ?
void	Character::equip(AMateria* m)
{
	std::cout << "equip call of " <<  YELLOW << "Character class" \
		<< NC << std::endl;
	for (int i = 0; i < MAT_NB; i++)
	{
		if (!this->_materias[i])
		{
			this->_materias[i] = m;
			return ;
		}
	}
}

void	Character::unequip(int idx)
{

	if (idx < 0 || idx >= MAT_NB || !this->_materias[idx])
		return ;
	this->_materias[idx] = NULL;
}

void	Character::use(int idx, ICharacter& target)
{
	if (idx < 0 || idx >= MAT_NB)
		std::cerr << "invalid index" << std::endl;
	if (!this->_materias[idx])
		std::cerr << "nothing at this index" << std::endl;
	this->_materias[idx]->use(target);
}