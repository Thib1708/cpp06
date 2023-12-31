/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thibaultgiraudon <thibaultgiraudon@stud    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/13 09:46:34 by thibaultgir       #+#    #+#             */
/*   Updated: 2023/09/19 16:53:21 by thibaultgir      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScalarConvert.hpp"

int main(int argc, char **argv)
{
	if (argc != 2)
	{
		return (std::cout << "Error: <usage> : ./convert <char, int, float, double>" << std::endl, 1);
	}
	ScalarConvert convert;
	convert.convert(argv[1]);
	return (0);
}