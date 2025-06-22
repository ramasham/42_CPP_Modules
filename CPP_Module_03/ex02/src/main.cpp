/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rsham <rsham@student.42amman.com>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/16 17:38:19 by rsham             #+#    #+#             */
/*   Updated: 2025/06/22 12:23:50 by rsham            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"
#include <iostream>
#include "ScavTrap.hpp"
#include "FragTrap.hpp"

int main() {
    ClapTrap clap;
    ClapTrap clap1("clapy");
    ScavTrap scav;
    FragTrap frag;

    clap.setAttackDamage(1);
    clap1.setAttackDamage(3);
    scav.setAttackDamage(10);
    frag.setAttackDamage(2);

    clap.attack(clap1.getName());
    clap1.takeDamage(clap.getAttackDamage());

    scav.attack(clap.getName());
    clap.takeDamage(scav.getAttackDamage());

    scav.guardGate();

    clap.attack(clap1.getName());
    clap1.takeDamage(clap.getAttackDamage());

    frag.attack(clap.getName());
    clap.takeDamage(frag.getAttackDamage());

    frag.highFivesGuys();

    clap1.beRepaired(2);

    return 0;
}
