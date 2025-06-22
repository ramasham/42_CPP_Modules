/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ClapTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rsham <rsham@student.42amman.com>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/16 12:45:07 by rsham             #+#    #+#             */
/*   Updated: 2025/06/22 13:09:33 by rsham            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"
#include <iostream>
#include <iomanip> 

//constructors
ClapTrap::ClapTrap() : name("clapr"), hitPoints(10), energyPoints(10), attackDamage(0) {
    std::cout << "ClapTrap: Default constructor called\n";
}

ClapTrap::ClapTrap(const std::string& name) : name(name), hitPoints(10), energyPoints(10), attackDamage(0) {
}

ClapTrap::~ClapTrap() {
    std::cout << "ClapTrap: destructor called" << std::endl;
}

ClapTrap::ClapTrap(const ClapTrap& other) : name(other.name), hitPoints(other.hitPoints),
      energyPoints(other.energyPoints), attackDamage(other.attackDamage) {
    std::cout << "ClapTrap: Copy constructor called" << std::endl;
}

ClapTrap& ClapTrap::operator=(const ClapTrap& other) {
    std::cout << "ClapTrap: Copy assignment operator called" << std::endl;
    if (this != &other)
    {
        name = other.name;
        hitPoints = other.hitPoints;
        energyPoints = other.energyPoints;
        attackDamage = other.attackDamage;
    }
    return *this;
}

//setters and getters
void ClapTrap::setName(const std::string& name) {
    this->name = name;
}

void ClapTrap::setHitPoints(int points) {
    hitPoints = points;
}

void ClapTrap::setEnergyPoints(int points) {
    energyPoints = points;
}

void ClapTrap::setAttackDamage(int damage) { 
    if (damage < 0)
        damage = 0;
    attackDamage = damage;
    
}

int ClapTrap::getAttackDamage() const {
    return attackDamage;
}

std::string ClapTrap::getName() const {
    return name;
}

void ClapTrap::attack(const std::string& target) {
    if (hitPoints <= 0 || energyPoints <= 0) {
        std::cout << "ClapTrap: " << name << " cannot attack!. Not enough hit points or energy 🪫 .\n";
        return ;
    }
    energyPoints--;
    std::cout << "ClapTrap: " << name << " attacks 💣 " << target << ", causing "
                << attackDamage << " points of damage! 💥 \n";
    std::cout << "ClapTrap: " << name << " energy points left " << energyPoints << " points! \n"; 
}

void ClapTrap::takeDamage(unsigned int amount) {
    if (amount >= static_cast<unsigned int>(hitPoints))
        hitPoints = 0;
    else
        hitPoints -= amount;
    std::cout << "ClapTrap: " << name << " Hit points ❤️  : " << hitPoints << " points! \n";
   std::cout << "ClapTrap: " << name << " takes " 
            << amount << " points of damage!" << std::endl;
}

void ClapTrap::beRepaired(unsigned int amount) {
    if (hitPoints <= 0 || energyPoints <= 0) {
        std::cout << "ClapTrap: " << name << " cannot repair!. Not enough hit points or energy 🪫 .\n";
        return;
    }
    hitPoints += amount;
    std::cout << "ClapTrap: " << name << " Hit points ❤️  : " << hitPoints << " points! \n";
    if (hitPoints > 10)
        hitPoints = 10;
    energyPoints--;
    std::cout << "ClapTrap: " << name << " Energy points left " << energyPoints << " points 🪫 \n"; 
    std::cout << "ClapTrap: " << name << " is repaired by " 
            << amount << " points! 🔋 " << std::endl;
}

