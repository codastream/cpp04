
#ifndef CAT_CLASS_HPP
# define CAT_CLASS_HPP

# include <string>
# include <iostream>
# include "AAnimal.class.hpp"
# include "Brain.class.hpp"

class Cat : public AAnimal
{
	public:
		Cat(void);
		Cat(const Cat &o);
		~Cat(void);
		Cat& operator=(const Cat &o);
		
		void				makeSound(void) const;
		Brain* 				getBrain(void);

	private:
		Brain *_brain;
};

#endif
