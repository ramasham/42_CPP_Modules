/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   FragTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rsham <rsham@student.42amman.com>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/18 12:03:00 by rsham             #+#    #+#             */
/*   Updated: 2025/06/19 15:30:44 by rsham            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "FragTrap.hpp"
#include <iostream>

FragTrap::FragTrap(const std::string& name) : ClapTrap(name) {
    std::cout << "constructor called\n";
}

FragTrap::FragTrap() : ClapTrap("Tuffy", 100, 50, 20) {
    std::cout << "FragTrap: default constructor called\n";
}

FragTrap::FragTrap(const FragTrap& other) : ClapTrap(other) {
    std::cout << "FragTrap: copy constructor called\n";
}

FragTrap& FragTrap::operator=(const FragTrap& other) {
    std::cout << "FragTrap: copy assignment operator called\n";
    if (this != &other)
        ClapTrap::operator=(other);
    return *this;
}

FragTrap::~FragTrap() {
    std::cout << "FragTrap: destructor called\n";
}

//member functions
void FragTrap::highFivesGuys() {
    std::cout << "FragTrap: " << getName() << " in high five! ✋" << std::endl;
}
