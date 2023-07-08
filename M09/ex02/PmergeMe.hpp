#ifndef PMERGEME_HPP
#define PMERGEME_HPP

#include <iostream>
#include <vector>
#include <list>

class PmergeMe {
	private:
		std::vector<int> _v;
		std::list<int> _l;
		bool pushNumberToContainers(int number);
		void insertionSortVector(int first, int last);
		void mergeSortVector(int first, int last);
		void mergeVector(int first, int mid, int last);
		void insertionSortList(int first, int last);
		void mergeSortList(int first, int last);
		void mergeList(int first, int mid, int last);
	public:
		PmergeMe();
		PmergeMe( const PmergeMe & src );
		~PmergeMe();
		PmergeMe & operator = ( const PmergeMe & rhs );
		void run(char** args);
		std::list<int>::iterator list_at(int index);
};

#endif /* PMERGEME_HPP */
