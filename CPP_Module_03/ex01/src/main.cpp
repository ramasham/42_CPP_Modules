/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rsham <rsham@student.42amman.com>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/16 17:38:19 by rsham             #+#    #+#             */
/*   Updated: 2025/06/19 15:27:33 by rsham            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"
#include <iostream>
#include "ScavTrap.hpp"

int main() {
    ClapTrap a;
    ClapTrap b("Jerry");
    ScavTrap c;
    
    a.setAttackDamage(1);
    b.setAttackDamage(3);
    c.setAttackDamage(10);
    a.attack(b.getName());
    c.attack(a.getName());
    c.guardGate();
    b.takeDamage(a.getAttackDamage());
    a.takeDamage(b.getAttackDamage());
    b.beRepaired(2);

    std::cout << "\nClapTrap Status Table:\n";
    std::cout << "---------------------------------------------------------\n";
    std::cout << "| Name     | ❤️  Hit Points | 🔋 Energy | 💥 Attack Damage|\n";
    std::cout << "---------------------------------------------------------\n";

    a.printStatus();
    b.printStatus();
    c.printStatus();

    std::cout << "---------------------------------------------------------\n";

    return 0;
}
