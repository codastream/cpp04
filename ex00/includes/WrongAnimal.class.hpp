
#ifndef WRONG_ANIMAL_CLASS_HPP
# define WRONG_ANIMAL_CLASS_HPP

#include <string>
#include <iostream>
#include "util.hpp"

class WrongAnimal
{
	private:

	protected:
		std::string	_type;
	
	public:
		WrongAnimal(void);
		WrongAnimal(const WrongAnimal& o);
		WrongAnimal(const std::string& type);
		virtual ~WrongAnimal( void );

		WrongAnimal& operator=(const WrongAnimal& o);

		const std::string	getType(void) const;
		void				setType(const std::string& type);
		void				makeSound(void) const;
};

std::ostream &operator<<(std::ostream& os, const WrongAnimal& a);

#endif
