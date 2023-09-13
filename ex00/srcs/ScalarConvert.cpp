/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConvert.cpp                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thibaultgiraudon <thibaultgiraudon@stud    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/17 13:11:57 by thibaultgir       #+#    #+#             */
/*   Updated: 2023/09/13 13:15:06 by thibaultgir      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScalarConvert.hpp"

ScalarConvert::ScalarConvert( void ) {
	// std::cout << "[ SCALARCONVERT ] Constructor called" << std::endl;
	this->_index = 0;
	this->_type = INVALID;
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
	this->_index = copy._index;
	this->_type = copy._type;
	return *this;
}

int	ScalarConvert::getType( void ) const {
	return (this->_type);
}

bool ScalarConvert::isChar( void ) {
	if (this->_str.length() == 1 && ((this->_str[0] > 31 && this->_str[0] < 48) || (this->_str[0] > 57 && this->_str[0] < 127)))
	{
		this->_type = CHAR;
		return (true);
	}
	return (false);
}

bool ScalarConvert::isInt( void ) {
	this->_index = 0;
	if (this->_str[this->_index] == '+' || this->_str[this->_index] == '-')
		this->_index++;
	while (this->_str[this->_index] && std::isdigit(this->_str[this->_index]))
		this->_index++;
	if (this->_index != this->_str.length())
		return (false);
	this->_type = INT;
	return (true);
}

bool ScalarConvert::isFloat( void ) {
	if (this->_str == "nan" || this->_str == "-inf" || this->_str == "+inf" || \
		this->_str == "nanf" || this->_str == "-inff" || this->_str == "+inff" )
	{
		this->_type = STRING;
		return (true);
	}
	if (this->_str[this->_index] == '.')
	{
		this->_index++;
		while(this->_str[this->_index])
		{
			if ((this->_str[this->_index] < 48 || this->_str[this->_index] > 57) && this->_str[this->_index] != 'f')
				return (false);
			if (this->_str[this->_index] == 'f' && this->_index != this->_str.length() - 1)
				return (false);
			this->_index++;
		}
		if (this->_str[this->_index - 1] == 'f')
		{
			this->_str[this->_index - 1] = '\0';
			this->_type = FLOAT;
			return (true);
		}
		this->_type = DOUBLE;
		return (true);
	}
	if (this->_str[this->_index] == 'f' && this->_index == this->_str.length() - 1)
	{
		this->_str[this->_index] = '\0';
		this->_type = FLOAT;
		return (true);
	}
	return (false);
}

void	ScalarConvert::printChar( void ) const {
	if (this->_type == STRING)
		std::cout << "impossible" << std::endl;
	else if (this->_c < 32 || this->_c > 126)
		std::cout << "Non displayable" << std::endl;
	else
		std::cout << "'" << this->_c << "'" << std::endl;
}

void	ScalarConvert::printInt( void ) const {
	if (this->_type == STRING)
		std::cout << "impossible" << std::endl;
	else 
		std::cout << this->_i << std::endl;
}

void	ScalarConvert::printFloat( void ) const {
	if (this->_type == STRING)
	{
		if (this->_str == "nan" || this->_str == "-inf" || this->_str == "+inf")
			std::cout << this->_str << "f" << std::endl;
		else
			std::cout << this->_str << std::endl;
	}
	else if (this->_type == INT || this->_type == CHAR)
		std::cout << this->_f << ".0f" << std::endl;
	else
		std::cout << this->_f << "f" << std::endl;
}

void	ScalarConvert::printDouble( void ) const {
	if (this->_str == "nanf")
		std::cout << "nan" << std::endl;
	else if (this->_str == "-inff")
		std::cout << "-inf" << std::endl;
	else if (this->_str == "+inff")
		std::cout << "+inf" << std::endl;
	else if (this->_type == STRING)
		std::cout << this->_str << std::endl;
	else if (this->_type == INT || this->_type == CHAR)
		std::cout << this->_f << ".0" << std::endl;
	else
		std::cout << this->_d << std::endl;
}

void ScalarConvert::convert( std::string str ) {
	this->_str = str;
	if (!isChar())
		if (!isInt())
			if (!isFloat())
				this->_type = INVALID;
	std::istringstream iss(this->_str);
	switch (this->_type) {
		case CHAR: {
			this->_c = this->_str[0];
			this->_i = static_cast<int>(this->_c);
			this->_f = static_cast<float>(this->_c);
			this->_d = static_cast<double>(this->_c);
			break ;
		}
		case INT: {
			iss >> this->_i;
			this->_c = static_cast<char>(this->_i);
			this->_f = static_cast<float>(this->_i);
			this->_d = static_cast<double>(this->_i);
			break ;
		}
		case FLOAT: {
			iss >> this->_f;
			this->_c = static_cast<char>(this->_f);
			this->_i = static_cast<int>(this->_f);
			this->_d = static_cast<double>(this->_f);
			break ;
		}
		case DOUBLE: {
			iss >> this->_d;
			this->_c = static_cast<char>(this->_d);
			this->_i = static_cast<int>(this->_d);
			this->_f = static_cast<float>(this->_d);
			break ;
		}
		case STRING: {
			break ;
		}
		default: {
			break ;
		}	
	}
}

std::ostream &operator<<( std::ostream &out, ScalarConvert const &convert ) {
	if (convert.getType() == INVALID)
	{
		out << "This input makes no sense!";
		return (out);
	}
	out << "char: ";
	convert.printChar();
	out << "int: ";
	convert.printInt();
	out << "float: ";
	convert.printFloat();
	out << "double: ";
	convert.printDouble();
	return (out);
}