/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rsham <rsham@student.42amman.com>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/28 16:54:54 by rsham             #+#    #+#             */
/*   Updated: 2025/05/28 17:27:13 by rsham            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string>
#include <iostream>

int main() {
    std::string str = "HI THIS IS BRAIN";
    std::string* stringPTR = &str;
    std::string& stringREF = str;
    
    std::cout << "The memory address of the string variable: ";
    std::cout << &str << std::endl;
     
    std::cout << "The memory address held by stringPTR: ";
    std::cout << stringPTR << std::endl;

    std::cout << "The memory address held by stringREF: ";
    std::cout << &stringREF << std::endl;
    
    std::cout << "The value of the string variable: ";
    std::cout << str << std::endl;

    std::cout << "The value pointed to by stringPTR: ";
    std::cout << *stringPTR << std::endl;

    std::cout << "The value pointed to by stringREF: ";
    std::cout << stringREF << std::endl;
    
    return 0;
}
