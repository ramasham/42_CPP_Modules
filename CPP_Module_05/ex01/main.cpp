#include "Form.hpp"
#include "Bureaucrat.hpp"

int main() {
    try {
        Bureaucrat alice("Alice", 50);
        Bureaucrat bob("Bob", 1);
        
        // name, toSign, toExe
        Form taxForm("TaxForm", 1, 1);
        Form secretForm("SecretForm", 5, 3);
        alice.signForm(taxForm);
        bob.signForm(taxForm);
        bob.signForm(secretForm);

    } catch (const std::exception& e) {
        std::cerr << "Exception caught in main: " << e.what() << std::endl;
    }

    return 0;
}
