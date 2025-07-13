
#ifndef AMATERIA_CLASS_HPP
# define AMATERIA_CLASS_HPP

#include <string>
#include <iostream>
#include "util.hpp"
#include "Character.class.hpp"

class ICharacter;
class AMateria
{
	protected:
		std::string	_type;

	public:
		AMateria(const std::string& type);
		AMateria(void);
		AMateria(const AMateria& inst);
		AMateria& operator= (const AMateria& inst);
		virtual ~AMateria(void);

		// member
		const std::string&	getType(void) const;
		virtual AMateria*	clone(void) const = 0;
		virtual void		use(ICharacter& target);
};

#endif
