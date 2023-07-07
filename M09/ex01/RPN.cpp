#include "RPN.hpp"

RPN::RPN() {}
RPN::RPN(RPN const &b) : _input(b._input), _result(b._result) {}
RPN &RPN::operator=(RPN const &rhs)
{
	if (this != &rhs)
	{
		this->_input = rhs._input;
		this->_result = rhs._result;
	}
	return (*this);
}
RPN::RPN(std::string input) : _input(input), _result(0) {}
RPN::~RPN() {}

void RPN::calculate()
{
	std::stack<double> stack;
	std::stringstream ss(this->_input);
	std::string token;
	double a;
	double b;

	while (std::getline(ss, token, ' '))
	{
		if (token == "+" || token == "-" || token == "*" || token == "/")
		{
			if (stack.size() < 2)
				throw std::runtime_error("Error: Not enough values in stack");
			a = stack.top();
			stack.pop();
			b = stack.top();
			stack.pop();
			if (token == "+")
				stack.push(b + a);
			else if (token == "-")
				stack.push(b - a);
			else if (token == "*")
				stack.push(b * a);
			else if (token == "/")
			{
				if (a == 0)
					throw std::runtime_error("Error: Division by zero");
				stack.push(b / a);
			}
		}
		else
		{
			try {
				stack.push(std::stod(token));
			} catch (std::exception &e) {
				throw std::runtime_error("Error: Invalid value");
			}
		}
	}
	if (stack.size() != 1)
		throw std::runtime_error("Error: Too many values in stack");
	this->_result = stack.top();
}

double RPN::getResult() const { return (this->_result); }