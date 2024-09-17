/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinExchange.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: prando-a <prando-a@student.42malaga.com>   #+#  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024-08-27 21:32:53 by prando-a          #+#    #+#             */
/*   Updated: 2024-08-27 21:32:53 by prando-a         ###   ########.com      */
/*                                                                            */
/* ************************************************************************** */

#include "BitcoinExchange.hpp"

std::string trim(std::string str)
{
	size_t first = str.find_first_not_of(" \t\n\r\f\v");
	size_t last = str.find_last_not_of(" \t\n\r\f\v");
	return str.substr(first, (last - first + 1));
}

int get_unix_time(std::string date, int input_flag)
{
    struct tm tm;
	memset(&tm, 0, sizeof(struct tm));
    if (strptime(date.c_str(), "%Y-%m-%d", &tm) == NULL)
	{
		std::cerr << RED << "Error: Bad input => " << date << RESET << "\n";
		return (-1);
	}
	int year = tm.tm_year;
	int month = tm.tm_mon;
	int day = tm.tm_mday;
	time_t t = mktime(&tm);
    if (t == -1)
	{
       	std::cerr << RED << "Error: Bad input: => " << date << RESET << "\n";
		return (-1);
    }

	if (input_flag && (year < 109 || (year == 109 && month == 0 && day == 1)))
	{
		std::cerr << RED << "Error: Too low date: => " << date << RESET << "\n";
		return (-1);
	}

	if (year != tm.tm_year || month != tm.tm_mon || day != tm.tm_mday)
	{
		std::cerr << RED << "Error: Bad input: => " << date << RESET << "\n";
		return (-1);
	}
	
	return (t);
}

void BitcoinExchange::printInfo(long long quantity, std::string date)
{

	long long u_date = get_unix_time(date, 1);
	if (u_date == -1) return;

	if (quantity < 0)
	{
		std::cerr << RED << "Error: not a positive number." << RESET << "\n";
		return;
	}
	if (quantity > 1000)
	{
		std::cerr << RED << "Error: too large a number." << RESET << "\n";
		return;
	}

	std::map<std::string, double>::iterator it = this->map.begin();
	while (it != this->map.end())
	{
		long long u_key = get_unix_time(it->first, 0);
		if (u_key == u_date)
			break;
		if (u_key > u_date)
		{
			it--;
			break;
		}
		it++;
	}

	if (it == this->map.end()) it--;
	std::cout << date << " => " << quantity << " = ";
	std::cout << quantity * map[it->first] << "\n";
}

void BitcoinExchange::parse_file(char *filename)
{
	std::ifstream file(filename);
	if (!file) throw ("MISSING input file");

	std::string line;
	std::string str;
	std::getline(file, line);
	std::stringstream ss(line);
	std::getline(ss, str, '|');
	std::getline(ss, line);
	str = trim(str);
	line = trim(line);

	if (str != "date" || line != "value")
		throw ("Bad input file");

	for (std::string line; std::getline(file, line);)
	{
		std::stringstream ss(line);
		std::string date;
		int empty_flag = !strchr(line.c_str(), '|');
		std::getline(ss, date, '|');
		std::getline(ss, line);
		long long quantity = atoll(line.c_str());
		if (empty_flag) quantity = 0;
		printInfo(quantity, date);
	}
	file.close();
}

BitcoinExchange::BitcoinExchange()
{
	std::ifstream data_file("data.csv");
	if (!data_file) throw ("MISSING data.csv");

	std::string line;
	std::string str;
	std::getline(data_file, line);
	std::stringstream ss(line);
	std::getline(ss, str, ',');
	std::getline(ss, line);
	str = trim(str);
	line = trim(line);

	if (str != "date" || line != "exchange_rate")
		throw ("Bad data.csv");

	for (std::string line; std::getline(data_file, line);)
	{
		std::string key;
		double value;
		std::stringstream ss(line);
		std::getline(ss, key, ',');
		std::getline(ss, line);
		value = strtod(line.c_str(), NULL);
		this->map[key] = value;
	}
	data_file.close();
}

void BitcoinExchange::printMap()
{
	std::cout << std::fixed << std::setprecision(2);
	for (std::map<std::string, double>::iterator it = this->map.begin(); it != this->map.end(); it++)
	{
		std::cout << it->first << " : " << it->second << "\n";
	}
}

BitcoinExchange::BitcoinExchange(const BitcoinExchange &BitcoinExchange)
{
	std::cout << GREEN << "Copy constructor called\n" << RESET;
	*this = BitcoinExchange;
}

BitcoinExchange &BitcoinExchange::operator=(const BitcoinExchange &BitcoinExchange)
{
    std::cout << GREEN "Copy assignment operator called\n" << RESET;
    return *this;
}

BitcoinExchange::~BitcoinExchange()
{

}