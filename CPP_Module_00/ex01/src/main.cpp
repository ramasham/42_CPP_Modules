/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rsham <rsham@student.42amman.com>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/20 18:54:58 by rsham             #+#    #+#             */
/*   Updated: 2025/05/22 12:43:31 by rsham            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "phoneBook.hpp"
#include "utils.hpp"

void add(phoneBook& book)
{
    contact newContact;

    newContact.setFirstName(checkEmpty("First name"));
    newContact.setLastName(checkEmpty("Last name"));
    newContact.setNickname(checkEmpty("Nickname"));
    newContact.setPhoneNumber(checkEmpty("Phone number"));
    newContact.setDarkestSecret(checkEmpty("Darkest secret"));

    book.addContact(newContact);
    std::cout << "Contact saved! ✅ " << std::endl;
    
}

void search(phoneBook& book) {

    book.printContact();
    std::string input;

    std::cout << "Enter the index of the contact to view: ";
    std::getline(std::cin, input);
    if (input.length() != 1 || input[0] < '0' || input[0] > '7') {
        std::cout << "Invalid index! 🅾️ " << std::endl;
        return;
    }
    int i = input[0] - '0';
    contact *c = book.getContact(i);
    if (!c) {
        std::cout << "No contact at given index! 🅾️" << std::endl;
        return ;
    }
    std::cout << "First Name: " << c->getFirstName() << std::endl;
    std::cout << "Last Name: " << c->getLastName() << std::endl;
    std::cout << "Nickname: " << c->getNickname() << std::endl;
    std::cout << "Phone Number: " << c->getPhoneNumber() << std::endl;
    std::cout << "Darkest Secret: 🤫 " << c->getDarkestSecret() << std::endl;
}

int main()
{
    phoneBook book;
    std::string userInput;

    while (1) {        
        std::cout << "Enter one of these commands (ADD, SEARCH and EXIT) : " << std::endl;
        if (!std::getline(std::cin, userInput)) {
            std::cout << "Exiting program. 👋 \n";
            break;
        }
        if (userInput == "ADD")
            add(book);
        else if (userInput == "SEARCH")
            search(book);
        else if (userInput == "EXIT")
            break;
        else
            std::cout << "Enter valid command! 🙄" << std::endl;
    }
    return (0);
}
