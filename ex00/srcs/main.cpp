#include "Animal.class.hpp"
#include "Dog.class.hpp"
#include "Cat.class.hpp"

void	test_const_heap()
{
	const	Animal *meta = new Animal();
	const	Animal *ad = new Dog();
	const	Animal *ac = new Cat();

	std::cout << *ad << std::endl;
	std::cout << *ac << std::endl;
	ad->makeSound();
	ac->makeSound();
	meta->makeSound();

	delete meta;
	delete ad;
	delete ac;
}

void	test_mutable_heap()
{
	Animal *meta = new Animal();
	Animal *ad = new Dog();
	Animal *ac = new Cat();

	ad->setType("Chihuahua");
	ac->setType("Angora");
	std::cout << *ad << std::endl;
	std::cout << *ac << std::endl;
	ad->makeSound();
	ac->makeSound();
	meta->makeSound();

	delete meta;
	delete ad;
	delete ac;
}

int main( void )
{
	test_const_heap();
	test_mutable_heap();
}