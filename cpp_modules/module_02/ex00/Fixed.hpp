#ifndef FIXED_H
#define FIXED_H

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


class Fixed
{
	private:
		int 				integral;
		static const int	fractional = 8;
	public:
		Fixed();
		Fixed(const Fixed &fixed);
		Fixed&				operator=(const Fixed&);
		void				setRawBits(const int);
		int					getRawBits() const;
		~Fixed();
};

#endif