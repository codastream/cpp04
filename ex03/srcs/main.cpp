#include "AMateria.class.hpp"
#include "MateriaSource.class.hpp"
#include "Character.class.hpp"
#include "Ice.class.hpp"
#include "Cure.class.hpp"
#include "util.hpp"

void testIceMateria(void)
{
	putcol(PURPLEBACK, "ICE");
	putcol(YELLOWBACK, "default constructor");
	Ice *ice = new Ice();
	putcol(YELLOWBACK, "copy constructor");
	Ice *copied(ice);
	putcol(YELLOWBACK, "clone");
	Ice *cloned = static_cast<Ice *>(ice->clone());
	putcol(YELLOWBACK, "use");
	Character *princess = new Character("Frozen");
	copied->use(*princess);
	putcol(YELLOWBACK, "destructor");
	delete ice;
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
	ms.learnMateria(&ice);
}

void testDefault(void)
{
	IMateriaSource *src = new MateriaSource();
	src->learnMateria(new Ice());
	src->learnMateria(new Cure());

	ICharacter* me = new Character("me");

	AMateria *tmp;
	tmp = src->createMateria("ice");
	me->equip(tmp);
	tmp = src->createMateria("cure");
	me->equip(tmp);

	ICharacter* bob = new Character("bob");

	me->use(0, *bob);
	me->use(1, *bob);

	delete bob;
	delete me;
	delete src;
}

int main( void )
{
	testCharacter();
	return 0;
}