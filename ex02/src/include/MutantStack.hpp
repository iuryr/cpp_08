#ifndef _MUTANT_STACK_HPP_
#define _MUTANT_STACK_HPP_

#include <stack>
#include <deque>

template<typename T, typename Container = std::deque<T> >
class MutantStack: public std::stack<T, Container>
{
public:
	MutantStack(void);
	~MutantStack(void);
	MutantStack(const MutantStack& obj);
	MutantStack& operator=(const MutantStack& obj);

	class iterator
	{
	private:
		typename Container::iterator _it;

	public:
		iterator(void);
		~iterator(void);
		iterator(const iterator& obj);
		iterator& operator=(const iterator& obj);

		iterator(typename Container::iterator it);
		T& operator*(void); //dereference
		iterator& operator++(void); //pre-increment
		iterator operator++(int); //post-increment
		iterator& operator--(void); //pre-decrement
		iterator operator--(int); //post-decrement
		bool operator==(const iterator& obj) const;
		bool operator!=(const iterator& obj) const;
	};

	iterator begin(void);
	iterator end(void);
};

#include "MutantStack.tpp"

#endif //_MUTANT_STACK_HPP_
