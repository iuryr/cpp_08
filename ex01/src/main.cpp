#include "Span.hpp"
#include "qolMacros.hpp"

#include <cstdlib> //srand, rand
#include <ctime> //time
#include <list>
#include <deque>

int main(void)
{
	Span sp = Span(5);
	sp.addNumber(6);
	sp.addNumber(3);
	sp.addNumber(17);
	sp.addNumber(9);
	sp.addNumber(11);
	std::cout << "Shortest span: " << sp.shortestSpan() << std::endl;
	std::cout << "Longest span: " << sp.longestSpan() << std::endl;
	println("");

	try
	{
		sp.addNumber(42);
	}
	catch (std::exception& e)
	{
		println(e.what());
	}
	println("");

	std::list<int> random_list;
	std::deque<int> random_deque;

	std::srand(std::time(NULL));

	for (unsigned int i = 0; i < 100000; i++)
	{
		random_list.push_back(rand());
		random_deque.push_back(rand());
	}

	Span span1(100000);
	Span span2(100000);

	span1.addRange(random_list.begin(), random_list.end());
	span2.addRange(random_deque.begin(), random_deque.end());
	
	println("Shortest span span1: " << span1.shortestSpan());
	println("Longest span span1: " << span1.longestSpan());
	println("");

	println("Shortest span span2: " << span2.shortestSpan());
	println("Longest span span2: " << span2.longestSpan());

	println("");
	println("Trying to addRange in a small Span");
	Span span3(10);
	try
	{
		span3.addRange(random_list.begin(), random_list.end());
	}
	catch (std::exception& e)
	{
		println(e.what());
	}

	return 0;
};
