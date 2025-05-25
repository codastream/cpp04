#include "Animal.class.hpp"
#include "WrongAnimal.class.hpp"
#include "WrongCat.class.hpp"
#include "Dog.class.hpp"
#include "Cat.class.hpp"

void	test_const_heap()
{
	const	Animal *meta = new Animal();
	const	Animal *ad = new Dog();
	const	Animal *ac = new Cat();
	const	WrongAnimal *wc = new WrongCat();

	std::cout << *ad << std::endl;
	std::cout << *ac << std::endl;
	meta->makeSound();
	ad->makeSound();
	ac->makeSound();
	wc->makeSound();

	delete meta;
	delete ad;
	delete ac;
	delete wc;
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