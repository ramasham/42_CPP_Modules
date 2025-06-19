/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   weapon.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rsham <rsham@student.42amman.com>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/28 18:03:25 by rsham             #+#    #+#             */
/*   Updated: 2025/05/29 15:38:27 by rsham            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "weapon.hpp"

Weapon::Weapon(std::string type) : type(type) {
    
}

void Weapon::setType(const std::string& newType) {
    type = newType;
}

const std::string& Weapon::getType() const {
    return type;
}

