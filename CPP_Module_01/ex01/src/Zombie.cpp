/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rsham <rsham@student.42amman.com>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/28 12:26:27 by rsham             #+#    #+#             */
/*   Updated: 2025/05/28 16:49:31 by rsham            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"
#include <iostream>

Zombie::Zombie() {}

void Zombie::setName(const std::string& newName) {
    name = newName;
}

Zombie::~Zombie() {
    std::cout << name << ": is destroyed." << std::endl;
}

void Zombie::announce(void) {
    std::cout << name << std::endl;
}
