#ifndef FIRE_CLASS_HPP
# define FIRE_CLASS_HPP

#include <string>
#include <iostream>
#include "AMateria.class.hpp"
#include "Character.class.hpp"

class Character;

class Fire : public AMateria
{
	public:
		Fire(void);
		Fire(const Fire& inst);
		virtual ~Fire(void);
		Fire& operator=(const Fire& inst);

		AMateria*			clone(void) const;
		void				use(ICharacter& target);
};

#endif