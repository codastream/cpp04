#include "IMateriaSource.class.hpp"

const int MAT_NB_SRC = 4;
class MateriaSource: public IMateriaSource
{
	public:
		MateriaSource(void);
		~MateriaSource(void);
		MateriaSource(MateriaSource& inst);

		MateriaSource&	operator=(MateriaSource& inst);

		void			learnMateria(AMateria*);
		AMateria*		createMateria(const std::string& type);
	
	private:
		AMateria*	_materias[4];
};

std::ostream& operator<<(std::ostream& os, const MateriaSource& o);