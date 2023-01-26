#ifndef _SPAN_HPP
#define _SPAN_HPP

#include <exception>
#include <vector>
#include <iostream>

class	Span
{
public:
	class	NotFoundException : public std::exception
	{
	public:
		const char* what() const throw();	
	};
	class	OnlyOneFoundException : public std::exception
	{
	public:
		const char* what() const throw();
	};
	class	FullStoreException : public std::exception
	{
	public:
		const char* what() const throw();
	};
private:
	std::vector<int>	_v;
	unsigned int		_maxSize;
	unsigned int		_curCnt;
	
public:
	Span();
	explicit Span(unsigned int n);
	~Span();
	Span(const Span& rSpan);
	Span& operator=(const Span& rSpan);
	
	void	addNumber(int n);
	int		shortestSpan();
	int		longestSpan();
	void	showSpan();

	template<typename Iterator>
	void	addNumber(const Iterator& begin, const Iterator&  end)
	{
		try
		{
			if (_curCnt >= _maxSize)
				throw FullStoreException();
			_v.insert(_v.end(), begin, end);
			_curCnt = _v.size();
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
};

#endif

