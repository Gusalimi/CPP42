#include <iostream>
#include "Span.hpp"

int main()
{
	Span sp = Span(10000);
	for (int i = 0 ; i < 10000 ; i++)
		sp.addNumber(i);
	std::cout << sp.shortestSpan() << std::endl;
	std::cout << sp.longestSpan() << std::endl;

	std::cout << std::endl;

	Span sp2 = Span(6);
	sp2.addNumber(2);
	std::vector<int> tmp;
	for (int i = 5; i < 10; i++)
		tmp.push_back(i);
	sp2.addNumber(tmp.begin(), tmp.end());
	std::cout << sp2.shortestSpan() << std::endl;
	std::cout << sp2.longestSpan() << std::endl;

	std::cout << std::endl;

	Span sp3 = Span(5);
	sp3.addNumber(6);
	sp3.addNumber(3);
	sp3.addNumber(17);
	sp3.addNumber(9);
	sp3.addNumber(11);
	std::cout << sp3.shortestSpan() << std::endl;
	std::cout << sp3.longestSpan() << std::endl;

	return (0);
}