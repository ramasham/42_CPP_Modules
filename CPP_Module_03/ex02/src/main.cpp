/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rsham <rsham@student.42amman.com>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/16 17:38:19 by rsham             #+#    #+#             */
/*   Updated: 2025/06/19 15:31:04 by rsham            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"
#include <iostream>
#include "ScavTrap.hpp"
#include "FragTrap.hpp"

int main() {
    ClapTrap t;
    ClapTrap j("Jerry");
    ScavTrap s;
    FragTrap f;
    
    t.setAttackDamage(1);
    j.setAttackDamage(3);
    s.setAttackDamage(10);
    f.setAttackDamage(2);
    
    t.attack(j.getName());
    s.attack(t.getName());
    s.guardGate();
    t.attack(j.getName());
    f.attack(t.getName());
    f.highFivesGuys();
    j.takeDamage(t.getAttackDamage());
    t.takeDamage(j.getAttackDamage());
    j.beRepaired(2);

    std::cout << "\nClapTrap Status Table:\n";
    std::cout << "---------------------------------------------------------\n";
    std::cout << "| Name     | ❤️  Hit Points | 🔋 Energy | 💥 Attack Damage|\n";
    std::cout << "---------------------------------------------------------\n";

    t.printStatus();
    j.printStatus();
    s.printStatus();
    f.printStatus();

    std::cout << "---------------------------------------------------------\n";

    return 0;
}
