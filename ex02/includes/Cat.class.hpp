
#ifndef CAT_CLASS_HPP
# define CAT_CLASS_HPP

# include <string>
# include <iostream>
# include "AAnimal.class.hpp"
# include "Brain.class.hpp"

class Cat : public AAnimal
{
	private:
	std::string _type;
	Brain 		*_brain;
	
	public:
	Cat( void );
	Cat( const Cat &o );
	virtual ~Cat( void );
	Cat& operator=( const Cat &o );
	
	//member
	const std::string	getType( void ) const;
	void				setType( const std::string &type ); 
	void				makeSound( void ) const;
	Brain* 				getBrain( void );

	protected:
};

// std::ostream &operator<<(std::ostream &os, const AAnimal *a);

#endif
