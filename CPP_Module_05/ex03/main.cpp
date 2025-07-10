#include "Bureaucrat.hpp"
#include "PresidentialPardonForm.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"

int main() {
    Bureaucrat bob("Bob", 1);

    ShrubberyCreationForm tree("garden");
    RobotomyRequestForm robo("Alice");
    PresidentialPardonForm pardon("Marvin");

    try {
        bob.signForm(tree);
        bob.signForm(robo);
        bob.signForm(pardon);

        bob.executeForm(tree);    // creates "garden_shrubbery"
        bob.executeForm(robo);    // 50% chance of success
        bob.executeForm(pardon);  // pardon message
    } catch (std::exception& e) {
        std::cerr << e.what() << std::endl;
    }
}
