/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rsham <rsham@student.42amman.com>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/03 13:58:55 by rsham             #+#    #+#             */
/*   Updated: 2025/06/11 17:15:52 by rsham            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FIXED_HPP
#define FIXED_HPP

class Fixed {
private:
    int                 value;
    static const int    fractionalBits = 8;

public:
    // Default constructor
    Fixed();

    // Copy constructor
    Fixed(const Fixed& other);

    // Copy assignment operator
    Fixed& operator=(const Fixed& other);

    // Destructor
    ~Fixed();

    // Getter for the raw bits
    int getRawBits(void) const;

    // Setter for the raw bits
    void setRawBits(int const raw);
};



#endif