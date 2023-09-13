/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConvert.hpp                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thibaultgiraudon <thibaultgiraudon@stud    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/17 13:11:57 by thibaultgir       #+#    #+#             */
/*   Updated: 2023/09/13 12:21:35 by thibaultgir      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SCALARCONVERT_HPP
#define SCALARCONVERT_HPP

#include <iostream>
#include <sstream>

enum {
    CHAR,
    INT,
    FLOAT,
    DOUBLE,
    INVALID
};

class ScalarConvert {
    private:
        std::string         _str;
        unsigned long       _index;
        int                 _type;
        char    _c;
        int     _i;
        float   _f;
        double  _d;
    public:
        ScalarConvert( void );
        ~ScalarConvert( void );
        ScalarConvert( const ScalarConvert & );
        ScalarConvert& operator=( const ScalarConvert &);

        int	getType( void ) const;
        
        void    convert( std::string str );
        bool isChar( void );
        bool isInt( void );
        bool isFloat( void );
        void    printChar( void ) const;
        void    printInt( void ) const;
        void    printFloat( void ) const;
        void    printDouble( void ) const;
        // bool isDouble( std::string str );
};

std::ostream &operator<<( std::ostream &out, ScalarConvert const &convert );

#endif