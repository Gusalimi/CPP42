#ifndef EASYFIND_HPP
#define EASYFIND_HPP

//#include <list>

template<typename T>
int easyfind(T const &container, int const &value)
{
	int	i = 0;
	typename T::const_iterator it = container.begin();
	typename T::const_iterator ite = container.end();

	while (it != ite)
	{
		if (*it == value)
			return (i);
		i++;
		it++;
	}
	return (-1);
}

#endif /* EASYFIND_HPP */
