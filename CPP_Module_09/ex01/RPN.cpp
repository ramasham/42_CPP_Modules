#include "RPN.hpp"
#include <iostream>

RPN::RPN() {}

RPN::~RPN() {}

RPN::RPN(const RPN& other) : numbers(other.numbers) {}

RPN& RPN::operator=(const RPN& other) {
	if (this != &other) {
		numbers = other.numbers;
	}
	return *this;
}

void RPN::add() {
	int b = numbers.top();
	numbers.pop();
	int a = numbers.top();
	numbers.pop();
	numbers.push(a + b);
}

void RPN::subtract() {
	int b = numbers.top();
	numbers.pop();
	int a = numbers.top();
	numbers.pop();
	numbers.push(a - b);
}

void RPN::multiply() {
	int b = numbers.top();
	numbers.pop();
	int a = numbers.top();
	numbers.pop();
	numbers.push(a * b);
}

void RPN::divide() {
	int b = numbers.top();
	numbers.pop();
	int a = numbers.top();
	numbers.pop();
	
	if (b == 0) {
		std::cout << "Error: Division by zero." << std::endl;
		numbers.push(a);
		numbers.push(b);
		return;
	}
	numbers.push(a / b);
}

bool RPN::isValidOperator(char c) {
	return c == '+' || c == '-' || c == '*' || c == '/';
}

bool RPN::isValidOperand() {
	return numbers.size() >= 2;
}

void RPN::calculate(std::string input) {
	for (size_t i = 0; i < input.size(); ++i) {
		char c = input[i];

		if (c == ' ') {
			continue;
		} else if (isdigit(c)) {
			numbers.push(c - '0');
		} else if (isValidOperator(c) && isValidOperand()) {
			if (c == '+')
                add();
			else if (c == '-')
                subtract();
			else if (c == '*')
                multiply();
			else if (c == '/')
                divide();
		} else {
			std::cout << "Error: Invalid input" << std::endl;
			return;
		}
	}

	if (numbers.size() == 1) {
		std::cout << "Result: " << numbers.top() << std::endl;
		numbers.pop();
	} else {
		std::cout << "Error: Invalid input" << std::endl;
	}
}
