#include "../includes/Brain.class.hpp"
#include "../includes/util.hpp"
#include <sstream>

Brain::Brain( void )
{
	std::cout << "default constructor called for " <<  BLUE << "Brain class" \
	<< NC << std::endl;
	for (int i = 0; i < 100; i++)
	{
		std::ostringstream str;
		str << "idea " << i;
		_ideas[i] = str.str();
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

std::string Brain::getIdeaByIndex(unsigned int index)
{
	if (index < 100)
	{
		return _ideas[index];
	}
	return (0);
}

void		Brain::setIdea(unsigned int index, const std::string &s)
{
	if (index < 100)
	{
		_ideas[index] = s;
	}
}