
#ifndef DOG_CLASS_HPP
# define DOG_CLASS_HPP

# include <string>
# include <iostream>
# include "Animal.class.hpp"

class Dog : public Animal
{
	public:
	Dog( void );
	Dog( const Dog &o );
	~Dog( void );
	Dog& operator=( const Dog &o );

	//member
	// const std::string	getType( void ) const;
	// void				setType( const std::string &type );
	void				makeSound( void ) const;

	protected:
};

#endif
