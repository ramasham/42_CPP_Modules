/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Harl.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rsham <rsham@student.42amman.com>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/01 16:21:28 by rsham             #+#    #+#             */
/*   Updated: 2025/06/03 13:19:36 by rsham            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Harl.hpp"
#include <iostream>

void Harl::debug(void) {
    std::cout << "[DEBUG] - Honestly, extra cheese just makes everything better. Why not pile it on?\n";
}

void Harl::info(void) {
    std::cout << "[INFO] - Did you know? Adding cheese costs more. Outrageous, but sadly true.\n";
}

void Harl::warning(void) {
    std::cout << "[WARNING] - Look, I've been a loyal customer. A little extra cheese shouldn't be too much to ask.\n";
}

void Harl::error(void) {
    std::cout << "[ERROR] - I've had enough! This service is a joke. Get the manager — NOW.\n";
}

void Harl::complain(std::string level) {
    typedef void (Harl::*funcPtr)(void);
    
    std::string levels[] = {"DEBUG", "INFO", "WARNING", "ERROR"};
    funcPtr funcs[] = {&Harl::debug, &Harl::info, &Harl::warning, &Harl::error};
    for (int i = 0; i < 4; i++) {
        if (level == levels[i]) {
            (this->*funcs[i])();
            return ;
        }
    }
    std::cout << "[UNKNOWN] Level not recognized.\n";
}
