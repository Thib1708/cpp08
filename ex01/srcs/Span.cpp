/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Span.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thibaultgiraudon <thibaultgiraudon@stud    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/17 13:11:57 by thibaultgir       #+#    #+#             */
/*   Updated: 2023/09/20 14:30:24 by thibaultgir      ###   ########.fr       */
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
    if (this->_vec.size() + std::distance(begin, end) > this->_N)
        throw (StackFullException());
    this->_vec.insert(this->_vec.end(), begin, end);
}

int	Span::longestSpan( void ) {
	if (this->_vec.size() < 2)
		throw(StackEmptyException());
	else
	{
		std::sort(this->_vec.begin(), this->_vec.end());
		return(this->_vec[this->_N - 1] - this->_vec[0]);
	}
}

int	Span::shortestSpan( void ) {
	int min;
	if (this->_vec.size() < 2)
		throw(StackEmptyException());
	else
	{
		std::sort(this->_vec.begin(), this->_vec.end());
		min = this->_vec[1] - this->_vec[0];
		for (size_t i(1); i < this->_vec.size() - 1; i++)
		{
			if (this->_vec[i + 1] - this->_vec[i] < min)
				min = this->_vec[i + 1] - this->_vec[i];
		}
	}
	return (min);
}

const char *Span::StackFullException::what(void) const throw()
{
	return ("Error: tab is full: can't add more integer");
}

const char *Span::StackEmptyException::what(void) const throw()
{
	return ("Error: tab isn't enought filled");
}