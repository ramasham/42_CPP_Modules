/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rsham <rsham@student.42amman.com>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/16 17:38:19 by rsham             #+#    #+#             */
/*   Updated: 2025/06/22 12:51:00 by rsham            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"
#include <iostream>

int main() {
    ClapTrap clap1;
    ClapTrap clap2("clapy");

    clap1.setAttackDamage(6);
    clap2.setAttackDamage(4);

    clap1.attack(clap2.getName());
    clap2.takeDamage(clap1.getAttackDamage());
    
    clap2.attack(clap1.getName());
    clap1.takeDamage(clap2.getAttackDamage());
    
    clap2.beRepaired(1);

    return 0;
}
