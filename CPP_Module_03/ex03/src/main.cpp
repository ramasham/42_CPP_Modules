/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rsham <rsham@student.42amman.com>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/16 17:38:19 by rsham             #+#    #+#             */
/*   Updated: 2025/06/22 12:25:24 by rsham            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <DiamondTrap.hpp>
#include <FragTrap.hpp>
#include <ScavTrap.hpp>


int main() {
   DiamondTrap diamo("Tom");

    std::cout << diamo.getName() << std::endl;
    std::cout << diamo.getEnergyPoints() << std::endl;
    std::cout << diamo.getHitPoints() << std::endl;
    std::cout << diamo.getAttackDamage() << std::endl;
    
    return 0;
}
