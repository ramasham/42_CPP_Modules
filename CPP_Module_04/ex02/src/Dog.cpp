/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rsham <rsham@student.42amman.com>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/23 12:09:25 by rsham             #+#    #+#             */
/*   Updated: 2025/06/23 17:46:02 by rsham            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Animal.hpp"
#include "Dog.hpp"

Dog::Dog() : Animal("Dog") {
    brain = new Brain();
    std::cout << "Dog: Default constructor\n";
}

Dog::Dog(const Dog& other) : Animal(other) {
    brain = new Brain(*other.brain);
    std::cout << "Dog: copy constructor\n";
}

Dog&Dog::operator=(const Dog& other) {
    std::cout << "Dog: copy assignment operator\n";
    if (this != &other) {
        Animal::operator=(other);
        if (brain)
            delete brain;
        brain = new Brain(*other.brain);
    }
    return *this;
}

Dog::~Dog() {
    delete brain;
    std::cout << "Dog: Destructor" << std::endl;
}

void Dog::makeSound() const {
    std::cout << "woof woof!\n";
}

void Dog::setIdea(int index, const std::string& idea) {
    if (brain)
        brain->setIdea(index, idea);
}

std::string Dog::getIdea(int index) const {
    if (brain)
        return brain->getIdea(index);
    return "";
}

