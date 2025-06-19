/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rsham <rsham@student.42amman.com>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/28 12:20:57 by rsham             #+#    #+#             */
/*   Updated: 2025/05/28 16:49:28 by rsham            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#ifndef ZOMBIE_HPP
# define ZOMBIE_HPP

#include <string>

class Zombie {
    std::string name;
    
    public:
    Zombie();
    ~Zombie();
    void setName(const std::string& newName);
    void announce ( void );
};

Zombie* zombieHorde(int N, std::string name);

#endif