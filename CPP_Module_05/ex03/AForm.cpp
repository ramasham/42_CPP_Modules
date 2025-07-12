#include "AForm.hpp"

AForm::AForm() : 
    name("default"),
    isSigned(false),
    gradeToSign(150),
    gradeToExe(150) {
        std::cout << "AForm: Default constructor called\n";
}

AForm::AForm(const std::string& name, const int gradeToSign, const int gradeToExe)
    : name(name), isSigned(false), gradeToSign(gradeToSign), gradeToExe(gradeToExe)
{
    if (gradeToSign < 1 || gradeToExe < 1)
        throw AForm::GradeTooHighException();
    if (gradeToSign > 150 || gradeToExe > 150)
        throw AForm::GradeTooLowException();
     std::cout << "AForm: constructor called\n";

}

AForm::~AForm() {
    std::cout << "AForm: Destructor called\n";
}

AForm::AForm(const AForm& other) :
    name(other.name),
    isSigned(other.isSigned),
    gradeToSign(other.gradeToSign),
    gradeToExe(other.gradeToExe) {
        std::cout << "AForm: Copy constructor called\n";
}

AForm& AForm::operator=(const AForm& other) {
    if (this != &other) {
       this->isSigned = other.isSigned;
    }
    std::cout << "AForm: Copy assignment operator called\n" << std::endl;
    return *this;
}

//take bure -> change the form's status to signed if garde is >= required 
void AForm::beSigned(const Bureaucrat& bureaucrat) {
    if (bureaucrat.getGrade() <= gradeToSign)
        isSigned = true;
    else
        throw AForm::GradeTooLowException();

}

const std::string& AForm::getName() const {
    return name;
}

int AForm::getGradeToSign() const {
    return gradeToSign;
}

int AForm::getGradeToExecute() const {
    return gradeToExe;
}

bool AForm::getIsSigned() const {
    return isSigned;
}

std::string AForm::getTarget() const {
    return target;
}

std::ostream& operator<<(std::ostream& os, const AForm& f) {
    os << "Form \"" << f.getName()
       << "\", signed: " << (f.getIsSigned() ? "yes" : "no")
       << ", grade to sign: " << f.getGradeToSign()
       << ", grade to execute: " << f.getGradeToExecute();
    return os;
}

void AForm::execute(const Bureaucrat &executor) const {
    if (!isSigned)
        throw AForm::FormNotSignedException();
    if (executor.getGrade() > gradeToExe)
        throw AForm::GradeTooLowException();
    executeAction();
}