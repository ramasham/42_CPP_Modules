/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rsham <rsham@student.42amman.com>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/17 13:53:21 by rsham             #+#    #+#             */
/*   Updated: 2025/05/22 15:33:51 by rsham            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "phoneBook.hpp"
#include "utils.hpp"

phoneBook::phoneBook() : index(0), count(0) {
    
}

void phoneBook::addContact(const contact& newContact) {
    contacts[index] = newContact;
    index = (index + 1) % 8;
    if (count < 8)
        count++;
}
    
void phoneBook::printContact() {
    std::cout << std::setw(10) << "Index" << "|"
              << std::setw(10) << "First Name" << "|"
              << std::setw(10) << "Last Name" << "|"
              << std::setw(10) << "Nickname" << std::endl;

    for (int i = 0; i < count; i++) {
        std::cout << std::setw(10) << i << "|"
                  << format(contacts[i].getFirstName()) << "|"
                  << format(contacts[i].getLastName()) << "|"
                  << format(contacts[i].getNickname()) << std::endl;
    }
}

contact* phoneBook::getContact(int i) {
    if (i < 0 || i >= count)
        return NULL;
    return &contacts[i];
}
