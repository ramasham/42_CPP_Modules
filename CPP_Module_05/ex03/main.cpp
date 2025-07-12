#include <iostream>
#include "Intern.hpp"
#include "AForm.hpp"
#include "Bureaucrat.hpp"
#include <ctime>

int main() {
    std::srand(std::time(0));

    Intern someRandomIntern;
    AForm* form1 = NULL;
    AForm* form2 = NULL;
    AForm* form3 = NULL;
    AForm* formInvalid = NULL;

    // Test valid form: shrubbery creation
    form1 = someRandomIntern.makeForm("shrubbery creation", "Garden");
    if (form1)
        std::cout << "Created form: " << form1->getName() << " targeting " << form1->getTarget() << "\n\n";

    // Test valid form: robotomy request
    form2 = someRandomIntern.makeForm("robotomy request", "Bender");
    if (form2)
        std::cout << "Created form: " << form2->getName() << " targeting " << form2->getTarget() << "\n\n";

    // Test valid form: presidential pardon
    form3 = someRandomIntern.makeForm("presidential pardon", "Marvin");
    if (form3)
        std::cout << "Created form: " << form3->getName() << " targeting " << form3->getTarget() << "\n\n";

    // Test invalid form
    formInvalid = someRandomIntern.makeForm("invalid form", "Nobody");
    if (!formInvalid)
        std::cout << "Form creation failed for unknown form type.\n\n";

    delete form1;
    delete form2;
    delete form3;
    delete formInvalid;

    return 0;
}
