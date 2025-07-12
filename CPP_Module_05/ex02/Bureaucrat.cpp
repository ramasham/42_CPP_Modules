#include "Bureaucrat.hpp"

Bureaucrat::Bureaucrat() : name("default"), grade(150){
    std::cout << "Bureaucrat: Default constructor called\n";
}

Bureaucrat::Bureaucrat(const std::string& name, int grade) : name(name) {
    if (grade < 1)
        throw GradeTooHighException();
    else if (grade > 150)
        throw GradeTooLowException();
    this->grade = grade;
    std::cout << "Bureaucrat: constructor called\n";
}

Bureaucrat& Bureaucrat::operator=(const Bureaucrat& other) {
    if (this != &other) {
        grade = other.grade;
    }
    std::cout << "Bureaucrat: Copy assignment operator called\n" << std::endl;
    return *this;
}

Bureaucrat::Bureaucrat(const Bureaucrat& other) : name(other.name), grade(other.grade) {
    std::cout << "Bureaucrat: Copy constructor called\n";
}

Bureaucrat::~Bureaucrat() {
    std::cout << "Bureaucrat: Destructor called" << std::endl;
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

void Bureaucrat::signForm(AForm& aform) {
    try {
        aform.beSigned(*this);
        std::cout << this->getName() << " signed " << aform.getName();
    }
    catch (const std::exception& e) {
        std::cout << this->getName() << " couldn’t sign "
                  << aform.getName() << " because " << e.what() << std::endl;
    }
}

void Bureaucrat::executeForm(const AForm &form) const {
    try {
        form.execute(*this);
        std::cout << name << " executed " << form.getName() << std::endl;
    } catch (std::exception &e) {
        std::cout << name << " couldn’t execute " << form.getName()
                  << " because " << e.what() << std::endl;
    }
}


