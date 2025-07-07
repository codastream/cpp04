#ifndef CHARACTER_CLASS_HPP
# define CHARACTER_CLASS_HPP

#include "ICharacter.class.hpp"

class Character: public ICharacter
{
	private:
		const std::string&	_name;
		AMateria 			*_materias[MAT_NB];
	
	public:
		Character(void);
		~Character(void);
		Character(Character& inst);
		Character::Character (const std::string& name);

		Character& operator=(const Character& inst);

		// member functions
		std::string const& getName() const;
		AMateria* getMateria(unsigned int idx) const;
		void equip(AMateria* m);
		void unequip(int idx);
		void use(int idx, ICharacter& target);
};

const unsigned int	MAT_NB = 4;

#endif
