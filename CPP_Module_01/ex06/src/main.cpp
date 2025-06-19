/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rsham <rsham@student.42amman.com>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/01 16:34:49 by rsham             #+#    #+#             */
/*   Updated: 2025/06/03 13:19:50 by rsham            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Harl.hpp"
#include <iostream>

int main(int argc, char **argv) {
    if (argc == 2)
    {
        Harl harl;
        harl.complain(argv[1]);
        return 0;
    }
    std::cout << "Please enter a level 🙄 " << std::endl;
    return 0; 
}
