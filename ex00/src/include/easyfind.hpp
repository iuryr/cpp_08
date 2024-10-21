#ifndef _EASYFIND_HPP_
#define _EASYFIND_HPP_

#include <algorithm>
#include <stdexcept> //runtime_error exception

template<typename T>
typename T::iterator easyfind(T container, int number)
{
	typename T::iterator match;

	match = std::find(container.begin(), container.end(), number);

	if (match == container.end())
	{
		throw std::runtime_error("Value not found in container");
	}

	return match;
};

#endif //__EASYFIND_HPP_
