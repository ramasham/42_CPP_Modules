/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rsham <rsham@student.42amman.com>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/28 13:08:23 by rsham             #+#    #+#             */
/*   Updated: 2025/05/28 14:22:00 by rsham            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

int main() {
    int count = 10;
    Zombie* horde = zombieHorde(count, "zombie");
    for (int i = 0; i < count; ++i) {
        horde[i].announce();
    }
    delete [] horde;
    return 0;
}
