/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rsham <rsham@student.42amman.com>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/22 17:49:26 by rsham             #+#    #+#             */
/*   Updated: 2025/06/23 17:46:11 by rsham            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Cat.hpp"

Cat::Cat() : Animal("Cat") {
    brain = new Brain();
    std::cout << "Cat: Default constructors\n";
}

Cat::Cat(const Cat& other) : Animal(other) {
    brain = new Brain(*other.brain);
    std::cout << "Cat: Copy constructor called\n";
}

Cat& Cat::operator=(const Cat& other) {
    if (this != &other) {
        Animal::operator=(other);
        if (brain)
        delete brain;
        brain = new Brain(*other.brain);
    }
    std::cout << "Cat: Copy assignment operator\n";
    return *this;
}

Cat::~Cat() {
    delete brain;
    std::cout << "Cat: Destructor" << std::endl;
}

void Cat::makeSound() const {
    std::cout << "meow meow!\n";    
}

void Cat::setIdea(int index, const std::string& idea) {
    if (brain)
        brain->setIdea(index, idea);
}

std::string Cat::getIdea(int index) const {
    if (brain)
        return brain->getIdea(index);
    return "";
}
