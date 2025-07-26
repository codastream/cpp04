#include "../includes/Brain.class.hpp"
#include "../includes/util.hpp"
#include <sstream>

Brain::Brain( void )
{
	std::cout << "default constructor called for " <<  BLUE << "Brain class" \
	<< NC << std::endl;
	for( size_t i = 0; i < 100; i++)
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

std::string Brain::getIdeaByIndex(unsigned int index) const
{
	if (index < 100)
	{
		return _ideas[index];
	}
	std::cerr << RED << "out of range" << NC << std::endl;
	return ("out of range idea");
}

void		Brain::setIdea(unsigned int index, const std::string &s)
{
	if (index < 100)
	{
		_ideas[index] = s;
	}
}

std::ostream& operator<<(std::ostream& os, const Brain& b)
{
	os << BWHITE << "brain" << NC << std::endl;
	int i = 0;
	std::string idea = b.getIdeaByIndex(i);
	while (i < 100 && !idea.empty())
	{
		os << "idea" << i << " => " << IWHITE << b.getIdeaByIndex(i) << NC << std::endl;
		i++;
		idea = b.getIdeaByIndex(i);
	}
	return (os);
}