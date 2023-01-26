#ifndef _EASY_FIND_HPP
#define _EASY_FIND_HPP

#include <algorithm>
#include <stdexcept>
#include <iostream>

template<typename T>
void	easyfind(T& r, int n)
{
	typename T::iterator iter;
	
	iter = std::find(r.begin(), r.end(), n);
	if (iter == r.end())
	{
		std::cout << n << " is  ";
		throw std::invalid_argument("not Found!");
	}
}

#endif

