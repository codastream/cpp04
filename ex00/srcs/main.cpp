#include "Animal.class.hpp"
#include "Cat.class.hpp"
#include "Dog.class.hpp"
#include "WrongAnimal.class.hpp"
#include "WrongCat.class.hpp"

void	test_const_heap()
{
	putcol(BLUE, "Constructors");
	putcol(YELLOWBACK, "new Animal - const Animal *meta = new Animal();");
	const	Animal *meta = new Animal();
	std::cout << *meta << std::endl;
	meta->makeSound();
	putcol(YELLOWBACK, "new Animal/Dog - const Animal *ad = new Dog()");
	const	Animal *ad = new Dog();
	std::cout << *ad << std::endl;
	ad->makeSound();
	putcol(YELLOWBACK, "new Animal/Cat - const Animal *ac = new Cat();");
	const	Animal *ac = new Cat();
	std::cout << *ac << std::endl;
	ac->makeSound();
	putcol(YELLOWBACK, "new Wrong Animal - const WrongAnimal *wa = new WrongAnimal();");
	const	WrongAnimal *wa = new WrongAnimal();
	std::cout << *wa << std::endl;
	wa->makeSound();
	putcol(YELLOWBACK, "new Wrong Animal/WrongCat - const WrongAnimal *wa = new WrongCat();");
	const	WrongAnimal *wc = new WrongCat();
	std::cout << *wc << std::endl;
	wc->makeSound();
	putcol(YELLOWBACK, "new Wrong Cat - const WrongCat *wc = new WrongCat();");
	const	WrongCat *wcat = new WrongCat();
	std::cout << *wcat << std::endl;
	wcat->makeSound();

	delete meta;
	delete ad;
	delete ac;
	delete wa;
	delete wc;
	delete wcat;
}

void	test_getter_setter()
{
	putcol(YELLOWBACK, "Animal dog - Mutable stack + setType - ⚠️ object slicing");
	Animal ad = Dog();
	std::cout << ad << std::endl;
	ad.setType("Chihuahua");
	std::cout << "dog type is " << ad.getType() << std::endl;
	ad.makeSound();
	
	putcol(YELLOWBACK, "Animal dog Mutable stack + setType - No slicing");
	Dog dd;
	std::cout << dd << std::endl;
	Animal& aref = dd;
	std::cout << aref << std::endl;
	aref.makeSound();

	putcol(YELLOWBACK, "Mutable heap + setType");
	Animal *ac = new Cat();
	std::cout << *ac << std::endl;
	ac->setType("Angora");
	std::cout << *ac << std::endl;
	ac->makeSound();

	delete ac;
}

int main( void )
{
	test_const_heap();
	test_getter_setter();
}