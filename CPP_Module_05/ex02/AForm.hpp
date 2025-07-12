#ifndef AFORM_HPP
# define AFORM_HPP

#include <iostream>
#include "Bureaucrat.hpp"

//If a base class destructor is not virtual,
//and you delete a derived object through a base class pointer,
//only the base class's destructor will run

class Bureaucrat;

class AForm {
    private:
        const std::string name;
        bool isSigned;
        const int gradeToSign;
        const int gradeToExe;
    
    protected:
        virtual void executeAction() const = 0;

    public:
        AForm();
        virtual ~AForm();
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
                    return "Form is not signed!";
                }
        };

};

std::ostream& operator<<(std::ostream& os, const AForm& f);

#endif
