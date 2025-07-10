#ifndef AFORM_HPP
# define AFORM_HPP

#include <iostream>
#include "Bureaucrat.hpp"

class Bureaucrat;

class AForm {
    private:
        const std::string name;
        bool isSigned;
        const int gradeToExe;
        const int gradeToSign;
    
    protected:
        virtual void executeAction() const = 0;

    public:
        AForm();
        ~AForm();
        AForm(const std::string& name, const int gradeToSign, const int gradeToExe);
        AForm& operator=(const AForm& other);
        AForm(const AForm& other);

        const std::string& getName() const;
        int getGradeToSign() const;
        int getGradeToExecute() const;
        bool getIsSigned() const;

        void beSigned(const Bureaucrat& bureaucrat);
        void execute(Bureaucrat const & executor) const;
        
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

        class FormNotSignedException : public std::exception {
            public:
                virtual const char* what() const throw() {
                    return "";
                }
        };

};

std::ostream& operator<<(std::ostream& os, const AForm& f);

#endif
