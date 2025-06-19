/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rsham <rsham@student.42amman.com>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/15 15:17:22 by rsham             #+#    #+#             */
/*   Updated: 2025/06/15 18:34:29 by rsham            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"
#include <iostream>
#include <cmath>

//default constructor
Fixed::Fixed() : value(0) {
    std::cout << "Default constructor called" << std::endl;
}

//Copy constructor
Fixed::Fixed(const Fixed& other) : value(other.value) {
    std::cout << "Copy constructor called" << std::endl;
    *this = other;
}

//Copy assignment operator
Fixed& Fixed::operator=(const Fixed& other) {
    std::cout << "Copy assignment operator called" << std::endl;
    if (this != &other) {
        value = other.value;
    }
    return *this;
}

//destructor
Fixed::~Fixed() {
    std::cout << "Destructor called" << std::endl;
}

//overload of the insertion («)
std::ostream& operator<<(std::ostream& os, const Fixed& fixed) {
    os << fixed.toFloat();
    return os;
}

//getter
int Fixed::getFixed() const {
    return value;
}

//arithmetic operators
Fixed Fixed::operator+(const Fixed& other) const {
    return Fixed(this->toFloat() + other.toFloat());
}

Fixed Fixed::operator-(const Fixed& other) const {
    return Fixed(this->toFloat() - other.toFloat());
}

Fixed Fixed::operator*(const Fixed& other) const {
    return Fixed(this->toFloat() * other.toFloat());
}

Fixed Fixed::operator/(const Fixed& other) const {
    return Fixed(this->toFloat() / other.toFloat());
}

// comparison operators
bool Fixed::operator>(const Fixed& other) const {
    return this->value > other.value;
}

bool Fixed::operator<(const Fixed& other) const {
    return this->value < other.value;
}

bool Fixed::operator>=(const Fixed& other) const {
    return this->value >= other.value;
}

bool Fixed::operator<=(const Fixed& other) const {
    return this->value <= other.value;
}

bool Fixed::operator==(const Fixed& other) const {
    return this->value == other.value;
}

bool Fixed::operator!=(const Fixed& other) const {
    return this->value != other.value;
}

//pre-increment and post-increment
Fixed& Fixed::operator++() {
    value++;
    return *this;
}

Fixed Fixed::operator++(int) {
    Fixed temp = *this;
    ++value;
    return temp;
}

Fixed& Fixed::operator--() {
    value--;
    return *this;
}

Fixed Fixed::operator--(int) {
    Fixed temp = *this;
    --value;
    return temp;
}

//conversions
float Fixed::toFloat(void) const {
    return static_cast<float>(value) / (1 << fractionalBits);
}

int Fixed::toInt() const {
    return value >> fractionalBits;
}

Fixed::Fixed(const int intNbr) {
    std::cout << "Int constructor called" << std::endl;
    value = intNbr << fractionalBits;
}

Fixed::Fixed(const float fNbr) {
    std::cout << "Float constructor called" << std::endl;
    value = static_cast<int>(roundf(fNbr * (1 << fractionalBits)));
}

// overloaded member functions
Fixed& Fixed::min(Fixed& a, const Fixed& b) {
    if (a < b)
        return a;
    else
        return const_cast<Fixed&>(b);
}

Fixed& Fixed::max(Fixed& a, const Fixed& b) {
    if (a > b)
        return a;
    else
        return const_cast<Fixed&>(b);
}
