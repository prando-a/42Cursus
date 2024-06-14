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

Fixed &Fixed::operator=(const Fixed &fixed)
{
    std::cout << GREEN "Copy assignment operator called\n" << RESET;
    this->integral = fixed.integral;
    return *this;
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

Fixed::~Fixed()
{
	std::cout << GREEN << "Destructor called\n" << RESET;
}