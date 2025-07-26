#ifndef BRAIN_CLASS_HPP
# define BRAIN_CLASS_HPP

# include <string>
# include <iostream>

class Brain
{
	private:
		std::string _ideas[100];
	
	public:
		Brain(void);
		Brain(const Brain &o);
		~Brain(void);
		Brain& operator=(const Brain &o);
		
		std::string getIdeaByIndex(unsigned int index) const;
		void		setIdea(unsigned int index, const std::string &s);

	protected:
};

std::ostream& operator<<(std::ostream& os, const Brain& b);

#endif
