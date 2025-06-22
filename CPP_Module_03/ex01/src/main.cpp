/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rsham <rsham@student.42amman.com>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/16 17:38:19 by rsham             #+#    #+#             */
/*   Updated: 2025/06/22 12:46:31 by rsham            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"
#include "ScavTrap.hpp"

int main() {
    ClapTrap clap;
    ClapTrap clap1("clapy");
    ScavTrap scav;

    clap.setAttackDamage(1);
    clap1.setAttackDamage(3);
    scav.setAttackDamage(10);

    clap.attack(clap1.getName());
    clap1.takeDamage(clap.getAttackDamage());

    scav.attack(clap.getName());
    clap.takeDamage(scav.getAttackDamage());

    scav.guardGate();

    clap.attack(clap1.getName());
    clap1.takeDamage(clap.getAttackDamage());

    clap1.beRepaired(2);

    return 0;
}
