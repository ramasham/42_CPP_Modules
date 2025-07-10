#include "RobotomyRequestForm.hpp"
#include <iostream>
#include <cstdlib>
#include <ctime>

RobotomyRequestForm::RobotomyRequestForm() : AForm(), target("default") {
    std::cout << "RobotomyRequestForm: default constructor\n";
}

RobotomyRequestForm::RobotomyRequestForm(const std::string& target)
    : AForm("RobotomyRequestForm", 72, 45),
    target(target) {
        std::srand(std::time(0));
        std::cout<< "RobotomyRequestForm: constructor\n";
}

RobotomyRequestForm::RobotomyRequestForm(const RobotomyRequestForm& other)
    : AForm(other),
    target(other.target) {
        std::cout << "RobotomyRequestForm: Copy constructor called\n";
}

RobotomyRequestForm& RobotomyRequestForm::operator=(const RobotomyRequestForm& other) {
    if (this != &other) {
        AForm::operator=(other);
        target = other.target;
    }
    std::cout << "RobotomyRequestForm: Copy assignment operator called\n";
    return *this;
}

RobotomyRequestForm::~RobotomyRequestForm() {
    std::cout << "RobotomyRequestForm: destructor\n";
}

void RobotomyRequestForm::executeAction() const {
    std::cout << "BzzzZZZzzzz... drilling noises..." << std::endl;
    if (std::rand() % 2)
        std::cout << target << " has been robotomized successfully!" << std::endl;
    else
        std::cout << "Robotomy failed for " << target << std::endl;
}
