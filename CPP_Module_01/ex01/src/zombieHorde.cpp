/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   zombieHorde.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rsham <rsham@student.42amman.com>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/28 12:50:33 by rsham             #+#    #+#             */
/*   Updated: 2025/05/28 14:05:39 by rsham            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"
#include <sstream>

std::string intToString(int n) {
    std::stringstream ss;
    ss << n;
    return ss.str();
}

Zombie* zombieHorde(int N, std::string name) {
    if (N <= 0)
        return NULL;
    Zombie* horde = new Zombie[N];
    for (int i = 0; i < N; ++i) {
        horde[i].setName(name + "_" + intToString(i));
    }
    return horde;
}