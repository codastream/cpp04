
#ifndef CAT_CLASS_HPP
# define CAT_CLASS_HPP

# include <string>
# include <iostream>
# include "WrongAnimal.class.hpp"
# include "Brain.class.hpp"

class WrongCat : public WrongAnimal
{
	private:
	Brain *_brain;
	
	public:
	WrongCat( void );
	WrongCat( const WrongCat &o );
	~WrongCat( void );
	WrongCat& operator=( const WrongCat &o );
	
	//member

	protected:
};

#endif
