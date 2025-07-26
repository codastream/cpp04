
#ifndef CAT_CLASS_HPP
# define CAT_CLASS_HPP

# include <string>
# include <iostream>
# include "Animal.class.hpp"

class Cat : public Animal
{
	public:
		Cat(void);
		Cat(const Cat& o);
		~Cat(void);

		Cat& 				operator=(const Cat& o);

		void				makeSound(void) const;
};

#endif
