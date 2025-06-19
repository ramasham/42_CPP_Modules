/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rsham <rsham@student.42amman.com>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/29 17:56:24 by rsham             #+#    #+#             */
/*   Updated: 2025/06/02 11:58:49 by rsham            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <fstream>
#include <iostream>

//std::ifstream input(src); == 
//std::ifstream input;     // step 1: declare the object
//input.open(src);         // step 2: open the file

std::string read_file(const std::string& path) {
    std::ifstream file(path.c_str());
    if (!file.is_open())
        return "";
    std::string content((std::istreambuf_iterator<char>(file)), std::istreambuf_iterator<char>());
    file.close();
    return content;
}

std::string ft_replace(const std::string& content, const std::string& from, const std::string& to) {
    std::string res;
    size_t pos = 0;
    size_t found;
    
    while ((found = content.find(from, pos)) != std::string::npos) {
        res += content.substr(pos, found - pos);
        res += to;
        pos = found + from.length();
    }
    res += content.substr(pos);
    return res;
}

bool write_file(const std::string& path, const std::string& content) {
    std::ofstream file(path.c_str());
    if (!file.is_open())
        return false;
    file << content;
    file.close();
    return true;
}

int copy_content(const std::string& src, const std::string& s1, const std::string& s2) {
    if (s1.empty()) {
        std::cerr << "Error: search string cannot be empty.\n";
        return 1;
    }
    
    std::string content = read_file(src);
    if (content.empty()) {
        std::cout << "File is empty or does not exist.\n";
        return 1;
    }
    if (content.find(s1) == std::string::npos) {
        std::cout << "Nothing to replace, '" << s1 << "' was not found.\n";
        return 0;
    }
    std::string replaced = ft_replace(content, s1, s2);
    if (!write_file(src + ".replace", replaced)) {
        std::cerr << "Failed to create output file.\n";
        return 1;
    }
    return 0;
}

int main(int argc, char **argv) {
    if (argc != 4) {
        std::cerr << "Invalid number of arguments.\n";
        std::cerr << "Usage: ./program <filename> <string_to_replace> <replacement_string>\n";
        return 1;
    }
    return copy_content(argv[1], argv[2], argv[3]);
}
