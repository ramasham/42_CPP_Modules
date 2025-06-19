    /* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   DiamondTrap.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rsham <rsham@student.42amman.com>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/18 12:37:11 by rsham             #+#    #+#             */
/*   Updated: 2025/06/18 15:30:05 by rsham            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DIAMONDTRAP_HPP
#define DIAMONDTRAP_HPP

#include "ClapTrap.hpp"
#include "FragTrap.hpp"
#include "ScavTrap.hpp"


//Variable shadowing: (name)
//one from ClapTrap(inherited)
//one in DaimondTrap

//The DiamondTrap::name shadows (hides) the ClapTrap::name — meaning,
//within DiamondTrap, if you write just name,
//it refers to its own name member, not the base class one.

class DiamondTrap : public FragTrap , public ScavTrap {
    private:
        std::string name;
    
    public:
    DiamondTrap();
    DiamondTrap(const std::string& name);
    DiamondTrap(const DiamondTrap& other);
    DiamondTrap& operator=(const DiamondTrap& other);
    ~DiamondTrap();

    void whoAmI();
    using ScavTrap::attack;
};

#endif