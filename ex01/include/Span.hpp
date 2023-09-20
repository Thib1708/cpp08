/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Span.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thibaultgiraudon <thibaultgiraudon@stud    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/17 13:11:57 by thibaultgir       #+#    #+#             */
/*   Updated: 2023/09/16 11:28:21 by thibaultgir      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SPAN_HPP
#define SPAN_HPP

#include <iostream>
#include <algorithm>
#include <vector>


# define RESET		"\033[0m"
# define BLACK		"\033[30m"
# define RED		"\033[31m"
# define GREEN		"\033[32m"
# define YELLOW		"\033[33m"
# define BLUE		"\033[34m"
# define MAGENTA	"\033[35m"
# define CYAN		"\033[36m"
# define WHITE		"\033[37m"

class Span {
    private:
        size_t  _N;
        size_t  _index;
        std::vector<int> _vec;
    public:
        Span( void );
        Span( size_t N );
        ~Span( void );
        Span( const Span & );
        Span& operator=( const Span &);

        void    addNumber(int number);
        void    addNumber(std::vector<int>::iterator begin, std::vector<int>::iterator end);
        int     shortestSpan( void );
        int     longestSpan( void );
        class StackFullException: public std::exception {
				public :
						virtual const char	*what( void ) const throw();
		};
        class StackEmptyException: public std::exception {
				public :
						virtual const char	*what( void ) const throw();
		};
};

#endif