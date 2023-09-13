/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Serializer.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thibaultgiraudon <thibaultgiraudon@stud    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/17 13:11:57 by thibaultgir       #+#    #+#             */
/*   Updated: 2023/09/13 16:00:12 by thibaultgir      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Serializer.hpp"

Serializer::Serializer( void ) {
	std::cout << "[ SERIALIZER ] Constructor called" << std::endl;
	return ;
}

Serializer::~Serializer( void ) {
	std::cout << "[ SERIALIZER ] Destructor called" << std::endl;
	return ;
}

Serializer::Serializer( const Serializer &copy ) {
	std::cout << "[ SERIALIZER ] Copied" << std::endl;
	*this = copy;
	return ;
}

Serializer& Serializer::operator=( const Serializer &copy ) {
	std::cout << "[ SERIALIZER ]  Assignement operator called" << std::endl;
	(void)copy;
	return *this;
}

uintptr_t Serializer::serialize(Data *ptr)
{
	return reinterpret_cast<uintptr_t>(ptr);
}

Data *Serializer::deserialize(uintptr_t raw)
{
	return reinterpret_cast<Data *>(raw);
}
