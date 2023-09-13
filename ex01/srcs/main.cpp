/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thibaultgiraudon <thibaultgiraudon@stud    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/13 15:24:19 by thibaultgir       #+#    #+#             */
/*   Updated: 2023/09/13 15:58:01 by thibaultgir      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Serializer.hpp"

int main()
{
    Data original_data;

    original_data.i = 42;
    original_data.c = 'C';
    original_data.d = 42.5;

	
	uintptr_t ptr = Serializer::serialize(&original_data);
	Data *serialized_data = Serializer::deserialize(ptr);

	if (&original_data == serialized_data)
	{
		std::cout << "Original_data:   " << &original_data << " | " << original_data.i << std::endl;
		std::cout << "Serialized_data: " << serialized_data << " | " << serialized_data->i << std::endl;
	}
	else 
		std::cout << "Failure" << std::endl;
	return (0);
}