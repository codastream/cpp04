
#ifndef DOG_CLASS_HPP
# define DOG_CLASS_HPP

# include <string>
# include <iostream>
# include "AAnimal.class.hpp"
# include "Brain.class.hpp"

class Dog : public AAnimal
{
	private:
		Brain *_brain;

	public:
		Dog(void);
		Dog(const Dog &o);
		~Dog(void);
		Dog& operator=(const Dog &o);

		void				makeSound(void) const;
		Brain* 				getBrain(void);
};

#endif
