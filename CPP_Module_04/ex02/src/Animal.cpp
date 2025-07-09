/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Animal.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rsham <rsham@student.42amman.com>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/22 17:37:51 by rsham             #+#    #+#             */
/*   Updated: 2025/06/23 18:47:32 by rsham            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Animal.hpp"

//Constructors
Animal::Animal() : type("animal") {
    std::cout << "Animal: Default constructor\n";
}

Animal::Animal(const std::string& type) : type(type) {
    std::cout << "Animal: constructor called\n";
}

Animal::Animal(const Animal& other) : type(other.type) {
    std::cout << "Animal: Copy constructor called\n";
}

Animal& Animal::operator=(const Animal& other) {
    if (this != &other)
        type = other.type;
    std:: cout << "Animal: copy assignment operator called\n";
    return *this;
}

Animal::~Animal() {
    std::cout << "Animal: Destructor called" << std::endl;
}

std::string Animal::getType() const {
    return type;
}
