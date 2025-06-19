/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanB.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rsham <rsham@student.42amman.com>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/28 18:44:01 by rsham             #+#    #+#             */
/*   Updated: 2025/05/29 15:20:08 by rsham            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HUMANB_HPP
#define HUMANB_HPP

#include <string>
#include "weapon.hpp"

class HumanB {
    std::string name;
    Weapon* weapon;

    public:
    HumanB(std::string name);
    void setWeapon(Weapon& newWeapon);
    void attack() const;
};
#endif