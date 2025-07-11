#ifndef FORM_HPP
# define FORM_HPP

#include <iostream>

class Bureaucrat;

class Form {
    private:
        const std::string name;
        bool isSigned;
        const int gradeToExe;
        const int gradeToSign;
    
    public:
        Form();
        ~Form();
        Form(const std::string& name, const int gradeToSign, const int gradeToExe);
        Form& operator=(const Form& other);
        Form(const Form& other);

        const std::string& getName() const;
        int getGradeToSign() const;
        int getGradeToExecute() const;
        bool getIsSigned() const;

        void beSigned(const Bureaucrat& bureaucrat);

        class GradeTooHighException : public std::exception {
            public:
                virtual const char* what() const throw() {
                    return "Grade is too HIGH!";
                }
        };

        class GradeTooLowException : public std::exception {
            public:
                virtual const char* what() const throw() {
                    return "Grade is too LOW!";
                }
        };

};

std::ostream& operator<<(std::ostream& os, const Form& f);


#endif