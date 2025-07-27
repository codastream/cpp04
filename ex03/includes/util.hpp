#ifndef UTIL_HPP
# define UTIL_HPP

#include <string>
#include <iostream>

# define NC			"\033[0m"
# define RED		"\033[31m"
# define BLUE		"\033[34m"
# define CYAN		"\033[36m"
# define BLACK		"\033[30m"
# define ORANGE		"\033[0;33m"
# define WHITE		"\033[37m"
# define GREEN		"\033[32m"
# define YELLOW		"\033[33m"
# define YELLOWBACK	"\e[3m\e[103m"
# define REDBACK	"\e[3m\e[101m"
# define MAGENTA	"\033[35m" 
# define BWHITE		"\e[1;37m"
# define IWHITE		"\e[3;37m"
# define BCYAN		"\e[1;36m"
# define BPURPLE	"\e[1;35m"
# define PURPLEBACK	"\e[3m\e[105m"
# define BBLUE		"\e[1;34m"
# define AMAT		BWHITE
# define ICE		CYAN
# define CURE		GREEN
# define CHAR		BLUE
# define MATS		MAGENTA

void	put_nl(const std::string &s);
void	putcol(const std::string& col, const std::string& msg);

#endif