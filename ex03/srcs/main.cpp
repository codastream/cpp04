#include "AMateria.class.hpp"
#include "MateriaSource.class.hpp"
#include "Character.class.hpp"
#include "Ice.class.hpp"
#include "Cure.class.hpp"
#include "util.hpp"

int main( void )
{
	IMateriaSource *src = new MateriaSource();
	src->learnMateria(new Cure());
}