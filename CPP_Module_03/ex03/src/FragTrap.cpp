/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   FragTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rsham <rsham@student.42amman.com>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/18 12:03:00 by rsham             #+#    #+#             */
/*   Updated: 2025/06/22 13:17:22 by rsham            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "FragTrap.hpp"
#include <iostream>

FragTrap::FragTrap() : ClapTrap("fragr") {
    this->energyPoints = 100;
    this->attackDamage = 30;
    this->setHitPoints(ClapTrap::DFL_HP);
    std::cout << "FragTrap: default constructor called\n";
}

FragTrap::FragTrap(const std::string& name) : ClapTrap(name) {
    this->energyPoints = 100;
    this->attackDamage = 30;
    this->setHitPoints(ClapTrap::DFL_HP);
    std::cout << "constructor called\n";
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