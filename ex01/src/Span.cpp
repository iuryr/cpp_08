#include "Span.hpp"

#include <stdexcept> //out_of_range
#include <algorithm> //min_element, max_element, sort
#include <limits> // numeric_limits
#include <iterator> //distance

Span::Span(void): _maxSize(0), _numbers()
{
}

Span::~Span(void)
{
}

Span::Span(const Span& obj)
{
	*this = obj;
}

Span& Span::operator=(const Span& obj)
{
	if (this != &obj)
	{
		_maxSize = obj._maxSize;
		_numbers = std::vector<int>(obj._numbers);
	}

	return *this;
}

Span::Span(unsigned int N): _maxSize(N), _numbers()
{
}

void Span::addNumber(int number)
{
	if (_numbers.size() + 1 > _maxSize)
	{
		throw std::out_of_range("Addition would exceed max size of Span");
	}
	
	_numbers.push_back(number);
}

int Span::shortestSpan(void)
{
	if (_numbers.size() < 2)
	{
		throw std::invalid_argument("Container size must be of at least 2");
	}

	std::sort(_numbers.begin(), _numbers.end());

	int min_span = std::numeric_limits<int>::max();

	for (size_t i = 1; i < _numbers.size(); i++)
	{
		int span = _numbers[i] - _numbers[i-1];
		if (span < min_span)
		{
			min_span = span;
		}
	}

	return min_span;
}

int Span::longestSpan(void)
{
	if (_numbers.size() < 2)
	{
		throw std::invalid_argument("Container size must be of at least 2");
	}

	std::sort(_numbers.begin(), _numbers.end());

	int longest_span;
	int min_element;
	int max_element;

	max_element = *std::max_element(_numbers.begin(), _numbers.end());
	min_element = *std::min_element(_numbers.begin(), _numbers.end());
	longest_span = max_element - min_element;


	return longest_span;
}
