
#ifndef CAT_CLASS_HPP
# define CAT_CLASS_HPP

# include <string>
# include <iostream>
# include "WrongAnimal.class.hpp"

class WrongCat : public WrongAnimal
{
	private:

	protected:
	
	public:
	WrongCat(void);
	WrongCat(const WrongCat& o);
	~WrongCat(void);

	WrongCat& 	operator=(const WrongCat& o);
};

#endif
