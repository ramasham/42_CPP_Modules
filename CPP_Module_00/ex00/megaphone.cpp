/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   megaphone.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rsham <rsham@student.42amman.com>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/15 16:39:22 by rsham             #+#    #+#             */
/*   Updated: 2025/05/17 13:32:16 by rsham            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>

int main(int argc, char **argv)
{
    if (argc == 1)
    {
        std::cout << "* LOUD AND UNBEARABLE FEEDBACK NOISE *" << std::endl;
        return (0);
    }
    int i = 1;
    while (argv[i])
    {
        int j = 0;
        while (argv[i][j])
        {
            argv[i][j] = toupper(argv[i][j]);
            std::cout << argv[i][j];
            j++;
        }
        i++;
    }
    std::cout << std::endl;
    return (0);
}