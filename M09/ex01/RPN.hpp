#ifndef RPN_HPP
#define RPN_HPP

#include <iostream>
#include <stack>

class RPN {
private:
	std::stack<double> stack;
	std::string input;
	double result;

	void calculate();
	void printStack();
	void printResult();
};

#endif /* RPN_HPP */
