/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rsham <rsham@student.42amman.com>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/23 12:39:15 by rsham             #+#    #+#             */
/*   Updated: 2025/06/23 18:02:41 by rsham            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Animal.hpp"
#include "Cat.hpp"
#include "Dog.hpp"
#include "Brain.hpp"

int main() {
    const int size = 4;
    Animal* animals[size];

    std::cout << "---- Creating Animals ----" << std::endl;

    for (int i = 0; i < size / 2; ++i)
        animals[i] = new Dog();

    for (int i = size / 2; i < size; ++i)
        animals[i] = new Cat();

    std::cout << "\n---- Setting and Getting Ideas ----" << std::endl;

    Dog* realDog = dynamic_cast<Dog*>(animals[0]);
    if (realDog) {
        realDog->setIdea(0, "Chase the cat");
        std::cout << "Dog idea[0]: " << realDog->getIdea(0) << std::endl;
    }

    std::cout << "\n---- Testing Deep Copy ----" << std::endl;

    Dog originalDog;
    originalDog.setIdea(0, "Orginal idea");

    Dog copyDog = originalDog;
    copyDog.setIdea(0, "Changed idea");

    std::cout << "Original Dog idea[0]: " << originalDog.getIdea(0) << std::endl;
    std::cout << "Copy Dog idea[0]:     " << copyDog.getIdea(0) << std::endl;

    std::cout << "\n---- Deleting Animals ----" << std::endl;

    for (int i = 0; i < size; ++i)
        delete animals[i];

    std::cout << "---- Done ----" << std::endl;

    return 0;
}
