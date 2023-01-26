#include "easyfind.hpp"
#include <iostream>
#include <algorithm>
#include <vector>
#include <list>

void	show(int n)
{
	std::cout << n << " ";
}

int	main()
{
	std::vector<int> v;
	std::list<int> l;

	for (unsigned int idx = 0; idx < 5; idx++)
		v.push_back(idx);
	std::copy(v.begin(), v.end(), std::insert_iterator<std::list<int> >(l, l.begin()));
	std::for_each(v.begin(), v.end(), show);
	std::cout << std::endl;

	std::for_each(l.begin(), l.end(), show);
	std::cout << std::endl;

	try
	{	
		const std::vector<int> v2(v);
		std::for_each(v2.begin(), v2.end(), show);
		std::cout << std::endl;
		easyfind(v2, 1);
		std::cout << "1 is Found!\n";


		easyfind(v, 1);
		std::cout << "1 is Found!\n";

		easyfind(l, 10);
		std::cout << "10 is Found!\n";
	}
	catch(std::exception &e)
	{
		std::cout << e.what() << std::endl;
	}
	return (0);
}
