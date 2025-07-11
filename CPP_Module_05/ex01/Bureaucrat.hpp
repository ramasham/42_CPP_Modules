#ifndef BUREAUCRAT_HPP
# define BUREAUCRAT_HPP

#include "iostream"
#include <exception>
#include "Form.hpp"

//throw -> Something went wrong! Exit from here
//and go to the nearest matching catch block.
class Form;

class Bureaucrat {
    private:
        const std::string name;
        int grade;
    
    public:
        Bureaucrat();
        Bureaucrat(const std::string& name, int grade);
        Bureaucrat(const Bureaucrat& other);
        Bureaucrat& operator=(const Bureaucrat& other);
        ~Bureaucrat();

        int getGrade() const;
        const std::string& getName() const;

        void increment();
        void decrement();
        void signForm(Form& form);

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

std::ostream& operator<<(std::ostream& os, const Bureaucrat& b);

#endif