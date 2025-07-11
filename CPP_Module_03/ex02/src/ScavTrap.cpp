/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScavTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rsham <rsham@student.42amman.com>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/17 18:23:00 by rsham             #+#    #+#             */
/*   Updated: 2025/06/22 13:09:06 by rsham            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScavTrap.hpp"

//constructors
ScavTrap::ScavTrap(const std::string& name) : ClapTrap(name) {
    this->energyPoints = 50;
    this->attackDamage = 20;
    this->setAttackDamage(ClapTrap::DFL_HP);
    std::cout << "ScavTrap: constructor called\n";
}

ScavTrap::ScavTrap() : ClapTrap("scavr") {
    this->energyPoints = 50;
    this->attackDamage = 20;
    this->setHitPoints(ClapTrap::DFL_HP);
    std::cout << "FragTrap: default constructor called\n";
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
void ScavTrap::attack(const std::string& target) {
    if (hitPoints <= 0 || energyPoints <= 0) {
        std::cout << "ScavTrap: " << name << " cannot attack!. Not enough hit points or energy 🪫 .\n";
        return ;
    }
    energyPoints--;
    std::cout << "ScavTrap: " << name << " attacks 💣 " << target << ", causing "
                << attackDamage << " points of damage! 💥 \n";
    std::cout << "ScavTrap: " << name << " energy points left " << energyPoints << " points! \n"; 
}

void ScavTrap::guardGate() {
    std::cout << "ScavTrap: " << getName() << " in gate keeper mode 🏠 \n";
}
