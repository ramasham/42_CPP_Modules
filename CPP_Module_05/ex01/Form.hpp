#ifndef FORM_HPP
# define FORM_HPP

#include <iostream>

class Form {
    private:
        const std::string name;
        bool signed_num;
        const int grade_sign;
        const int grade_exe;
    
    public:
        Form();
        ~Form();
        Form(const std::string& name, bool signed_num, const int grade_sign, const int grade_exe);
        Form& operator=(const Form& other);
        Form(const Form& other);

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