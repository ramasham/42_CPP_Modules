#include <iostream>
#include <ctime>
#include <cstdlib>

#include "Bureaucrat.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"

int main() {
    std::srand(std::time(0));

    Bureaucrat bob("Bob", 1);

    ShrubberyCreationForm tree("garden");
    RobotomyRequestForm robo("Alice");
    PresidentialPardonForm pardon("Marvin");

    try {
        bob.signForm(tree);
        bob.signForm(robo);
        bob.signForm(pardon);

        bob.executeForm(tree);
        bob.executeForm(robo);
        bob.executeForm(pardon);
    } catch (const std::exception& e) {
        std::cerr << "Exception: " << e.what() << std::endl;
    }

    return 0;
}
