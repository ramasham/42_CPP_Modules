/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rsham <rsham@student.42amman.com>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/15 15:12:20 by rsham             #+#    #+#             */
/*   Updated: 2025/06/15 18:20:49 by rsham            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FIXED_HPP
#define FIXED_HPP

#include <iostream>

class Fixed {
    private:
        int value;
        static const int fractionalBits = 8;
        
    public:
        Fixed();
        Fixed(const int intNbr);
        Fixed(const float fNbr);
        Fixed(const Fixed& other);
        Fixed& operator=(const Fixed& other);
        ~Fixed();

        int getFixed() const;
        
        Fixed operator+(const Fixed& other) const;
        Fixed operator*(const Fixed& other) const;
        Fixed operator/(const Fixed& other) const;
        Fixed operator-(const Fixed& other) const;

        bool operator>(const Fixed& other) const;
        bool operator<(const Fixed& other) const;
        bool operator>=(const Fixed& other) const;
        bool operator<=(const Fixed& other) const;
        bool operator==(const Fixed& other) const;
        bool operator!=(const Fixed& other) const;

        Fixed& operator++();       // pre-increment (++x)
        Fixed operator++(int);     // post-increment (x++)
        Fixed& operator--();       // pre-decrement (--x)
        Fixed operator--(int);     // post-decrement (x--)
        
        static Fixed& min(Fixed& a, const Fixed& b);
        static Fixed& max(Fixed& a, const Fixed& b);
        float toFloat(void) const;
        int toInt(void) const;
        
};

std::ostream& operator<<(std::ostream& os, const Fixed& fixed);

#endif