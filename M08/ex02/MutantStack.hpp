#ifndef MUTANTSTACK_HPP
#define MUTANTSTACK_HPP

#include <stack>

template <typename T>
class MutantStack : public std::stack<T> {
public:
	MutantStack() : std::stack<T>() {};
	MutantStack(const MutantStack<T> &other) : std::stack<T>(other) {};
	~MutantStack() {};
	MutantStack<T> &operator=(const MutantStack<T> &other) {
		if (this != &other)
			std::stack<T>::operator=(other);
		return *this;
	};
	typedef typename std::stack<T>::container_type::iterator iterator;

    iterator begin() { return std::stack<T>::c.begin(); }
    iterator end() { return std::stack<T>::c.end(); }
};

#endif /* MUTANTSTACK_HPP */
