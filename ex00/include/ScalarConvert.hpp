/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConvert.hpp                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tgiraudo <tgiraudo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/17 13:11:57 by thibaultgir       #+#    #+#             */
/*   Updated: 2023/09/27 15:46:19 by tgiraudo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SCALARCONVERT_HPP
#define SCALARCONVERT_HPP

#include <iostream>
#include <sstream>
#include <limits>
#include <cmath>
#include <stdlib.h>

# define RESET		"\033[0m"
# define BLACK		"\033[30m"
# define RED		"\033[31m"
# define GREEN		"\033[32m"
# define YELLOW		"\033[33m"
# define BLUE		"\033[34m"
# define MAGENTA	"\033[35m"
# define CYAN		"\033[36m"
# define WHITE		"\033[37m"

enum {
    CHAR,
    INT,
    FLOAT,
    DOUBLE,
    INVALID,
    STRING
};

class ScalarConvert {
    private:

    public:
        ScalarConvert( void );
        ~ScalarConvert( void );
        ScalarConvert( const ScalarConvert & );
        ScalarConvert& operator=( const ScalarConvert &);

        static int	getType( void );
        
        static void    convert( std::string str );
        static bool isChar( std::string &str, int &type );
        static bool isInt( std::string &str, int &type, size_t &index );
        static bool isFloat( std::string &str, int &type, size_t &index );
        static void    printChar( int type, char c, int i );
        static void    printInt( int type, int i, double d );
        static void    printFloat( int type, std::string str, int i, float f, double d );
        static void    printDouble( int type, std::string str, int i, float f, double d );
        // bool isDouble( std::string str );
};

std::ostream &operator<<( std::ostream &out, ScalarConvert const &convert );

#endif