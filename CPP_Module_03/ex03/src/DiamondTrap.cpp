/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   DiamondTrap.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rsham <rsham@student.42amman.com>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/18 14:07:42 by rsham             #+#    #+#             */
/*   Updated: 2025/06/22 13:15:38 by rsham            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "DiamondTrap.hpp"

//constructors
DiamondTrap::DiamondTrap(const std::string& name) 
    : ClapTrap(name + "_clap_name"), FragTrap(), ScavTrap(), name(name) {
    this->setHitPoints(FragTrap::DFL_HP);
    this->setEnergyPoints(ScavTrap::DFL_EP);
    this->setAttackDamage(FragTrap::DFL_AD);
    std::cout << "DiamondTrap: constructor called\n";
    
}

DiamondTrap::DiamondTrap() : ClapTrap("dimo_clap_name"), FragTrap(), ScavTrap(), name("Tyke") {
    this->setHitPoints(FragTrap::DFL_HP);
    this->setEnergyPoints(ScavTrap::DFL_EP);
    this->setAttackDamage(FragTrap::DFL_AD);
    std::cout << "DiamondTrap: default constructor called\n";
}

DiamondTrap::DiamondTrap(const DiamondTrap& other) : ClapTrap(other), FragTrap(other), ScavTrap(other), name(other.name) {
    std::cout << "DiamondTrap: copy constructor called\n";
}

DiamondTrap& DiamondTrap::operator=(const DiamondTrap& other) {
    std::cout << "DiamondTrap: copy assignment operator called\n";
    if (this != &other) { 
        ClapTrap::operator=(other);
        name = other.name;
    } 
    return *this;
}

DiamondTrap::~DiamondTrap() {
    std::cout << "DiamondTrap: destructor called\n";
}

//memeber functions
void DiamondTrap::whoAmI() {
    std::cout << "DiamondTrap name: " << name 
            << ", clapTrap name:" << ClapTrap::getName() << "\n";
}
