#include "IMateriaSource.class.hpp"

class MateriaSource: public IMateriaSource
{
	public:
	MateriaSource(void);
	MateriaSource(MateriaSource& inst);
	MateriaSource&	operator=(MateriaSource& inst);
	
	private:
	AMateria*	_materias[4];
};