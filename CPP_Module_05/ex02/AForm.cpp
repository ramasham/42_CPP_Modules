#include "AForm.hpp"

AForm::AForm() : 
    name("defalut"),
    isSigned(false),
    gradeToExe(150),
    gradeToSign(150) {
        std::cout << "Default constructor\n";
}

AForm::AForm(const std::string& name, const int gradeToExe, const int gradeToSign)
    : name(name), isSigned(false), gradeToExe(gradeToExe), gradeToSign(gradeToSign)
{
    if (gradeToSign < 1 || gradeToExe < 1)
        throw AForm::GradeTooHighException();
    if (gradeToSign > 150 || gradeToExe > 150)
        throw AForm::GradeTooLowException();

}

AForm::~AForm() {
    std::cout << "destructor\n";
}

AForm::AForm(const AForm& other) :
    name(other.name),
    isSigned(other.isSigned),
    gradeToExe(other.gradeToExe),
    gradeToSign(other.gradeToSign) {
        std::cout << "Copy constructor called\n";
}

AForm& AForm::operator=(const AForm& other) {
    if (this != &other) {
       this->isSigned = other.isSigned;
    }
    std::cout << "Copy assignment operator called\n" << std::endl;
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