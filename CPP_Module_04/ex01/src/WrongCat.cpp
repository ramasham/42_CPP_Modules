/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   WrongCat.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rsham <rsham@student.42amman.com>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/23 12:59:28 by rsham             #+#    #+#             */
/*   Updated: 2025/06/23 13:00:08 by rsham            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "WrongCat.hpp"

WrongCat::WrongCat() {
    type = "WrongCat";
    std::cout << "WrongCat: Constructor\n";
}

WrongCat::~WrongCat() {
    std::cout << "WrongCat: Destructor\n";
}

void WrongCat::makeSound() const {
    std::cout << "meow?? (but wrong)\n";
}
