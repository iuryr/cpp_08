#ifndef _SPAN_HPP_
#define _SPAN_HPP_

#include <vector>

class Span
{
public:
	Span(void);
	~Span(void);
	Span(const Span& obj);
	Span& operator=(const Span& obj);

	Span(unsigned int N);
	void addNumber(int number);
	int shortestSpan(void);
	int longestSpan(void);

	template<typename InputIterator>
	void addRange(InputIterator begin, InputIterator end);

private:
	unsigned int _maxSize;
	std::vector<int> _numbers;
};

#endif //_SPAN_HPP_
