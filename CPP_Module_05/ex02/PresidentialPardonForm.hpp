#ifndef PRESIDENTIALPARDONFORM_HPP
#define PRESIDENTIALPARDONFORM_HPP

#include "AForm.hpp"

//once a destructor is declared virtual in a base class, it is automatically virtual in all derived classes,
//even if you don’t explicitly write virtual in the derived class.

class PresidentialPardonForm : public AForm {
    private:
        std::string target;

    protected:
        void executeAction() const;

    public:
        PresidentialPardonForm();
        PresidentialPardonForm(const std::string& target);
        PresidentialPardonForm(const PresidentialPardonForm& other);
        PresidentialPardonForm& operator=(const PresidentialPardonForm& other);
        ~PresidentialPardonForm();

};

#endif
