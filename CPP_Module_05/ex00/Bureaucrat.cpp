
#include "Bureaucrat.hpp"

Bureaucrat::Bureaucrat() : name("default"), grade(150) {
    std::cout << "Default constructor\n";
}

Bureaucrat::Bureaucrat(const std::string& name, int grade) : name(name) {
    if (grade < 1)
        throw GradeTooHighException();
    else if (grade > 150)
        throw GradeTooLowException();
    this->grade = grade;
}

Bureaucrat& Bureaucrat::operator=(const Bureaucrat& other) {
    std::cout << "Copy assignment operator called\n" << std::endl;
    if (this != &other) {
        grade = other.grade;
    }
    return *this;
}

Bureaucrat::Bureaucrat(const Bureaucrat& other) : name(other.name), grade(other.grade) {
    std::cout << "Copy constructor called\n";
}

Bureaucrat::~Bureaucrat() {
    std::cout << "Destuctor called" << std::endl;
}

std::ostream& operator<<(std::ostream& os, const Bureaucrat& b) {
    os << b.getName() << ", bureaucrat grade " << b.getGrade() << "." << std::endl;
    return os;
}

int Bureaucrat::getGrade() const {
    return grade;
}

const std::string& Bureaucrat::getName() const {
    return name;
}

void Bureaucrat::increment() {
    if (grade - 1 < 1)
        throw GradeTooHighException();
    grade--;
}

void Bureaucrat::decrement() {
   if (grade + 1 > 150)
        throw GradeTooLowException();
    grade++;
}
