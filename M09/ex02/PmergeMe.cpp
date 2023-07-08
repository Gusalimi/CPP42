#include "PmergeMe.hpp"

PmergeMe::PmergeMe() {}

PmergeMe::PmergeMe(PmergeMe const &b) : _v(b._v), _l(b._l) {}

PmergeMe &PmergeMe::operator=(PmergeMe const &rhs)
{
	if (this != &rhs)
	{
		this->_v = rhs._v;
		this->_l = rhs._l;
	}
	return (*this);
}

PmergeMe::~PmergeMe() {}

bool PmergeMe::pushNumberToContainers(int number)
{
	if (number < 0
		|| std::find(this->_v.begin(), this->_v.end(), number) != this->_v.end()
		|| std::find(this->_l.begin(), this->_l.end(), number) != this->_l.end())
		return (false);
	this->_v.push_back(number);
	this->_l.push_back(number);
	return (true);
}

void PmergeMe::mergeSortVector(int first, int last)
{
	if (last - first <= 3)
	{
		insertionSortVector(first, last);
		return;
	}
	int mid = (first + last) / 2;
	mergeSortVector(first, mid);
	mergeSortVector(mid + 1, last);
	mergeVector(first, mid, last);
}

void PmergeMe::insertionSortVector(int first, int last)
{
	int i, j, key;
	for (i = first + 1; i <= last; i++)
	{
		key = this->_v[i];
		j = i - 1;
		while (j >= first && this->_v[j] > key)
		{
			this->_v[j + 1] = this->_v[j];
			j--;
		}
		this->_v[j + 1] = key;
	}
}

void PmergeMe::mergeVector(int first, int mid, int last)
{
	int i, j, k;
	int n1 = mid - first + 1;
	int n2 = last - mid;
	int L[n1], R[n2];
	for (i = 0; i < n1; i++)
		L[i] = this->_v[first + i];
	for (j = 0; j < n2; j++)
		R[j] = this->_v[mid + 1 + j];
	i = 0;
	j = 0;
	k = first;
	while (i < n1 && j < n2)
	{
		if (L[i] <= R[j])
			this->_v[k] = L[i++];
		else
			this->_v[k] = R[j++];
		k++;
	}
	while (i < n1)
		this->_v[k++] = L[i++];
	while (j < n2)
		this->_v[k++] = R[j++];
}

void PmergeMe::mergeSortList(int first, int last)
{
	if (last - first <= 3)
	{
		insertionSortList(first, last);
		return;
	}
	int mid = (first + last) / 2;
	mergeSortList(first, mid);
	mergeSortList(mid + 1, last);
	mergeList(first, mid, last);
}

void PmergeMe::insertionSortList(int first, int last)
{
	int i, j, key;
	std::list<int>::iterator it = this->_l.begin();
	for (i = 0; i < first; i++)
		it++;
	for (i = first + 1; i <= last; i++)
	{
		key = *it;
		j = i - 1;
		while (j >= first && *list_at(j) > key)
		{
			*list_at(j + 1) = *list_at(j);
			j--;
		}
		*list_at(j + 1) = key;
	}
}

void PmergeMe::mergeList(int first, int mid, int last)
{
	int i, j, k;
	int n1 = mid - first + 1;
	int n2 = last - mid;
	int L[n1], R[n2];
	std::list<int>::iterator it = this->_l.begin();
	for (i = 0; i < first; i++)
		it++;
	for (i = 0; i < n1; i++)
		L[i] = *it++;
	for (j = 0; j < n2; j++)
		R[j] = *it++;
	i = 0;
	j = 0;
	k = first;
	while (i < n1 && j < n2)
	{
		if (L[i] <= R[j])
			*list_at(k) = L[i++];
		else
			*list_at(k) = R[j++];
		k++;
	}
	while (i < n1)
		*list_at(k++) = L[i++];
	while (j < n2)
		*list_at(k++) = R[j++];
}

std::list<int>::iterator PmergeMe::list_at(int index)
{
	std::list<int>::iterator it = this->_l.begin();
	for (int i = 0; i < index; i++)
		it++;
	return (it);
}

void PmergeMe::run(char** argv)
{
	int i = 1;
	int j;
	while (argv[i])
	{
		j = 0;
		while (argv[i][j])
		{
			if (!isdigit(argv[i][j]) && (argv[i][j] != '+' && j != 0))
			{
				std::cout << "Error: " << argv[i] << " is not a valid number" << std::endl;
				return;
			}
			j++;
		}
		try{
			if (std::stoi(argv[i]) < 0)
			{
				std::cout << "Error: " << argv[i] << " is not a positive number" << std::endl;
				return;
			}
			if (!pushNumberToContainers(std::stoi(argv[i])))
			{
				std::cout << "Error: " << argv[i] << " is duplicated" << std::endl;
				return;
			}
			i++;
		}
		catch (std::exception &e)
		{
			std::cout << "Error: " << argv[i] << " is not a valid number" << std::endl;
			return;
		}
	}
	std::cout << "Before: ";
	for (unsigned long i = 0; i < this->_v.size(); i++)
		std::cout << this->_v[i] << " ";
	std::cout << std::endl;
	clock_t vectorStart = clock();
	mergeSortVector(0, this->_v.size() - 1);
	clock_t vectorEnd = clock();
	std::cout << "After: ";
	for (unsigned long i = 0; i < this->_v.size(); i++)
		std::cout << this->_v[i] << " ";
	std::cout << std::endl;
	clock_t listStart = clock();
	mergeSortList(0, this->_l.size() - 1);
	clock_t listEnd = clock();
	std::cout << "Time to process a range of " << this->_v.size() << " elements with std::vector : " << (double)(vectorEnd - vectorStart) / (CLOCKS_PER_SEC / 1000000) << " us" << std::endl;
	std::cout << "Time to process a range of " << this->_l.size() << " elements with std::list : " << (double)(listEnd - listStart) / (CLOCKS_PER_SEC / 1000000) << " us" << std::endl;
}