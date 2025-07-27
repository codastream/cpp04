#ifndef CHARACTER_CLASS_HPP
# define CHARACTER_CLASS_HPP

#include "ICharacter.class.hpp"

const int MAT_NB = 4;
class Character: public ICharacter
{
	private:
		std::string			_name;
		AMateria			*_materias[MAT_NB];
		void				_initMaterias(void);
		int					_nbMateria;

	public:
		Character(void);
		~Character(void);
		Character(Character& inst);
		Character (const std::string& name);

		Character& 			operator=(const Character& inst);

		const std::string&	getName() const;
		AMateria*			getMateria(unsigned int idx) const;
		void				equip(AMateria* m);
		void				unequip(int idx);
		void				use(int idx, ICharacter& target);
};

std::ostream& operator<<(std::ostream& os, const Character& o);

#endif
