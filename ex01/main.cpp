#include "Span.hpp"
#include <iostream>
#include <stdlib.h>

int	main(void)
{
	Span sp = Span(5);

	try
	{
		sp.addNumber(6);
		sp.addNumber(0);
		sp.addNumber(-2);
		sp.addNumber(2);
		sp.addNumber(3);
		Span sp2(sp);
		Span sp3(5);

		sp3.addNumber(1);
		sp3.addNumber(100);
		sp3 = sp;
		/*
		sp.addNumber(3);
		sp.addNumber(17);
		sp.addNumber(5);
		sp.addNumber(11);
		*/

		std::cout << sp3.shortestSpan() << std::endl;
		std::cout << sp3.longestSpan() << std::endl;
		
		Span sp4(10000);
		srand(time(NULL));
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
