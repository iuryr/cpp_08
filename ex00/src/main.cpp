#include <vector>
#include <list>
#include <deque>
#include "easyfind.hpp"
#include "qolMacros.hpp"

int main(void)
{
	int ints_array[] = {10,20,30,40,50};

	println("Testing with Vector");
	std::vector<int> int_vector(ints_array,
							 ints_array +  sizeof(ints_array) / sizeof(int));

	try
	{
		println(*easyfind(int_vector, 10));
		println(*easyfind(int_vector, 30));
		println(*easyfind(int_vector, 42));
	}
	catch (std::exception& e)
	{
		println(e.what());
	}
	println("");

	println("Testing with List");
	std::list<int> int_list(ints_array,
							 ints_array +  sizeof(ints_array) / sizeof(int));

	try
	{
		println(*easyfind(int_list, 10));
		println(*easyfind(int_list, 30));
		println(*easyfind(int_list, 42));
	}
	catch (std::exception& e)
	{
		println(e.what());
	}
	println("");

	println("Testing with Deque");
	std::deque<int> int_deque(ints_array,
							 ints_array +  sizeof(ints_array) / sizeof(int));

	try
	{
		println(*easyfind(int_deque, 10));
		println(*easyfind(int_deque, 30));
		println(*easyfind(int_deque, 42));
	}
	catch (std::exception& e)
	{
		println(e.what());
	}
	println("");

}
