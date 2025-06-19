/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rsham <rsham@student.42amman.com>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/20 18:56:07 by rsham             #+#    #+#             */
/*   Updated: 2025/05/22 12:14:07 by rsham            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "phoneBook.hpp"

std::string format(const std::string& str) {
    std::string result;
    
    if (str.length() > 10)
        result = str.substr(0, 9) + ".";
    else
        result = std::string(10 - str.length(), ' ') + str;
    return (result);
}

std::string checkEmpty(const std::string& field) {
    std::string input;
    
    while (1) {
        std::cout << field << ": ";
        std::getline(std::cin, input);

        if (!input.empty())
            return input;
        std::cout << "A saved contact can't have empty fields" <<std::endl;
    }
}
