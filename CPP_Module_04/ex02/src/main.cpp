/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rsham <rsham@student.42amman.com>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/23 12:39:15 by rsham             #+#    #+#             */
/*   Updated: 2025/06/23 18:49:26 by rsham            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Dog.hpp"
#include "Cat.hpp"

int main() {
   
    Animal* a1 = new Dog();
    Animal* a2 = new Cat();

    a1->makeSound();
    a2->makeSound();

    delete a1;
    delete a2;

    return 0;
}
