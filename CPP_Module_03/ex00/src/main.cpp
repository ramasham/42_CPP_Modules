/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rsham <rsham@student.42amman.com>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/16 17:38:19 by rsham             #+#    #+#             */
/*   Updated: 2025/06/19 15:24:44 by rsham            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"
#include <iostream>

int main() {
    ClapTrap a;
    ClapTrap b("Jerry");

    a.setAttackDamage(1);
    b.setAttackDamage(3);
    a.attack(b.getName());
    a.attack(b.getName());
    b.takeDamage(a.getAttackDamage());
    b.attack(a.getName());
    a.attack(b.getName());
    a.takeDamage(b.getAttackDamage());
    b.beRepaired(2);

    std::cout << "\nClapTrap Status Table:\n";
    std::cout << "---------------------------------------------------------\n";
    std::cout << "| Name     | ❤️  Hit Points | 🔋 Energy | 💥 Attack Damage|\n";
    std::cout << "---------------------------------------------------------\n";

    a.printStatus();
    b.printStatus();

    std::cout << "---------------------------------------------------------\n";

    return 0;
}
