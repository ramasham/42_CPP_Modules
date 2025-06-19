/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScavTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rsham <rsham@student.42amman.com>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/17 18:23:00 by rsham             #+#    #+#             */
/*   Updated: 2025/06/19 15:28:14 by rsham            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScavTrap.hpp"

//constructors
ScavTrap::ScavTrap() : ClapTrap("Spike") {
    std::cout << "ScavTrap: default constructor called\n";
    setHitPoints(100);
    setEnergyPoints(50);
    setAttackDamage(20);  
}

ScavTrap::ScavTrap(const std::string& name) : ClapTrap(name) {
    std::cout << "constructor called\n";
}

ScavTrap::~ScavTrap() {
    std::cout << "ScavTrap: destructor called\n";
}

ScavTrap::ScavTrap(const ScavTrap& other) : ClapTrap(other) {
    std::cout << "ScavTrap: copy constructor called\n";
}

ScavTrap& ScavTrap::operator=(const ScavTrap& other) {
    std::cout << "ScavTrap: copy assignment operator called\n";
    if (this != &other) {
        ClapTrap::operator=(other);
    }
    return *this;
}

//member functions
void ScavTrap::guardGate() {
    std::cout << "ScavTrap is now in gate keeper mode 🏠 \n";
}