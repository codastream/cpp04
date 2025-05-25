
#ifndef CAT_CLASS_HPP
# define CAT_CLASS_HPP

# include <string>
# include <iostream>
# include "Animal.class.hpp"

class Cat : public Animal
{
	private:
	
	public:
	Cat( void );
	Cat( const Cat &o );
	~Cat( void );
	Cat& operator=( const Cat &o );
	
	//member
	// const std::string	getType( void ) const;
	// void				setType( const std::string &type );
	void				makeSound( void ) const;

	protected:
};

#endif
