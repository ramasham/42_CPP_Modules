/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rsham <rsham@student.42amman.com>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/11 15:30:45 by rsham             #+#    #+#             */
/*   Updated: 2025/06/15 18:36:06 by rsham            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"
#include <iostream>
#include <cmath>

// Operator overloading
std::ostream& operator<<(std::ostream& os, const Fixed& fixed) {
    os << fixed.toFloat();
    return os;
}

// Default constructor
Fixed::Fixed() : value(0) {
    std::cout << "Default constructor called" << std::endl;
}

// Copy constructor
Fixed::Fixed(const Fixed& other) {
    std::cout << "Copy constructor called" << std::endl;
    *this = other;
}

// Copy assignment operator
Fixed& Fixed::operator=(const Fixed& other) {
    std::cout << "Copy assignment operator called" << std::endl;
    if (this != &other) {
        value = other.value;
    }
    return *this;
}

// Destructor
Fixed::~Fixed() {
    std::cout << "Destructor called" << std::endl;
}

int Fixed::getRawBits(void) const {
    std::cout << "getRawBits member function called" << std::endl;
    return value;
}

void Fixed::setRawBits(int const raw) {
    value = raw;
}

//constructor int -> fixed
//value = intNbr × 2^fractionalBits = intNbr × 256
//example Fixed(10) = 2560
//get value -> real = 2560 / 256.0f = 10.0
Fixed::Fixed(const int intNbr) {
    std::cout << "Int constructor called" << std::endl;
    value = intNbr << fractionalBits;
}

//constructor float -> fixed
//((1 << fractionalBits) = 2^8 = 256
// 3.75f * 256 = 960.0
Fixed::Fixed(const float fNbr) {
    std::cout << "Float constructor called" << std::endl;
    value = static_cast<int>(roundf(fNbr * (1 << fractionalBits)));
}

//fixed -> float
float Fixed::toFloat(void) const {
    return static_cast<float>(value) / (1 << fractionalBits);
}

//fixed -> int
int Fixed::toInt(void) const {
    return value >> fractionalBits;
}
