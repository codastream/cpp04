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
		Cure(const std::string& type);
		virtual ~Cure(void);
		Cure& operator=(const Cure& inst);

		// member
		// const std::string&	getType(void);
		// void				use(ICharacter& target);
		AMateria*			clone(void) const;

	private:

};

#endif