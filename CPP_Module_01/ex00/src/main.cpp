/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rsham <rsham@student.42amman.com>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/28 11:28:01 by rsham             #+#    #+#             */
/*   Updated: 2025/06/02 11:34:02 by rsham            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.h"

int main() {
    Zombie* z = newZombie("heapy");
    z->announce();
    randomChump("stacky");
    delete z;
    return 0;
}