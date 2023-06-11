#include "Span.hpp"

Span::Span(unsigned int N)
{
	this->_N = N;
}

Span::Span(const Span &other)
{
	this->_N = other._N;
	this->_numbers = other._numbers;
}

Span::~Span() {}

Span& Span::operator=(const Span &other)
{
	this->_N = other._N;
	this->_numbers = other._numbers;
	return (*this);
}

void Span::addNumber(int number)
{
	if (this->_numbers.size() == this->_N)
		throw Span::FullSpanException();
	this->_numbers.push_back(number);
}

void Span::addNumber(std::vector<int>::const_iterator begin, std::vector<int>::const_iterator end)
{
	if (this->_numbers.size() + std::distance(begin, end) > this->_N)
		throw Span::FullSpanException();
	this->_numbers.insert(this->_numbers.end(), begin, end);
}

int Span::shortestSpan()
{
	if (this->_numbers.size() <= 1)
		throw Span::EmptySpanException();
	std::vector<int> tmp = this->_numbers;
	std::sort(tmp.begin(), tmp.end());
	std::vector<int>::iterator it = tmp.begin();
	int shortest = std::abs(*it - *(it + 1));
	for (; it != tmp.end() - 1; it++)
	{
		if (std::abs(*it - *(it + 1)) < shortest)
			shortest = std::abs(*it - *(it + 1));
	}
	return (shortest);
}

int Span::longestSpan()
{
	if (this->_numbers.size() <= 1)
		throw Span::EmptySpanException();
	return (*std::max_element(this->_numbers.begin(), this->_numbers.end()) - *std::min_element(this->_numbers.begin(), this->_numbers.end()));
}

const char *Span::EmptySpanException::what() const throw()
{
	return ("No or only one element in span");
}

const char *Span::FullSpanException::what() const throw()
{
	return ("Span is full");
}