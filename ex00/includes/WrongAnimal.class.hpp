
#ifndef WRONG_ANIMAL_CLASS_HPP
# define WRONG_ANIMAL_CLASS_HPP

#include <string>
#include <iostream>

class WrongAnimal
{
	private:
	
	public:
	WrongAnimal( void );
	WrongAnimal( const WrongAnimal &o );
	WrongAnimal( const std::string &type );
	virtual ~WrongAnimal( void );
	virtual WrongAnimal& operator=( const WrongAnimal &o );

	//member
	const std::string	getType( void ) const;
	void				setType( const std::string &type );
	virtual void		makeSound( void ) const;
	
	protected:
	std::string	_type;
};

std::ostream &operator<<(std::ostream &os, const WrongAnimal &a);

#endif
