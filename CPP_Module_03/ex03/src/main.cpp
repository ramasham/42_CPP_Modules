/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rsham <rsham@student.42amman.com>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/16 17:38:19 by rsham             #+#    #+#             */
/*   Updated: 2025/06/19 15:16:22 by rsham            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <DiamondTrap.hpp>
#include <FragTrap.hpp>
#include <ScavTrap.hpp>

void testCase()
{
    DiamondTrap o("Tom");

    std::cout << o.getName() << std::endl;
    std::cout << o.getEnergyPoints() << std::endl;
    std::cout << o.getHitPoints() << std::endl;
    std::cout << o.getAttackDamage() << std::endl;
}

int main() {
    ClapTrap t;
    ClapTrap j("Jerry");
    ScavTrap s;
    FragTrap f;
    DiamondTrap d;    
    
    t.setAttackDamage(1);
    j.setAttackDamage(3);
    s.setAttackDamage(10);
    f.setAttackDamage(2);
    d.setAttackDamage(50);
    
    t.attack(j.getName());
    j.attack(t.getName());
    f.attack(t.getName());
    s.guardGate();
    d.whoAmI();
    f.highFivesGuys();
    j.takeDamage(t.getAttackDamage());

    j.attack(t.getName());
    t.attack(j.getName());
    t.takeDamage(j.getAttackDamage());

    j.beRepaired(2);

    std::cout << "\nClapTrap Status Table:\n";
    std::cout << "----------------------------------------------------------------\n";
    std::cout << "| Name            | ❤️  Hit Points | 🔋 Energy | 💥 Attack Damage|\n";
    std::cout << "----------------------------------------------------------------\n";

    t.printStatus();
    j.printStatus();
    s.printStatus();
    f.printStatus();
    d.printStatus();

    std::cout << "----------------------------------------------------------------\n";

    // testCase();
    return 0;
}
