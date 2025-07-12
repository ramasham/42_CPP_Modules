#include "Form.hpp"
#include "Bureaucrat.hpp"

Form::Form() : 
    name("defalut"),
    isSigned(false),
    gradeToExe(150),
    gradeToSign(150) {
        std::cout << "Form: Default constructor called\n";
}

Form::Form(const std::string& name, const int gradeToExe, const int gradeToSign)
    : name(name), isSigned(false), gradeToExe(gradeToExe), gradeToSign(gradeToSign)
{
    if (gradeToSign < 1 || gradeToExe < 1)
        throw Form::GradeTooHighException();
    if (gradeToSign > 150 || gradeToExe > 150)
        throw Form::GradeTooLowException();
    std::cout << "Form: constructor called\n";
}

Form::~Form() {
    std::cout << "Form: destructor called\n";
}

Form::Form(const Form& other) :
    name(other.name),
    isSigned(other.isSigned),
    gradeToExe(other.gradeToExe),
    gradeToSign(other.gradeToSign) {
        std::cout << "Form: Copy constructor called\n";
}

Form& Form::operator=(const Form& other) {
    if (this != &other) {
       this->isSigned = other.isSigned;
    }
    std::cout << "Form: Copy assignment operator called\n" << std::endl;
    return *this;
}

//take bure -> change the form's status to signed if garde is >= required 
void Form::beSigned(const Bureaucrat& bureaucrat) {
    if (bureaucrat.getGrade() <= gradeToSign)
        isSigned = true;
    else
        throw Form::GradeTooLowException();

}

const std::string& Form::getName() const {
    return name;
}

int Form::getGradeToSign() const {
    return gradeToSign;
}

int Form::getGradeToExecute() const {
    return gradeToExe;
}

bool Form::getIsSigned() const {
    return isSigned;
}

std::ostream& operator<<(std::ostream& os, const Form& f) {
    os << "Form \"" << f.getName()
       << "\", signed: " << (f.getIsSigned() ? "yes" : "no")
       << ", grade to sign: " << f.getGradeToSign()
       << ", grade to execute: " << f.getGradeToExecute();
    return os;
}