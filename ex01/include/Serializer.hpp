/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Serializer.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tgiraudo <tgiraudo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/17 13:11:57 by thibaultgir       #+#    #+#             */
/*   Updated: 2023/09/27 16:04:38 by tgiraudo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SERIALIZER_HPP
#define SERIALIZER_HPP

#include <iostream>
#include <stdint.h>

struct Data
{
    int     i;
    char    c;
    double    d;
};


class Serializer {
    private:
        
    public:
        Serializer( void );
        ~Serializer( void );
        Serializer( const Serializer & );
        Serializer& operator=( const Serializer &);

        static uintptr_t serialize(Data* ptr);
        static Data* deserialize(uintptr_t raw);;
};

#endif