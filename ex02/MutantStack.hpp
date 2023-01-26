#ifndef _MUTANT_STACK_HPP
#define _MUTANT_STACK_HPP

#include <stack>
#include <iostream>

template <typename T>
class MutantStack : public std::stack<T>
{
public:
	typedef typename std::stack<T>::container_type::iterator				iterator;
	typedef typename std::stack<T>::container_type::const_iterator 			const_iterator;
	typedef typename std::stack<T>::container_type::reverse_iterator 		reverse_iterator;
	typedef typename std::stack<T>::container_type::const_reverse_iterator	const_reverse_iterator;
	
	MutantStack();
	~MutantStack();
	MutantStack(const MutantStack& rMu);
	MutantStack& operator=(const MutantStack& rMu);
	
	iterator				begin();
	const_iterator			cbegin();
	reverse_iterator		rbegin();
	const_reverse_iterator	crbegin();

	iterator				end();
	const_iterator			cend();
	reverse_iterator		rend();
	const_reverse_iterator	crend();
};


template <typename T>
MutantStack<T>::MutantStack()
{
	std::cout << "MutantStack Default Constructor Called\n";
}
	
template <typename T>
MutantStack<T>::~MutantStack()
{
	std::cout << "MutantStack Destructor Called\n";
}

template <typename T>
MutantStack<T>::MutantStack(const MutantStack<T>& rMu)
: std::stack<T>(rMu)
{
	std::cout << "MutantStack Copy Constructor Called\n";
}

template <typename T>
MutantStack<T>& MutantStack<T>::operator=(const MutantStack<T>& rMu)
{
	std::cout << "MutantStack Copy constructor Called\n";
	if (this == &rMu)
		return (*this);
	std::stack<T>::operator=(rMu);
	return (*this);
}

template <typename T>
typename MutantStack<T>::iterator MutantStack<T>::begin()
{
	return (this->c.begin());
}

template <typename T>
typename MutantStack<T>::const_iterator MutantStack<T>::cbegin()
{
	return (this->c.cbegin());
}

template <typename T>
typename MutantStack<T>::reverse_iterator MutantStack<T>::rbegin()
{
	return (this->c.rbegin());
}
	
template <typename T>
typename MutantStack<T>::const_reverse_iterator MutantStack<T>::crbegin()
{
	return (this->c.crbegin());
}	
		
template <typename T>
typename MutantStack<T>::iterator MutantStack<T>::end()
{
	return (this->c.end());
}

template <typename T>
typename MutantStack<T>::const_iterator MutantStack<T>::cend()
{
	return (this->c.cend());
}

template <typename T>
typename MutantStack<T>::reverse_iterator MutantStack<T>::rend()
{
	return (this->c.rend());
}

template <typename T>
typename MutantStack<T>::const_reverse_iterator MutantStack<T>::crend()
{
	return (this->c.crend());
}
#endif

