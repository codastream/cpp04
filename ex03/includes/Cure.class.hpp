#ifndef CURE_CLASS_HPP
# define CURE_CLASS_HPP

#include <string>
#include <iostream>
#include "AMateria.class.hpp"
#include "Character.class.hpp"

class Character;

class Cure : public AMateria
{
	public:
		Cure(void);
		Cure(const Cure& inst);
		virtual ~Cure(void);
		Cure& operator=(const Cure& inst);

		AMateria*			clone(void) const;
		void				use(ICharacter& target);
};

#endif