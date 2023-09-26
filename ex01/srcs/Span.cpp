/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Span.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tgiraudo <tgiraudo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/17 13:11:57 by thibaultgir       #+#    #+#             */
/*   Updated: 2023/09/26 13:14:04 by tgiraudo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Span.hpp"

Span::Span( void ): _N(0) {
	std::cout << "[ SPAN ] Constructor called" << std::endl;
	return ;
}

Span::Span( size_t N ) {
	std::cout << "[ SPAN ] Constructor called" << std::endl;
	this->_N = N;
	return ;
}

Span::~Span( void ) {
	std::cout << "[ SPAN ] Destructor called" << std::endl;
	return ;
}

Span::Span( const Span &copy ) {
	std::cout << "[ SPAN ] Copied" << std::endl;
	*this = copy;
	return ;
}

Span& Span::operator=( const Span &copy ) {
	std::cout << "[ SPAN ]  Assignement operator called" << std::endl;
	this->_N = copy._N;
	this->_vec = copy._vec;
	return *this;
}

void	Span::addNumber( int number ) {
	if (this->_vec.size() < this->_N)
		this->_vec.push_back(number);
	else
		throw(StackFullException());
}


void    Span::addNumber(std::vector<int>::iterator begin, std::vector<int>::iterator end)
{
	while (begin != end)
	{
		this->_vec.push_back(*begin);
		if (this->_vec.size() > this->_N)
			throw (StackFullException());
		++begin;
	}
}

int	Span::longestSpan( void ) {
	std::vector<int> tmp_vec = this->_vec;
	if (this->_vec.size() < 2)
		throw(StackEmptyException());
	else
	{
		std::sort(tmp_vec.begin(), tmp_vec.end());
		return(tmp_vec[this->_N - 1] - tmp_vec[0]);
	}
}

int	Span::shortestSpan( void ) {
	std::vector<int> tmp_vec = this->_vec;
	int min;
	if (this->_vec.size() < 2)
		throw(StackEmptyException());
	else
	{
		std::sort(tmp_vec.begin(), tmp_vec.end());
		min = tmp_vec[1] - tmp_vec[0];
		for (size_t i(1); i < this->_vec.size() - 1; i++)
		{
			if (tmp_vec[i + 1] - tmp_vec[i] < min)
				min = tmp_vec[i + 1] - tmp_vec[i];
		}
	}
	return (min);
}

void	Span::print( void ) {
	std::vector<int>::iterator it = this->_vec.begin();
	for (it = this->_vec.begin(); it != this->_vec.end(); ++it)
		std::cout << *it << std::endl;
}

const char *Span::StackFullException::what(void) const throw()
{
	return ("Error: tab is full: can't add more integer");
}

const char *Span::StackEmptyException::what(void) const throw()
{
	return ("Error: tab isn't enought filled");
}