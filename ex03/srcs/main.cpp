#include "AMateria.class.hpp"
#include "MateriaSource.class.hpp"
#include "Character.class.hpp"
#include "Ice.class.hpp"
#include "Cure.class.hpp"
#include "Fire.class.hpp"
#include "util.hpp"

void testIceMateria(void)
{
	putcol(PURPLEBACK, "ICE");
	putcol(YELLOWBACK, "default constructor");
	Ice *ice = new Ice();
	putcol(YELLOWBACK, "copy constructor");
	Ice *copied(ice);
	std::cout << *copied << std::endl;
	putcol(YELLOWBACK, "clone");
	Ice *cloned = static_cast<Ice *>(ice->clone());
	std::cout << *cloned << std::endl;

	putcol(YELLOWBACK, "use");
	Character *princess = new Character("Frozen");
	copied->use(*princess);

	putcol(YELLOWBACK, "destructor");
	delete ice;
	delete cloned;
	delete princess; // let it go
}

void testCureMateria(void)
{
	putcol(PURPLEBACK, "CURE");
	putcol(YELLOWBACK, "default constructor");
	Cure *cure = new Cure();
	putcol(YELLOWBACK, "copy constructor");
	Cure *copied(cure);
	std::cout << *copied << std::endl;
	putcol(YELLOWBACK, "clone");
	Cure *cloned = static_cast<Cure *>(cure->clone());
	std::cout << *cloned << std::endl;

	putcol(YELLOWBACK, "use");
	Character *princess = new Character("Frozen");
	copied->use(*princess);

	putcol(YELLOWBACK, "destructor");
	delete cure;
	delete cloned;
	delete princess; // let it go
}

void testCharacter(void)
{
	putcol(PURPLEBACK, "CHARACTER");
	putcol(YELLOWBACK, "default constructor");
	Character *frozen = new Character();
	putcol(YELLOWBACK, "param constructor");
	Character *badguy = new Character("badguy");

	putcol(YELLOWBACK, "equip");
	Ice ice;
	Cure cure;
	frozen->equip(&ice);
	frozen->equip(&cure);

	putcol(YELLOWBACK, "use");
	frozen->use(0, *badguy);
	putcol(REDBACK, "use negative index");
	frozen->use(-1, *badguy);
	putcol(REDBACK, "use bad index");
	frozen->use(4, *badguy);
	putcol(REDBACK, "use with nothing");
	frozen->use(2, *badguy);
	// putcol(REDBACK, "use with deleted target"); // can't protect ?
	// delete badguy;
	// cha->use(0, *badguy);

	putcol(YELLOWBACK, "equip");
	putcol(REDBACK, "unequip negative index");
	frozen->unequip(-1);
	putcol(REDBACK, "unequip bad index");
	frozen->unequip(4);
	putcol(REDBACK, "unequip with nothing");
	frozen->unequip(2);

	delete frozen;
	delete badguy;
}

void testMateriaSource(void)
{
	putcol(PURPLEBACK, "MATERIA SOURCE");
	putcol(YELLOWBACK, "default constructor");
	MateriaSource ms;
	
	putcol(YELLOWBACK, "learn");
	Ice ice;
	Cure cure;
	ms.learnMateria(&ice);
	ms.learnMateria(&ice);
	std::cout << ms << std::endl;

	putcol(YELLOWBACK, "copy constructor");
	MateriaSource ms2(ms);
	putcol(YELLOWBACK, "checking deep copy : should have same materias");
	std::cout << ms2 << std::endl;
	putcol(YELLOWBACK, "checking deep copy : should evolve differently");
	ms2.learnMateria(&cure);
	ms2.learnMateria(&cure);
	putcol(YELLOW, "ms has still same 2 copies");	
	std::cout << ms << std::endl;
	putcol(YELLOW, "ms2 has also 2 new copies");
	std::cout << ms2 << std::endl;
	
	putcol(REDBACK, "learning when full");
	ms2.learnMateria(&cure);

	putcol(YELLOWBACK, "create");
	AMateria *c1 = ms2.createMateria("cure");
	delete c1;
	putcol(REDBACK, "create not in store");
	ms.createMateria("cure");
	putcol(REDBACK, "create unknown");
	ms2.createMateria("curedent");
}

void testDefault(void)
{
	putcol(YELLOWBACK, "MateriaSource can learn any Materia");
	IMateriaSource *src = new MateriaSource();
	Ice ice;
	src->learnMateria(&ice);
	Cure cure;
	src->learnMateria(&cure);
	Fire fire;
	src->learnMateria(&fire);

	putcol(YELLOWBACK, "ICharacter::equip");
	ICharacter* me = new Character("me");
	AMateria *tmp;
	AMateria *tmp1;
	AMateria *tmp2;
	tmp = src->createMateria("ice");
	me->equip(tmp);
	tmp1 = src->createMateria("cure");
	me->equip(tmp1);
	tmp2 = src->createMateria("fire");
	me->equip(tmp2);
	std::cout << static_cast<Character&>(*me) << std::endl;

	putcol(YELLOWBACK, "ICharacter::use");
	ICharacter* bob = new Character("bob");
	me->use(0, *bob);
	me->use(1, *bob);
	me->use(2, *bob);
	
	putcol(YELLOWBACK, "ICharacter::unequip");
	me->unequip(1);
	std::cout << static_cast<Character&>(*me) << std::endl;

	putcol(YELLOWBACK, "equip at first free slot");
	me->equip(tmp1);
	std::cout << static_cast<Character&>(*me) << std::endl;

	delete bob;
	delete me;
	delete(tmp);
	delete(tmp1);
	delete(tmp2);
	delete src;
}

int main( void )
{
	testIceMateria();
	testCureMateria();
	testCharacter();
	testMateriaSource();
	testDefault();
	return 0;
}