#include "Intern.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"
#include <iostream>

Intern::Intern() {
    std::cout << "Intern: Default constructor called\n";
}

Intern::Intern(const Intern& other) {
    (void)other;
    std::cout << "Intern: Copy constructor called\n";
}

Intern& Intern::operator=(const Intern& other) {
    (void)other;
    std::cout << "Intern: Copy assignment operator called\n" << std::endl;
    return *this;
}

Intern::~Intern() {
    std::cout << "Intern: Destructor called\n";
}

static AForm* ShurubberyCreation(const std::string& target) {
    return new ShrubberyCreationForm(target);
}

static AForm* RobotomyRequest(const std::string& target) {
    return new RobotomyRequestForm(target);
}

static AForm* PresidentialPardon(const std::string& target) {
    return new PresidentialPardonForm(target);
}

AForm* Intern::makeForm(const std::string& formName, const std::string& target) {
    const char* forms[3] = {
        "shrubbery creation",
        "robotomy request",
        "presidential pardon"
    };

    AForm* (*creators[3])(const std::string& target) = {
        &ShurubberyCreation,
        &RobotomyRequest,
        &PresidentialPardon
    };

    for (int i = 0; i < 3; ++i) {
        if (formName == forms[i]) {
            std::cout << "Intern creates " << formName << std::endl;
            return creators[i](target);
        }
    }
    std::cerr << "Intern: form '" << formName << "' doesn't exist." << std::endl;
    return NULL;
}