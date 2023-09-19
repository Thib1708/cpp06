/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConvert.cpp                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thibaultgiraudon <thibaultgiraudon@stud    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/17 13:11:57 by thibaultgir       #+#    #+#             */
/*   Updated: 2023/09/19 17:01:47 by thibaultgir      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScalarConvert.hpp"

ScalarConvert::ScalarConvert( void ) {
	// std::cout << "[ SCALARCONVERT ] Constructor called" << std::endl;
	return ;
}

ScalarConvert::~ScalarConvert( void ) {
	// std::cout << "[ SCALARCONVERT ] Destructor called" << std::endl;
	return ;
}

ScalarConvert::ScalarConvert( const ScalarConvert &copy ) {
	std::cout << "[ SCALARCONVERT ] Copied" << std::endl;
	*this = copy;
	return ;
}

ScalarConvert& ScalarConvert::operator=( const ScalarConvert &copy ) {
	std::cout << "[ SCALARCONVERT ]  Assignement operator called" << std::endl;
	(void)copy;
	return *this;
}

bool ScalarConvert::isChar( std::string &str, int &type ) {
	if (str.length() == 1 && ((str[0] > 31 && str[0] < 48) || (str[0] > 57 && str[0] < 127)))
	{
		type = CHAR;
		return (true);
	}
	return (false);
}

bool ScalarConvert::isInt( std::string &str, int &type, size_t &index ) {
	index = 0;
	if (str[index] == '+' || str[index] == '-')
		index++;
	while (str[index] && std::isdigit(str[index]))
		index++;
	if (index != str.length())
		return (false);
	type = INT;
	return (true);
}

bool ScalarConvert::isFloat( std::string &str, int &type, size_t &index ) {
	if (str == "nan" || str == "-inf" || str == "+inf" || \
		str == "nanf" || str == "-inff" || str == "+inff" )
	{
		type = STRING;
		return (true);
	}
	if (str[index] == '.')
	{
		index++;
		while(str[index])
		{
			if ((str[index] < 48 || str[index] > 57) && str[index] != 'f')
				return (false);
			if (str[index] == 'f' && index != str.length() - 1)
				return (false);
			index++;
		}
		if (str[index - 1] == 'f')
		{
			str[index - 1] = '\0';
			type = FLOAT;
			return (true);
		}
		type = DOUBLE;
		return (true);
	}
	if (str[index] == 'f' && index == str.length() - 1)
	{
		str[index] = '\0';
		type = FLOAT;
		return (true);
	}
	return (false);
}

void	ScalarConvert::printChar( int type, char c, int i ) {
	if (type == STRING)
		std::cout << "impossible" << std::endl;
	else if (i < 32 || i > 126)
		std::cout << "Non displayable" << std::endl;
	else
		std::cout << "'" << c << "'" << std::endl;
}

void	ScalarConvert::printInt( int type, int i, double d ) {
	if (type == STRING)
		std::cout << "impossible" << std::endl;
	else if (d != i)
		std::cout << "overflow" << std::endl;
	else 
		std::cout << i << std::endl;
}

void	ScalarConvert::printFloat( int type, std::string str, int i, float f, double d ) {
	if (type == STRING)
	{
		if (str == "nan" || str == "-inf" || str == "+inf")
			std::cout << str << "f" << std::endl;
		else
			std::cout << str << std::endl;
	}
	else if (d != f)
		std::cout << "overflow" << std::endl;
	else if (f - i == 0)
		std::cout << f << ".0f" << std::endl;
	else
		std::cout << f << "f" << std::endl;
}

void	ScalarConvert::printDouble( int type, std::string str, int i, float f, double d ) {
	if (str == "nanf")
		std::cout << "nan" << std::endl;
	else if (str == "-inff")
		std::cout << "-inf" << std::endl;
	else if (str == "+inff")
		std::cout << "+inf" << std::endl;
	else if (type == STRING)
		std::cout << str << std::endl;
	else if (d - i == 0)
		std::cout << f << ".0" << std::endl;
	else
		std::cout << d << std::endl;
}

void ScalarConvert::convert( std::string str ) {
	int type;
	size_t index = 0;
	char c;
	int i;
	float f;
	double d;
	if (!isChar(str, type))
		if (!isInt(str, type, index))
			if (!isFloat(str, type, index))
				type = INVALID;
	std::istringstream iss(str);
	switch (type) {
		case CHAR: {
			c = str[0];
			i = static_cast<int>(c);
			f = static_cast<float>(c);
			d = static_cast<double>(c);
			break ;
		}
		case INT: {
			iss >> d;
			c = static_cast<char>(d);
			i = static_cast<int>(d);
			f = static_cast<float>(d);
			if (d != i)
			{
				std::cout << "[ ERROR ] : int overflow" << std::endl;
				return ;
			}
			break ;
		}
		case FLOAT: {
			iss >> d;
			c = static_cast<char>(d);
			i = static_cast<int>(d);
			f = static_cast<float>(d);
			if (d != f)
			{
				std::cout << "[ ERROR ] : float overflow" << std::endl;
				return ;
			}
			break ;
		}
		case DOUBLE: {
			iss >> d;
			c = static_cast<char>(d);
			i = static_cast<int>(d);
			f = static_cast<float>(d);
			double d1 = std::strtod(str.c_str(), NULL);
			if (d1 == HUGE_VAL)
			{
				std::cout << "[ ERROR ] : double overflow" << std::endl;
				return ;
			}
			break ;
		}
		case STRING: {
			break ;
		}
		default: {
			break ;
		}	
	}
	if (type == INVALID)
		return ;
	std::cout << "char: ";
	ScalarConvert::printChar(type, c, i);
	std::cout << "int: ";
	ScalarConvert::printInt(type, c, i);
	std::cout << "float: ";
	ScalarConvert::printFloat(type, str, i, f, d);
	std::cout << "double: ";
	ScalarConvert::printDouble(type, str, i, f, d);
}
