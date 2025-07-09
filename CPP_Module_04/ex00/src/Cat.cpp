/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rsham <rsham@student.42amman.com>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/22 17:49:26 by rsham             #+#    #+#             */
/*   Updated: 2025/06/23 12:45:20 by rsham            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Cat.hpp"

Cat::Cat() : Animal("Cat") {
    std::cout << "Cat: Default constructors\n";
}

Cat::Cat(const Cat& other) : Animal(other) {
    std::cout << "Cat: Copy constructor called\n";
}

Cat&Cat::operator=(const Cat& other) {
    std::cout << "Cat: Copy assignment operator\n";
    if (this != &other)
        Animal::operator=(other);
    return *this;
}

Cat::~Cat() {
    std::cout << "Cat: Destructor" << std::endl;
}

void Cat::makeSound() const {
    std::cout << "meow meow!\n";    
}
