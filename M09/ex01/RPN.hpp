#ifndef RPN_HPP
#define RPN_HPP

#include <iostream>
#include <sstream>
#include <stack>

class RPN {
private:
	std::string _input;
	double _result;
	RPN();
public:
	RPN(std::string input);
	RPN(RPN const &b);
	RPN &operator=(RPN const &rhs);
	~RPN();

	double getResult() const;
	void calculate();
};

#endif /* RPN_HPP */
