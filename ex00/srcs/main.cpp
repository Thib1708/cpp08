/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thibaultgiraudon <thibaultgiraudon@stud    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/16 10:07:14 by thibaultgir       #+#    #+#             */
/*   Updated: 2023/09/16 10:19:20 by thibaultgir      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "easyfind.hpp"

int main()
{
	std::vector<int> vec;

	for(int i = 0; i < 100; i++)
		vec.push_back(i);
	try
	{
		easyfind(vec, 0);
		easyfind(vec, 42);
		easyfind(vec, 99);
		easyfind(vec, 100);
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}
}