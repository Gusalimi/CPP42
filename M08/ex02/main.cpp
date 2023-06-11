#include <iostream>
#include <list>
#include "MutantStack.hpp"

int main()
{
	{
		MutantStack<int> mstack;

		std::cout << "push 5" << std::endl;
		mstack.push(5);
		std::cout << "push 17" << std::endl;
		mstack.push(17);

		std::cout << "top: " << mstack.top() << std::endl;

		std::cout << "pop" << std::endl;
		mstack.pop();

		std::cout << "size: " << mstack.size() << std::endl;

		std::cout << "push 3" << std::endl;
		mstack.push(3);
		std::cout << "push 5" << std::endl;
		mstack.push(5);
		std::cout << "push 737" << std::endl;
		mstack.push(737);
		std::cout << "push 0" << std::endl;
		mstack.push(0);

		MutantStack<int>::iterator it = mstack.begin();
		MutantStack<int>::iterator ite = mstack.end();

		std::cout << "MutantStack: ";
		while (it != ite)
		{
			std::cout << *it << " ";
			++it;
		}
		std::cout << std::endl;

		std::cout << "MutantStack: ";
		for (MutantStack<int>::iterator it = mstack.begin(); it != mstack.end(); it++)
			std::cout << *it << " ";
		std::cout << std::endl;

		std::cout << "MutantStack: ";
		for (MutantStack<int>::reverse_iterator it = mstack.rbegin(); it != mstack.rend(); it++)
			std::cout << *it << " ";
		std::cout << std::endl;

		std::cout << "MutantStack: ";
		for (MutantStack<int>::const_iterator it = mstack.begin(); it != mstack.end(); it++)
			std::cout << *it << " ";
		std::cout << std::endl;

		std::cout << "MutantStack: ";
		for (MutantStack<int>::const_reverse_iterator it = mstack.rbegin(); it != mstack.rend(); it++)
			std::cout << *it << " ";
		std::cout << std::endl;

		std::stack<int> s(mstack);
	}

	std::cout << std::endl;

	{
		std::list<int> l;

		std::cout << "push 5" << std::endl;
		l.push_back(5);
		std::cout << "push 17" << std::endl;
		l.push_back(17);

		std::cout << "top: " << l.back() << std::endl;

		std::cout << "pop" << std::endl;
		l.pop_back();

		std::cout << "size: " << l.size() << std::endl;

		std::cout << "push 3" << std::endl;
		l.push_back(3);
		std::cout << "push 5" << std::endl;
		l.push_back(5);
		std::cout << "push 737" << std::endl;
		l.push_back(737);
		std::cout << "push 0" << std::endl;
		l.push_back(0);

		std::list<int>::iterator it = l.begin();
		std::list<int>::iterator ite = l.end();

		std::cout << "std::list: ";
		while (it != ite)
		{
			std::cout << *it << " ";
			++it;
		}
		std::cout << std::endl;

		std::cout << "std::list: ";
		for (std::list<int>::iterator it = l.begin(); it != l.end(); it++)
			std::cout << *it << " ";
		std::cout << std::endl;

		std::cout << "std::list: ";
		for (std::list<int>::reverse_iterator it = l.rbegin(); it != l.rend(); it++)
			std::cout << *it << " ";
		std::cout << std::endl;

		std::cout << "std::list: ";
		for (std::list<int>::const_iterator it = l.begin(); it != l.end(); it++)
			std::cout << *it << " ";
		std::cout << std::endl;

		std::cout << "std::list: ";
		for (std::list<int>::const_reverse_iterator it = l.rbegin(); it != l.rend(); it++)
			std::cout << *it << " ";
		std::cout << std::endl;
	}
	return 0;
}
