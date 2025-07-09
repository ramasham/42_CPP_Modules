/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Animal.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rsham <rsham@student.42amman.com>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/22 17:26:24 by rsham             #+#    #+#             */
/*   Updated: 2025/06/23 12:46:10 by rsham            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ANIMAL_HPP
#define ANIMAL_HPP

#include <iostream>

class Animal {
    protected:
        std::string type;
        
        public:
        Animal();
        Animal(const Animal& other);
        Animal(const std::string& type);
        Animal& operator=(const Animal& other);
        virtual ~Animal();
        
        virtual void makeSound() const;
        virtual std::string getType() const;
        
};

#endif