#include "util.hpp"

void	put_nl(const std::string &s)
{
	std::cout << s << std::endl;
}

void	cpy_array_str(std::string *dest, const std::string *src, size_t size)
{
	for( size_t i = 0; i < size; i++)
	{
		dest[i] = src[i];
	}
}