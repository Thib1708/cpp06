/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thibaultgiraudon <thibaultgiraudon@stud    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/13 16:10:33 by thibaultgir       #+#    #+#             */
/*   Updated: 2023/09/19 17:51:35 by thibaultgir      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Base.hpp"

Base * generate( void ) {
	srand (time(NULL));

	int rand_num;

	rand_num = rand() % 3 + 1;
	switch(rand_num) {
		case 1: {
			std::cout << "Create class A" << std::endl;
			return (new A);
		}
		case 2: {
			std::cout << "Create class B" << std::endl;
			return (new B);
		}
		case 3: {
			std::cout << "Create class C" << std::endl;
			return (new C);
		}
	}
	return(NULL);
}

void	identify(Base* p)
{
	try
	{
		if (dynamic_cast<A *>(p))
			std::cout << "Base type is A" << std::endl;
	}
	catch(std::exception& e){}
	try
	{
		if (dynamic_cast<B *>(p))
			std::cout << "Base type is B" << std::endl;
	}
	catch(std::exception& e){}
	try
	{
		if (dynamic_cast<C *>(p))
			std::cout << "Base type is C" << std::endl;
	}
	catch(std::exception& e){}
	
	
	// if(dynamic_cast<A *>(p))
	// 	std::cout << "Base type is A" << std::endl;
	// else if(dynamic_cast<B *>(p))
	// 	std::cout << "Base type is B" << std::endl;
	// else if(dynamic_cast<C *>(p))
	// 	std::cout << "Base type is C" << std::endl;
}

void	identify(Base& p)
{
	if(dynamic_cast<A *>(&p))
		std::cout << "Base type is A" << std::endl;
	if(dynamic_cast<B *>(&p))
		std::cout << "Base type is B" << std::endl;
	if(dynamic_cast<C *>(&p))
		std::cout << "Base type is C" << std::endl;
}

int main()
{
	Base *rand_base = generate();
	identify(*rand_base);
	identify(rand_base);
	delete rand_base;
}