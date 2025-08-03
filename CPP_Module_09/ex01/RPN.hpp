#ifndef RPN__HPP
# define RPN__HPP

#include <stack>
#include <string>


class RPN {
    private:
        std::stack<int> numbers;
        void add();
        void subtract();
        void divide();
        void multiply();
        bool isValidOperator(char c);
        bool isValidOperand();
    
    public:
        RPN();
        RPN(const RPN& other);
        RPN& operator=(const RPN& other);
        ~RPN();
        void calculate(std::string input);

};


#endif