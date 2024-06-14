#ifndef FIXED_H
#define FIXED_H

#include <iostream>
#include <cmath>

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
		Fixed(const Fixed&);
		Fixed(const int);
		Fixed(const float);
		Fixed&				operator=(const Fixed&);
		void				setRawBits(const int);
		int					getRawBits() const;
		float				toFloat(void) const;
		int					toInt(void) const;
		bool				operator>(const Fixed&) const;
		bool				operator<(const Fixed&) const;
		bool				operator>=(const Fixed&) const;
		bool				operator<=(const Fixed&) const;
		bool				operator==(const Fixed&) const;
		bool				operator!=(const Fixed&) const;
		Fixed				operator+(const Fixed&) const;
		Fixed				operator-(const Fixed&) const;
		Fixed				operator*(const Fixed&) const;
		Fixed				operator/(const Fixed&) const;
		Fixed&				operator++(void);
		Fixed&				operator--(void);
		Fixed				operator++(int);
		Fixed				operator--(int);
		static const Fixed&	max(const Fixed&, const Fixed&);
		static const Fixed&	min(const Fixed&, const Fixed&);
		static Fixed&		max(Fixed&, Fixed&);
		static Fixed&		min(Fixed&, Fixed&);
		~Fixed();
};

std::ostream	&operator<<(std::ostream &out, const Fixed &fixed);

#endif