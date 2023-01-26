#include "MutantStack.hpp"
#include <iostream>
#include <stack>
#include <list>
#include <algorithm>


void	print(int n)
{
	std::cout << n << std::endl;
}

int	main()
{
	MutantStack<int> mstack;
	
	mstack.push(5);
	mstack.push(17);
	
	std::cout << mstack.top() << std::endl;
	mstack.pop();

	std::cout << mstack.size() << std::endl;
	std::cout << "=====================\n";	
	mstack.push(3);
	mstack.push(5);
	mstack.push(737);
	mstack.push(0);

	MutantStack<int>::iterator it = mstack.begin();
	MutantStack<int>::iterator ite = mstack.end();
	//MutantStack<int>::container_type::iterator it = mstack.begin();
	//MutantStack<int>::container_type::iterator ite = mstack.end();

	++it;
	--it;

	while (it != ite)
	{
		std::cout << *it << std::endl;
		++it;
	}
	std::cout << "Copy Operator Test!\n";
	MutantStack<int> mstack2;
	mstack2.push(1);
	mstack2.push(100);
	mstack2 = mstack;
	for_each(mstack2.begin(), mstack2.end(), print);

	std::cout << "Copy Constructor Test!\n";
	MutantStack<int> mstack3(mstack2);
	for_each(mstack3.begin(), mstack3.end(), print);


	std::cout << "============stack==============\n";
	std::stack<int> s(mstack);
	size_t len = s.size();
	for(size_t idx = 0; idx < len; idx++)
	{
		std::cout << s.top() << std::endl;
		s.pop();
	}

	std::cout << "============list===================\n";
	std::list<int> l(mstack.begin(), mstack.end());
	for_each(l.begin(), l.end(), print);


	std::cout << "mutant Stack reverse iterator test!=========\n";
	for_each(mstack.rbegin(), mstack.rend(), print);
	return (0);
}
