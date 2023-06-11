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
	typedef typename std::stack<T>::container_type::reverse_iterator reverse_iterator;
	typedef typename std::stack<T>::container_type::const_iterator const_iterator;
	typedef typename std::stack<T>::container_type::const_reverse_iterator const_reverse_iterator;

    iterator begin() { return std::stack<T>::c.begin(); }
    iterator end() { return std::stack<T>::c.end(); }
    reverse_iterator rbegin() { return std::stack<T>::c.rbegin(); }
    reverse_iterator rend() { return std::stack<T>::c.rend(); }
};

#endif /* MUTANTSTACK_HPP */
