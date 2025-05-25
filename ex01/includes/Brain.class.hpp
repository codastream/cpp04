#ifndef BRAIN_CLASS_HPP
# define BRAIN_CLASS_HPP

# include <string>
# include <iostream>

class Brain
{
	private:
	std::string _ideas[100];
	
	public:
	Brain( void );
	Brain( const Brain &o );
	~Brain( void );
	Brain& operator=( const Brain &o );
	
	//member

	protected:
};

#endif
