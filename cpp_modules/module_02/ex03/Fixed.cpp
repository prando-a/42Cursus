#include "Fixed.hpp"

Fixed::Fixed()
{
	std::cout << GREEN << "Default constructor called\n" << RESET;
	this->integral = 0;
}

Fixed::Fixed(const Fixed &fixed)
{
	std::cout << GREEN << "Copy constructor called\n" << RESET;
	*this = fixed;
}

Fixed::Fixed(const int integral)
{
	std::cout << GREEN << "Int constructor called\n" << RESET;
	this->integral = integral << fractional;
}

Fixed::Fixed(const float integral)
{
	std::cout << GREEN << "Float constructor called\n" << RESET;
	this->integral = roundf(integral * (1 << fractional));
}

Fixed &Fixed::operator=(const Fixed &fixed)
{
    std::cout << GREEN "Copy assignment operator called\n" << RESET;
    this->integral = fixed.integral;
    return (*this);
}

void Fixed::setRawBits(int const raw)
{
	std::cout << GREEN << "setRawBits member function called\n" << RESET;
	this->integral = raw;
}

int Fixed::getRawBits( void ) const
{
	std::cout << GREEN << "getRawBits member function called\n" << RESET;
	return (this->integral);
}

float Fixed::toFloat(void) const
{
	return ((float)this->integral / (1 << fractional));
}

int Fixed::toInt(void) const
{
	return (this->integral >> fractional);
}

Fixed::~Fixed()
{
	std::cout << GREEN << "Destructor called\n" << RESET;
}

// https://www.youtube.com/watch?v=5JzzR9IFtiA
std::ostream &operator<<(std::ostream &out, const Fixed &fixed)
{
	out << fixed.toFloat();
	return (out);
}

bool	Fixed::operator<(const Fixed &a) const
{
	return (this->integral < a.integral);
}

bool	Fixed::operator>(const Fixed &a) const
{
	return (this->integral > a.integral);
}

bool	Fixed::operator<=(const Fixed &a) const
{
	return (this->integral <= a.integral);
}

bool	Fixed::operator>=(const Fixed &a) const
{
	return (this->integral >= a.integral);
}

bool	Fixed::operator==(const Fixed &a) const
{
	return (this->integral == a.integral);
}

Fixed Fixed::operator+(const Fixed &a) const
{
	return (Fixed(this->toFloat() + a.toFloat()));
}

Fixed Fixed::operator-(const Fixed &a) const
{
	return (Fixed(this->toFloat() - a.toFloat()));
}

Fixed Fixed::operator*(const Fixed &a) const
{
	return (Fixed(this->toFloat() * a.toFloat()));
}

Fixed Fixed::operator/(const Fixed &a) const
{
	return (Fixed(this->toFloat() / a.toFloat()));
}

Fixed &Fixed::operator++(void)
{
	this->integral++;
	return (*this);
}

Fixed &Fixed::operator--(void)
{
	this->integral--;
	return (*this);
}

Fixed Fixed::operator++(int)
{
	Fixed tmp(*this);
	operator++();
	return (tmp);
}

Fixed Fixed::operator--(int)
{
	Fixed tmp(*this);
	operator--();
	return (tmp);
}

Fixed Fixed::max(const Fixed &a, const Fixed &b)
{
	if (a > b)
		return (a);
	return (b);
}

Fixed Fixed::min(const Fixed &a, const Fixed &b)
{
	if (a < b)
		return (a);
	return (b);
}

Fixed& Fixed::max(Fixed &a, Fixed &b)
{
	if (a > b)
		return (a);
	return (b);
}

Fixed& Fixed::min(Fixed &a, Fixed &b)
{
	if (a < b)
		return (a);
	return (b);
}