/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   MutantStack.tpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tgiraudo <tgiraudo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/20 10:03:23 by tgiraudo          #+#    #+#             */
/*   Updated: 2023/09/20 10:44:20 by tgiraudo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "MutantStack.hpp"

template <typename T>
MutantStack<T>::MutantStack( void ) {
	std::cout << "[ MUTANTSTACK ] Constructor called" << std::endl;
	return ;
}

template <typename T>
MutantStack<T>::~MutantStack( void ) {
	std::cout << "[ MUTANTSTACK ] Destructor called" << std::endl;
	return ;
}

template <typename T>
MutantStack<T>::MutantStack( const MutantStack &copy ) {
	std::cout << "[ MUTANTSTACK ] Copied" << std::endl;
	*this = copy;
	return ;
}

template <typename T>
MutantStack<T>& MutantStack<T>::operator=( const MutantStack &copy ) {
	std::cout << "[ MUTANTSTACK ]  Assignement operator called" << std::endl;
	(void)copy;
	return *this;
}