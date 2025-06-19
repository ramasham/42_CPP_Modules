/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ClapTrap.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rsham <rsham@student.42amman.com>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/16 12:37:38 by rsham             #+#    #+#             */
/*   Updated: 2025/06/18 12:06:24 by rsham            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CLAPTRAP_HPP
# define CLAPTRAP_HPP

#include <string>

class ClapTrap {
    private:
        std::string name;
        int hitPoints;
        int energyPoints;
        int attackDamage;
        
    protected:
        ClapTrap(const std::string& name, int hp, int ep, int ad);
        
    public:
        ClapTrap();
        ClapTrap(const std::string& name);
        ClapTrap(const ClapTrap& other);
        ClapTrap& operator=(const ClapTrap& other);
        ~ClapTrap();
        
        void attack(const std::string& target);
        void takeDamage(unsigned int amount);
        void beRepaired(unsigned int amount);

        void setHitPoints(int points);
        void setEnergyPoints(int points);
        void setAttackDamage(int damage);
        void setName(const std::string& name);
        
        int getHitPoints();
        int getEnergyPoints();
        int getAttackDamage() const;
        std::string getName() const;

        void printStatus() const;
};

#endif