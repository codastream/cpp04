
#ifndef DOG_CLASS_HPP
# define DOG_CLASS_HPP

# include <string>
# include <iostream>
# include "Animal.class.hpp"

class Dog : public Animal
{
	public:
		Dog(void);
		Dog(const Dog& o);
		virtual ~Dog(void);
		Dog& 				operator=(const Dog& o);

		void				makeSound(void) const;
};

#endif
