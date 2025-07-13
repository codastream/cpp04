#ifndef ICE_CLASS_HPP
# define ICE_CLASS_HPP

#include <string>
#include <iostream>
#include "AMateria.class.hpp"
#include "Character.class.hpp"

class Character;

class Ice : public AMateria
{
	public:
		Ice(void);
		Ice(const Ice& inst);
		Ice(const std::string& type);
		virtual ~Ice(void);
		Ice& operator=(const Ice& inst);

		// void				use(ICharacter& target);
		AMateria*			clone(void) const;

	private:

};

#endif