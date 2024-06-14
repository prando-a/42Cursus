#ifndef HARL_H
#define HARL_H

#include <iostream>

# define RED     	"\x1b[31m"
# define GREEN   	"\x1b[32m"
# define YELLOW  	"\x1b[33m"
# define BLUE    	"\x1b[34m"
# define MAGENTA	"\x1b[35m"
# define CYAN    	"\x1b[36m"
# define WHITE		"\033[37m"
# define BOLD		"\033[1m"
# define RESET   	"\x1b[0m"
# define CLEAR		"\033[2J"


class Harl
{
	private:
		void			debug();
		void			info();
		void			warning();
		void			error();
		typedef void	(Harl::*funcPTR)();
		funcPTR			func[4];
		std::string		funcType[4];
	public:
		Harl();
		~Harl()	{};
		void			complain(std::string);
};

#endif