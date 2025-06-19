/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanA.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rsham <rsham@student.42amman.com>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/28 17:44:10 by rsham             #+#    #+#             */
/*   Updated: 2025/05/29 17:04:16 by rsham            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HUMANA_HPP
#define HUMANA_HPP

#include <string>
#include "weapon.hpp"

class HumanA {
    std::string name;
    Weapon& weapon;

    public:
    HumanA(std::string name, Weapon& WeaponRef);
    void attack () const;
};
#endif