/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tgiraudo <tgiraudo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/16 10:07:14 by thibaultgir       #+#    #+#             */
/*   Updated: 2023/10/17 12:58:05 by tgiraudo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "easyfind.hpp"

int main()
{
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
	{
		std::vector<int> vec;

		vec.push_back(1);
		vec.push_back(10);
		vec.push_back(42);
		vec.push_back(0);
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
}