/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Brain.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rsham <rsham@student.42amman.com>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/23 14:32:37 by rsham             #+#    #+#             */
/*   Updated: 2025/06/23 17:45:54 by rsham            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Brain.hpp"

Brain::Brain() {
    for (int i = 0; i < 100; ++i)  {
        ideas[i] = "empty";
    }
    std::cout << "Brain: Default constructor\n";
}

Brain::Brain(const Brain& other) {
    for (int i = 0; i < 100; ++i) {
        ideas[i] = other.ideas[i];
    }
    std::cout << "Brain: copy constructor called\n";
}

Brain& Brain::operator=(const Brain& other) {
    if (this != &other) {
        for (int i = 0; i < 100; ++i)
            ideas[i] = other.ideas[i];
    }
    std::cout << "Brain: copy assignment operator\n";
    return *this;
}

Brain::~Brain() {
    std:: cout << "Brain: destructor called\n";
}

void Brain::setIdea(int index, const std::string& idea) {
    if (index >= 0 && index < 100)
        ideas[index] = idea;
    else
        std::cerr << "Brain: Invalid index in setIdea()\n";
}

std::string Brain::getIdea(int index) const {
    if (index >= 0 && index < 100)
        return ideas[index];
    std::cerr << "Brain: Invalid index in getIdea()\n";
    return "";
}