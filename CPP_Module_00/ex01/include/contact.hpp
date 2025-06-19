/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   contact.hpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rsham <rsham@student.42amman.com>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/19 17:56:20 by rsham             #+#    #+#             */
/*   Updated: 2025/05/20 18:50:33 by rsham            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CONTACT_HPP
# define CONTACT_HPP

# include <iostream>
# include <iomanip>

class contact {
    std::string phoneNumber;
    std::string firstName;
    std::string lastName;
    std::string nickname;
    std::string darkestSecret;

    public:
    void setPhoneNumber(const std::string& newPhoneNumber) {
        phoneNumber = newPhoneNumber;
    }
    void setFirstName(const std::string& newFirstName) {
        firstName = newFirstName;
    }
    void setLastName(const std::string& newLastName) {
        lastName = newLastName;
    }
    void setNickname(const std::string& newNickname) {
        nickname = newNickname;
    }
    void setDarkestSecret(const std::string& newDarkestSecret) {
        darkestSecret = newDarkestSecret;
    }
    
    std::string getPhoneNumber() {
        return (phoneNumber);
    }
    std::string getFirstName() {
        return (firstName);
    }
    std::string getLastName() {
        return (lastName);
    }
    std::string getNickname() {
        return (nickname);
    }
    std::string getDarkestSecret() {
        return(darkestSecret);
    }

};

#endif