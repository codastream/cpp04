#ifndef UTIL_HPP
# define UTIL_HPP

#include <string>
#include <iostream>

# define NC      "\033[0m"
# define BLACK   "\033[30m"
# define RED     "\033[31m"
# define GREEN   "\033[32m"
# define YELLOW  "\033[33m"
# define BLUE    "\033[44m"
# define MAGENTA "\033[35m"
# define CYAN    "\033[36m"
# define WHITE   "\033[37m"


void	put_nl(const std::string& s);

void	cpy_array_str(std::string *dest, const std::string *src, size_t size);

#endif