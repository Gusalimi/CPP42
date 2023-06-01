#ifndef SPAN_HPP
#define SPAN_HPP

#include <vector>

class Span
{
	public:
		Span(unsigned int N);
		Span(const Span &other);
		~Span();
		Span &operator=(const Span &other);

		void addNumber(int number);
		void addNumber(std::vector<int>::const_iterator begin, std::vector<int>::const_iterator end);
		int shortestSpan();
		int longestSpan();

		class EmptySpanException : public std::exception
		{
			public:
				virtual const char *what() const throw();
		};

		class FullSpanException : public std::exception
		{
			public:
				virtual const char *what() const throw();
		};
	private:
		unsigned int _N;
		std::vector<int> _numbers;
		Span();
};

#endif /* SPAN_HPP */
