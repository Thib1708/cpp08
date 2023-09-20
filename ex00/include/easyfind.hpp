/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   easyfind.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thibaultgiraudon <thibaultgiraudon@stud    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/16 09:58:31 by thibaultgir       #+#    #+#             */
/*   Updated: 2023/09/16 10:18:48 by thibaultgir      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef EASYFIND_HPP
#define EASYFIND_HPP

#include <iostream>
#include <algorithm>
#include <vector>

class NotFoundException : public std::exception
{
    virtual const char* what() const throw()
    {
        return ("Value not found");
    }
};

template <typename T>
void	easyfind(T &vec, int item) {
	std::vector<int>::iterator it;

	it = std::find(vec.begin(), vec.end(), item);
	if (it != vec.end())
		std::cout << "Item found: " << *it << std::endl;
	else
		throw (NotFoundException());
	
}

#endif