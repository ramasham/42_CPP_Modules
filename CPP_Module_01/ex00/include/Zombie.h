/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rsham <rsham@student.42amman.com>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/22 19:05:00 by rsham             #+#    #+#             */
/*   Updated: 2025/06/02 11:33:54 by rsham            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ZOMBIE_H
# define ZOMBIE_H

#include <string>

class Zombie {
    std::string name;
    
    public:
    Zombie(const std::string zombieName);
    ~Zombie();
    void announce ( void );
};

void    randomChump(std::string name);
Zombie* newZombie(std::string name);


#endif