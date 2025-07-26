
#ifndef ANIMAL_CLASS_HPP
# define ANIMAL_CLASS_HPP

#include <string>
#include <iostream>

class AAnimal
{
	private:
	
	public:
		AAnimal(void );
		AAnimal(const AAnimal &o);
		AAnimal(const std::string &type);
		AAnimal& operator=( const AAnimal &o);
		
		//member
		virtual 					~AAnimal(void);
		virtual std::string	const & getType(void) const;
		virtual void				setType(const std::string &type);
		virtual void				makeSound(void) const = 0;
	
	protected:
		std::string	_type;
};

std::ostream &operator<<(std::ostream &os, const AAnimal &a);

#endif
