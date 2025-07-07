#include "Character.class.hpp"
#include "util.hpp"

Character::Character (void): _name("default")
{
	for (int i = 0; i < MAT_NB; i++)
	{
		this->_materias[i] = nullptr;
	}
	// std::cout << "default constructor called for " <<  BLUE << "Character class" \
	// 	<< NC << std::endl;
}

Character::Character(Character& inst): _name(inst.getName())
{
	for (int i = 0; i < MAT_NB; i++)
	{
		delete this->_materias[i];
		this->_materias[i] = inst.getMateria(i);
	}
}

Character::Character (const std::string& name): _name(name) {}

Character::~Character (void)
{
	// std::cout << "destructor called for " <<  BLUE << "Character class" \
	// 	<< NC << std::endl;
	for (int i = 0; i < MAT_NB; i++)
	{
		if (this->_materias[i])
			delete this->_materias[i];
	}
}

Character& Character::operator=(const Character& inst) 
{}

// member functions


AMateria* Character::getMateria(unsigned int idx) const
{
	if (idx < MAT_NB)
	{
		return (this->_materias[idx]);
	}
}

const std::string& Character::getName() const
{
	return (this->_name);
}

// clone materia + free dans unequip ?
void	Character::equip(AMateria* m)
{
	for (int i = 0; i < MAT_NB; i++)
	{
		if (!this->_materias[i])
			this->_materias[i] = m;
	}
}

void	Character::unequip(int idx)
{

	if (idx < 0 || idx >= MAT_NB || !this->_materias[idx])
		return ;
	this->_materias[idx] = nullptr;
}

void	Character::use(int idx, ICharacter& target)
{
	if (idx < 0 || idx >= MAT_NB)
		std::cerr << "invalid index" << std::endl;
	if (!this->_materias[idx])
		std::cerr << "nothing at this index" << std::endl;
	this->_materias[idx]->use(target);
}