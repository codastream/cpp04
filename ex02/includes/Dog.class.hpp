
#ifndef DOG_CLASS_HPP
# define DOG_CLASS_HPP

# include <string>
# include <iostream>
# include "AAnimal.class.hpp"
# include "Brain.class.hpp"

class Dog : public AAnimal
{
	private:
	std::string _type;
	Brain 		*_brain;

	public:
	Dog( void );
	Dog( const Dog &o );
	virtual ~Dog( void );
	Dog& operator=( const Dog &o );

	//member
	const std::string	getType( void ) const;
	void				setType( const std::string &type );
	void				makeSound( void ) const;
	Brain* 				getBrain( void );
	
	protected:
};

// std::ostream &operator<<(std::ostream &os, const AAnimal *a);

#endif
