#include "../includes/Cat.class.hpp"
#include "../includes/Brain.class.hpp"
#include "../includes/util.hpp"
/*
** @brief Default constructor
*/
Cat::Cat( void )
{
	std::cout << "default constructor called for " <<  BLUE << "Cat class" \
	<< NC << std::endl;
	_type = "Cat";
	_brain = new Brain();
	if (!_brain)
		put_nl("Error");
}

Cat::Cat( const Cat& o ) :  AAnimal(o), _type(o._type), _brain(o._brain)
{
	std::cout << "copy constructor called for " <<  BLUE << "Cat class" \
	<< NC << std::endl;
}

Cat::~Cat( void ) 
{
	std::cout << "destructor called for " <<  BLUE << "Cat class" \
	<< NC << std::endl;
	delete _brain;
}

Cat& Cat::operator=( const Cat &o )
{
	if (this != &o)
	{
		_type = o._type;
		_brain = o._brain;
	}
	return (*this);
}

const std::string Cat::getType( void ) const
{
	return (_type);
}

void Cat::setType( const std::string &type )
{
	_type = type;
}

void	Cat::makeSound( void ) const
{
	put_nl("Meow 😺");
}

Brain* 		Cat::getBrain( void )
{
	return (_brain);
}

std::ostream &operator<<(std::ostream &os, const Cat *a)
{
	os << YELLOW << "cat at add" << &a << " [type:" << a->getType() << "]" << NC;
	return (os);
}