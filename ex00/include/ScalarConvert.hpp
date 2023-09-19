/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConvert.hpp                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thibaultgiraudon <thibaultgiraudon@stud    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/17 13:11:57 by thibaultgir       #+#    #+#             */
/*   Updated: 2023/09/19 17:00:20 by thibaultgir      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SCALARCONVERT_HPP
#define SCALARCONVERT_HPP

#include <iostream>
#include <sstream>
#include <stdlib.h>

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