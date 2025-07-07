
#ifndef AMATERIA_CLASS_HPP
# define AMATERIA_CLASS_HPP

#include <string>
#include <iostream>

class ICharacter;
class AMateria
{
	protected:
		std::string	_type;

	public:
		AMateria(std::string const &type);
		AMateria(void);
		AMateria(const AMateria &inst);
		AMateria& operator= (const AMateria &inst);
		virtual ~AMateria(void);

		// member
		std::string const & getType(void) const;
		virtual AMateria* clone(void) const = 0;
		virtual void use(ICharacter& target);
};

#endif
