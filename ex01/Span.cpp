#include "Span.hpp"
#include <iostream>
#include <algorithm>

Span::Span()
: _maxSize(0), _curCnt(0)
{
	std::cout << "Span Default Constructor Called\n";
}

Span::Span(unsigned int n)
: _maxSize(n), _curCnt(0)
{
	std::cout << "Span Non Default Constructor Called\n";
}

Span::~Span()
{
	std::cout << "Span Destructor Called\n";
}

Span::Span(const Span& rSpan)
: _maxSize(rSpan._maxSize), _curCnt(rSpan._curCnt)
{
	std::cout << "Span Copy Constructor Called\n";
	copy(rSpan._v.begin(), rSpan._v.end(), std::insert_iterator<std::vector<int> >(_v, _v.begin()));
}

Span& Span::operator=(const Span& rSpan)
{
	std::cout << "Span Copy Operator Called\n";
	if (this == &rSpan)
		return (*this);
	_maxSize = rSpan._maxSize;
	_curCnt = rSpan._curCnt;
	_v.clear();
	copy(rSpan._v.begin(), rSpan._v.end(), std::insert_iterator<std::vector<int> >(_v, _v.begin()));
	return (*this);	
}

void	Span::addNumber(int n)
{
	try
	{
		if (_curCnt == _maxSize)
			throw FullStoreException();
		_v.push_back(n);
		_curCnt++;
	}
	catch(std::bad_alloc& e)
	{
		std::cout << e.what() << std::endl;
		exit(1);
	}
	catch(std::exception& e)
	{
		throw;
	}
}

int	Span::shortestSpan()
{
	size_t	length = _v.size();
	
	if (length == 0)
		throw NotFoundException();
	if (length == 1)
		throw OnlyOneFoundException();
	
	std::vector<int> tmp(_v);
	sort(tmp.begin(), tmp.end());

	size_t	shortestDist = abs(tmp[0] - tmp[1]);
	size_t	curDist;

	for(size_t idx = 0; idx < length - 1; idx++)
	{
		curDist = abs(tmp[idx] - tmp[idx + 1]);
		if (curDist < shortestDist)
			shortestDist = curDist;
	}
	return (shortestDist);
}
	
int	Span::longestSpan()
{
	size_t	length = _v.size();

	if (length == 0)
		throw NotFoundException();
	if (length == 1)
		throw OnlyOneFoundException();
	
	std::vector<int> tmp(_v);
	sort(tmp.begin(), tmp.end());
	return (abs(tmp[0] - tmp[length - 1]));
}

const char* Span::NotFoundException::what() const throw()
{
	return ("No numbers Stored");
}

const char* Span::OnlyOneFoundException::what() const throw()
{
	return ("Only One number Found!\n");
}

const char* Span::FullStoreException::what() const throw()
{
	return ("Fully Stored!");
}
