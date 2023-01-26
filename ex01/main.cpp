#include "Span.hpp"
#include <iostream>
#include <stdlib.h>
#include <list>

int	main(void)
{
	Span sp = Span(10);

	srand(time(NULL));
	try
	{
		sp.addNumber(6);
		sp.addNumber(0);
		sp.addNumber(-2);
		sp.addNumber(2);
		sp.addNumber(3);
		Span sp2(sp);
		Span sp3(10);

		sp3.addNumber(1);
		sp3.addNumber(100);
		sp3 = sp;
		std::list<int> tmp;
		for (int idx = 0; idx < 5; idx++)
			tmp.push_back(rand() % 20);

		sp3.addNumber(tmp.begin(), tmp.end());
		sp3.showSpan();
		/*
		sp.addNumber(3);
		sp.addNumber(17);
		sp.addNumber(5);
		sp.addNumber(11);
		*/

		std::cout << sp3.shortestSpan() << std::endl;
		std::cout << sp3.longestSpan() << std::endl;
		
		Span sp4(10000);
		for (int idx = 0; idx < 10000; idx++)
			sp4.addNumber(rand() % 100000000);
		std::cout << sp4.shortestSpan() << std::endl;
		std::cout << sp4.longestSpan() << std::endl;
		
	}
	catch(std::exception& e)
	{
		std::cout << e.what() << std::endl;
	}
	return (0);
}
