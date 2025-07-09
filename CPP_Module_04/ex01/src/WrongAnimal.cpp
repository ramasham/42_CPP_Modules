/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   WrongAnimal.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rsham <rsham@student.42amman.com>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/23 12:59:30 by rsham             #+#    #+#             */
/*   Updated: 2025/06/23 13:00:03 by rsham            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "WrongAnimal.hpp"

WrongAnimal::WrongAnimal() : type("WrongAnimal") {
    std::cout << "WrongAnimal: Constructor\n";
}

WrongAnimal::~WrongAnimal() {
    std::cout << "WrongAnimal: Destructor\n";
}

void WrongAnimal::makeSound() const {
    std::cout << "Generic wrong sound\n";
}

std::string WrongAnimal::getType() const {
    return type;
}
