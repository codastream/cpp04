#include "../includes/Brain.class.hpp"
#include "../includes/util.hpp"

Brain::Brain( void )
{
	std::cout << "default constructor called for " <<  BLUE << "Brain class" \
	<< NC << std::endl;
	for (size_t i = 0; i < 100; i++)
	{
		_ideas[i] = "";
	}
}

Brain::Brain( const Brain &o )
{
	std::cout << "copy constructor called for " <<  BLUE << "Brain class" \
	<< NC << std::endl;
	cpy_array_str(_ideas, o._ideas, 100);
}

Brain::~Brain( void ) 
{
	std::cout << "destructor called for " <<  BLUE << "Brain class" \
	<< NC << std::endl;
}

Brain& Brain::operator=( const Brain &o )
{
	if (this != &o)
	{
		cpy_array_str(_ideas, o._ideas, 100);
	}
	return (*this);
}
