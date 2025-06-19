/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   phoneBook.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rsham <rsham@student.42amman.com>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/19 17:55:57 by rsham             #+#    #+#             */
/*   Updated: 2025/05/22 15:41:20 by rsham            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHONEBOOK_HPP
#define PHONEBOOK_HPP

#include "contact.hpp"

class phoneBook {
    contact contacts[8];
    int index;
    int count;
    
    public:
    phoneBook();
    void addContact(const contact& newContact);
    void printContact();
    contact *getContact(int i);
    
    
};

#endif