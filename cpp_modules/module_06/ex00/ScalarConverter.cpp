/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConverter.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: prando-a <prando-a@student.42.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/29 17:23:32 by prando-a          #+#    #+#             */
/*   Updated: 2024/06/29 17:23:32 by prando-a         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScalarConverter.hpp"

ScalarConverter::ScalarConverter()
{
	std::cout << GREEN << "Default constructor called\n" << RESET;
}

ScalarConverter::ScalarConverter(const ScalarConverter &ScalarConverter)
{
	std::cout << GREEN << "Copy constructor called\n" << RESET;
	*this = ScalarConverter;
}

ScalarConverter &ScalarConverter::operator=(const ScalarConverter &ScalarConverter)
{
    std::cout << GREEN "Copy assignment operator called\n" << RESET;
	(void)ScalarConverter;
    return *this;
}

ScalarConverter::~ScalarConverter()
{
	std::cout << RED << "Destructor called\n" << RESET;
}


static int	float_checker(char *str, int *i, int *check)
{
	int	sym_lock;

	sym_lock = 0;
	while (str[*i])
	{
		if (str[*i] == '.')
		{
			if (sym_lock++ == 0 && str[*i + 1] >= '0' && str[*i + 1] <= '9')
				(*check)++;
		}
		if (str[*i] >= '0' && str[*i] <= '9')
			(*check)++;
		(*i)++;
	}
	if (str[*i - 1] == 'f' && ((*check + 1) == *i))
		(*check)++;
	return (sym_lock && (*check == *i));
}

static int	ft_str_islf(char *str)
{
	int	i;
	int	check;
	int	sym_lock;

	i = -1;
	check = 0;
	sym_lock = 0;
	if (!*str)
		return (0);
	while (str[++i] && str[i] != '.')
	{
		if (str[0] == '-' || str[0] == '+')
		{
			if (sym_lock++ == 0 && str[i + 1] >= '0' && str[i + 1] <= '9')
				check++;
		}
		if (str[i] >= '0' && str[i] <= '9')
			check++;
	}
	if (check == 0)
		return (0);
	return (float_checker(str, &i, &check) + (check == i));
}


void ScalarConverter::convert(char *literal)
{
	if (!literal)
	{
		std::cerr << RED << "Error: NULL argument\n" << RESET;
		return;
	}

	char c = static_cast<char>(std::atoi(literal));
	std::cout << "char: ";
	if (std::isprint(c))
		std::cout << "'" << c << "'" << std::endl;
	else if (ft_str_islf(literal) == INVALID)
		std::cout << "impossible" << std::endl;
	else
		std::cout << "Non displayable" << std::endl;


	long num = std::atol(literal);
	std::cout << "int: ";
	if (num > 2147483647 || num < -2147483648
		|| ft_str_islf(literal) == INVALID)
		std::cout << "impossible" << std::endl;
	else
		std::cout << num << std::endl;


	float f = std::atof(literal);
	std::cout << "float: ";
	if (*literal)
	{
		if (std::floor(f) == num && std::ceil(f) == num)
			std::cout << f << ".0f" << std::endl;
		else
			std::cout << f << "f" << std::endl;
	}
	else
		std::cout << "impossible" << std::endl;


	double d = std::atof(literal);
	std::cout << "double: ";
	if (*literal)
	{
		if (std::floor(d) == num && std::ceil(d) == num)
			std::cout << d << ".0" << std::endl;
		else
			std::cout << d << std::endl;
	}
	else
		std::cout << "impossible" << std::endl;
}