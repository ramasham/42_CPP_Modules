#include "ShrubberyCreationForm.hpp"

ShrubberyCreationForm::ShrubberyCreationForm() : AForm(), target("default") {
    std::cout << "ShrubberyCreationForm: default constructor\n";
}

ShrubberyCreationForm::ShrubberyCreationForm(const std::string& target)
    : AForm("ShrubberyCreationForm", 145, 137),
    target(target) {
        std::cout << "ShrubberyCreationForm: constructor\n";
}

ShrubberyCreationForm::ShrubberyCreationForm(const ShrubberyCreationForm& other) 
    : AForm(other),
    target(other.target) {
        std::cout << "ShrubberyCreationForm: Copy constructor called\n";

}

ShrubberyCreationForm& ShrubberyCreationForm::operator=(const ShrubberyCreationForm& other) {
    if (this != &other) {
        AForm::operator=(other);
        target = other.target;
    }
    std::cout << "ShrubberyCreationForm: Copy assignment operator called\n";
    return *this;
}

ShrubberyCreationForm::~ShrubberyCreationForm() {
    std::cout << "ShrubberyCreationForm: destructor\n";
}

void ShrubberyCreationForm::executeAction() const {
    std::ofstream ofs((target + "_shrubbery").c_str());
    if (!ofs)
        throw std::runtime_error("Failed to open file");

    ofs << "               ,@@@@@@@,\n";
    ofs << "       ,,,.   ,@@@@@@/@@,  .oo8888o.\n";
    ofs << "    ,&%%&%&&%,@@@@@/@@@@@@,8888\\88/8o\n";
    ofs << "   ,%&\\%&&%&&%,@@@\\@@@/@@@88\\88888/88'\n";
    ofs << "   %&&%&%&/%&&%@@\\@@/ /@@@88888\\88888'\n";
    ofs << "   %&&%/ %&%%&&@@\\ V /@@' `88\\8 `/88'\n";
    ofs << "   `&%\\ ` /%&'    |.|        \\ '|8'\n";
    ofs << "       |o|        | |         | |\n";
    ofs << "       |.|        | |         | |\n";
    ofs << "jgs \\\\/ ._\\//_/__/  ,\\_//__\\\\/.  \\_//__/_\n";

    ofs.close();
}