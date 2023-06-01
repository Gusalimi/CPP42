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
	int	shortest_span = -1;
	for (std::vector<int>::const_iterator it = this->_numbers.begin(); it != this->_numbers.end(); it++)
	{
		for (std::vector<int>::const_iterator it2 = it + 1; it2 != this->_numbers.end(); it2++)
		{
			int span = std::abs(*it - *it2);
			if (shortest_span == -1 || span < shortest_span)
				shortest_span = span;
		}
	}
	return (shortest_span);
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