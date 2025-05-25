
#ifndef ANIMAL_CLASS_HPP
# define ANIMAL_CLASS_HPP

#include <string>
#include <iostream>

class Animal
{
	private:
	
	public:
	Animal( void );
	Animal( const Animal &o );
	Animal( const std::string &type );
	virtual ~Animal( void );
	virtual Animal& operator=( const Animal &o );

	//member
	const std::string	getType( void ) const;
	void				setType( const std::string &type );
	virtual void		makeSound( void ) const;
	
	protected:
	std::string	_type;
};

std::ostream &operator<<(std::ostream &os, const Animal &a);

#endif
