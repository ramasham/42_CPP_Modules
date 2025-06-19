/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanA.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rsham <rsham@student.42amman.com>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/29 15:11:46 by rsham             #+#    #+#             */
/*   Updated: 2025/05/29 17:05:29 by rsham            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "HumanA.hpp"
#include <string>
#include <iostream>

HumanA::HumanA(std::string name, Weapon& weaponRef) : name(name), weapon(weaponRef)
{
    
}

void HumanA::attack() const{
    std::cout << name << " attacks with their " << weapon.getType() << std::endl;
}