#include "../includes/Dog.class.hpp"
#include "../includes/Brain.class.hpp"
#include "../includes/util.hpp"

Dog::Dog( void )
{
	std::cout << "default constructor called for " <<  BLUE << "Dog class" \
	<< NC << std::endl;
	_type = "Dog";
	_brain = new Brain();
}

Dog::Dog( const Dog& o ) : AAnimal(o), _type(o._type), _brain(o._brain)
{
	std::cout << "copy constructor called for " <<  BLUE << "Dog class" \
	<< NC << std::endl;
}

Dog::~Dog( void ) 
{
	std::cout << "destructor called for " <<  BLUE << "Dog class" \
	<< NC << std::endl;
	delete _brain;
}

Dog& Dog::operator=( const Dog &o )
{
	if (this != &o)
	{
		_type = o._type;
		_brain = o._brain;
	}
	return (*this);
}

const std::string Dog::getType( void ) const
{
	return (_type);
}

void Dog::setType( const std::string &type )
{
	_type = type;
}

Brain* 		Dog::getBrain( void )
{
	return (_brain);
}

void	Dog::makeSound( void ) const
{
	put_nl("Wouah 🐶");
}

std::ostream &operator<<(std::ostream &os, const AAnimal *a)
{
	os << YELLOW << "dog at add" << &a << " [type:" << a->getType() << "]" << NC;
	return (os);
}