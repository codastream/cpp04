#include "util.hpp"

void	put_nl(const std::string &s)
{
	std::cout << s << std::endl;
}

void	putcol(const std::string& col, const std::string& msg)
{
	std::cout << col << msg << NC << std::endl;
}