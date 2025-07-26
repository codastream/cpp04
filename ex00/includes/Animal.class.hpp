
#ifndef ANIMAL_CLASS_HPP
# define ANIMAL_CLASS_HPP

#include <string>
#include <iostream>
#include "util.hpp"

class Animal
{
	protected:
		std::string			_type;
	
	public:
		Animal(void);
		Animal(const Animal& o);
		Animal(const std::string& type);
		virtual ~Animal(void);

		Animal& 			operator=(const Animal& o);
		
		const std::string	getType(void) const;
		void				setType(const std::string& type);
		virtual void		makeSound(void) const;

};

std::ostream& operator<<(std::ostream& os, const Animal& a);

#endif
