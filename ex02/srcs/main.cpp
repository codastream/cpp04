#include "AAnimal.class.hpp"
#include "Dog.class.hpp"
#include "Cat.class.hpp"
#include "util.hpp"

void array(void)
{
	putcol(YELLOWBACK, "AAnimal *animals[10] : 5 dogs 5 cats");
	int	n = 10;
	AAnimal *animals[n];
	for (int i = 0; i < n; i++)
	{
		if (i < (n / 2))
			animals[i] = new Dog();
		else
			animals[i] = new Cat();
	}
	putcol(BLUE, "checking *animals[6]");
	std::cout << *(animals[6]) << std::endl;
	putcol(BLUE, "setting new idea at index #1");
	static_cast<Cat *>(animals[6])->getBrain()->setIdea(1, "good idea");
	putcol(BLUE, "checking *animals[6] idea at index #1");
	std::cout << static_cast<Cat *>(animals[6])->getBrain()->getIdeaByIndex(1) << std::endl;
	for (int i = 0; i < n; i++)
	{
		delete animals[i];
	}
}

void	readBrain(void)
{
	{
		putcol(YELLOWBACK, "read brain cat");
		Cat *tom = new Cat();
		putcol(BLUE, "brain after default constructor");
		std::cout << *(tom->getBrain()) << std::endl;
		tom->getBrain()->setIdea(0, "eat");
		tom->getBrain()->setIdea(1, "play with human");
		tom->getBrain()->setIdea(2, "rule the world");
		putcol(BLUE, "brain after some time");
		std::cout << *(tom->getBrain()) << std::endl;
		putcol(YELLOWBACK, "brain deep copy");
		Cat cheschire(*tom);
		std::cout << *(cheschire.getBrain()) << std::endl;
		putcol(YELLOWBACK, "ideas should evolve separately in both instances");
		cheschire.getBrain()->setIdea(0, "smile");
		std::cout << "tom" << *(tom->getBrain()) << std::endl;
		delete tom;
		std::cout << "cheschire" << *(cheschire.getBrain()) << std::endl;
	}
	{
		putcol(YELLOWBACK, "read brain dog");
		Dog milou;
		putcol(BLUE, "brain after default constructor");
		std::cout << *(milou.getBrain()) << std::endl;
		milou.getBrain()->setIdea(0, "yes tintin");
		milou.getBrain()->setIdea(1, "be a good dog");
		putcol(BLUE, "brain after some time");
		std::cout << *(milou.getBrain()) << std::endl;
		putcol(YELLOWBACK, "brain deep copy");
		Dog joy(milou);
		std::cout << *(joy.getBrain()) << std::endl;
		putcol(YELLOWBACK, "ideas should evolve separately in both instances");
		joy.getBrain()->setIdea(0, "get the swag");
		std::cout << "joy" << *(joy.getBrain()) << std::endl;
		std::cout << "milou" << *(milou.getBrain()) << std::endl;
	}
}

void	wrong(void)
{
	putcol(YELLOWBACK, "wrong");
	Cat tom;
	putcol(BLUE, "checking out of index");
	std::cout << tom.getBrain()->getIdeaByIndex(100) << std::endl;
	putcol(BLUE, "setting out of index");
	tom.getBrain()->setIdea(100, "out of range");
	std::cout << tom.getBrain() << std::endl;
}

int main( void )
{
	array();
	wrong();
	readBrain();
}