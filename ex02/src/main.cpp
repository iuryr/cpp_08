#include "MutantStack.hpp"
#include "qolMacros.hpp"

#include <list>
#include <ctime>
#include <cstdlib>
#include <stack>

int main(void)
{
	srand(time(NULL));
	MutantStack<int> mstack;
	std::list<int> list;

	println("Let's generate an empty Mutant Stack and add 0 for first element and another 10 random elements.");
	println("Also, we're generating a std::list and populating it with the same values. We'll use them later");
	mstack.push(0);
	for (int i = 0; i < 10; i++)
	{
		int value = rand();
		mstack.push(value);
		list.push_back(value);
	}


	MutantStack<int>::iterator it = mstack.begin();
	MutantStack<int>::iterator ite = mstack.end();

	++it;
	--it;

	println("Let's print the values in the Mutant Stack");
	while (it != ite)
	{
		println(*it);
		it++;
	};

	println("");
	println("Now let's pop the top element, reset the iterators and reprint the values of MutantStack:");
	mstack.pop();
	it = mstack.begin();
	ite = mstack.end();
	while (it != ite)
	{
		println(*it);
		it++;
	};

	println("");
	println("Now let's use iterators to print the values in the list");

	std::list<int>::iterator lit = list.begin();
	std::list<int>::iterator lite = list.end();

	while (lit != lite)
	{
		println(*lit);
		lit++;
	}

	std::stack<int> s(mstack);
	return (0);
};
