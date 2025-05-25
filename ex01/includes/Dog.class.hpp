
#ifndef DOG_CLASS_HPP
# define DOG_CLASS_HPP

# include <string>
# include <iostream>
# include "Animal.class.hpp"
# include "Brain.class.hpp"

class Dog : public Animal
{
	private:
	Brain *_brain;

	public:
	Dog( void );
	Dog( const Dog &o );
	~Dog( void );
	Dog& operator=( const Dog &o );

	//member
	void				makeSound( void ) const;

	protected:
};

#endif
