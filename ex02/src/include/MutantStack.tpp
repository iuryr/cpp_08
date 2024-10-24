#include "MutantStack.hpp"

template<typename T, typename Container>
MutantStack<T, Container>::MutantStack(void)
{
}

template<typename T, typename Container>
MutantStack<T, Container>::~MutantStack(void)
{
}

template<typename T, typename Container>
MutantStack<T, Container>::MutantStack(const MutantStack& obj)
{
	*this = obj;
}

template<typename T, typename Container>
MutantStack<T, Container>& MutantStack<T, Container>::operator=(const MutantStack& obj)
{
	if (this != &obj)
	{
		this->c = obj.c;
	}

	return *this;
}

template<typename T, typename Container>
MutantStack<T, Container>::iterator::iterator(void) : _it(0)
{
};

template<typename T, typename Container>
MutantStack<T, Container>::iterator::~iterator(void)
{
};

template<typename T, typename Container>
MutantStack<T, Container>::iterator::iterator(const iterator& obj)
{
	*this = obj;
};


template<typename T, typename Container>
typename MutantStack<T, Container>::iterator& MutantStack<T, Container>::iterator::operator=(const iterator& obj)
{
	if (this != &obj)
	{
		_it = obj._it;
	}

	return *this;
};

template<typename T, typename Container>
MutantStack<T, Container>::iterator::iterator(typename Container::iterator it): _it(it)
{
};

template<typename T, typename Container>
T& MutantStack<T, Container>::iterator::operator*(void) 
{
	return *_it;
};

template<typename T, typename Container>
typename MutantStack<T, Container>::iterator MutantStack<T, Container>::begin(void)
{
	return this->c.begin();
}

template<typename T, typename Container>
typename MutantStack<T, Container>::iterator MutantStack<T, Container>::end(void)
{
	return this->c.end();
}

template<typename T, typename Container>
typename MutantStack<T, Container>::iterator& MutantStack<T, Container>::iterator::operator++(void)
{
	++_it;
	
	return *this;
}

template<typename T, typename Container>
typename MutantStack<T, Container>::iterator MutantStack<T, Container>::iterator::operator++(int)
{
	MutantStack::iterator temp = *this;
	++_it;
	
	return temp;
}

template<typename T, typename Container>
typename MutantStack<T, Container>::iterator& MutantStack<T, Container>::iterator::operator--(void)
{
	--_it;
	
	return *this;
}

template<typename T, typename Container>
typename MutantStack<T, Container>::iterator MutantStack<T, Container>::iterator::operator--(int)
{
	MutantStack::iterator temp = *this;
	--_it;
	
	return temp;
}

template<typename T, typename Container>
bool MutantStack<T, Container>::iterator::operator==(const MutantStack<T, Container>::iterator& obj) const
{
	if (this->_it == obj._it)
	{
		return true;
	}
	return false;
};

template<typename T, typename Container>
bool MutantStack<T, Container>::iterator::operator!=(const MutantStack<T, Container>::iterator& obj) const
{
	if (this->_it != obj._it)
	{
		return true;
	}
	return false;
};
