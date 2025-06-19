/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rsham <rsham@student.42amman.com>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/20 18:57:35 by rsham             #+#    #+#             */
/*   Updated: 2025/05/20 19:05:34 by rsham            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef UTILS_HPP
#define UTILS_HPP

#include <string>
#include <iostream>
#include "phoneBook.hpp"

std::string format(const std::string& str);
std::string checkEmpty(const std::string& field);
void add(phoneBook& book);
void search(phoneBook& book);

#endif