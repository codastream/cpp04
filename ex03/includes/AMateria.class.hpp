
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
		AMateria(void);
		AMateria(const AMateria& inst);
		AMateria(const std::string& type);
		virtual ~AMateria(void);

		AMateria& operator= (const AMateria& inst);

		const std::string&	getType(void) const;
		virtual AMateria*	clone(void) const = 0;
		virtual void		use(ICharacter& target);
};

std::ostream& operator<<(std::ostream& os, const AMateria& o);

#endif
