/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rsham <rsham@student.42amman.com>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/23 12:09:25 by rsham             #+#    #+#             */
/*   Updated: 2025/06/23 12:45:25 by rsham            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Animal.hpp"
#include "Dog.hpp"

Dog::Dog() : Animal("Dog") {
    std::cout << "Dog: Default constructor\n";
}

Dog::Dog(const Dog& other) : Animal(other) {
    std::cout << "Dog: copy constructor\n";
}

Dog&Dog::operator=(const Dog& other) {
    std::cout << "Dog: copy assignment operator\n";
    if (this != &other)
        Animal::operator=(other);
    return *this;
}

Dog::~Dog() {
    std::cout << "Dog: Destructor" << std::endl;
}

void Dog::makeSound() const {
    std::cout << "bark bark!\n";
}