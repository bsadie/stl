#include <iostream>
#include <string>
#include <deque>
#if 1 //CREATE A																																																																																											 REAL STL EXAMPLE
	#include <map>
	#include <stack>
	#include <vector>
	//namespace ft = std;
#else
	#include <map.hpp>
	#include <stack.hpp>
	#include <vector.hpp>
#endif

#include <stdlib.h>
#include "ft_vector.hpp"
//#include "ft_stack.hpp"
//#include "ft_iterator.hpp"
/*
#define MAX_RAM 100
#define BUFFER_SIZE 10
struct Buffer
{
	int idx;
	char buff[BUFFER_SIZE];
};
*/

#define COUNT 10
/*
template<typename T>
class MutantStack : public ft::stack<T>
{
public:
	MutantStack() {}
	MutantStack(const MutantStack<T>& src) { *this = src; }
	MutantStack<T>& operator=(const MutantStack<T>& rhs) 
	{
		this->c = rhs.c;
		return *this;
	}
	~MutantStack() {}

	typedef typename ft::stack<T>::container_type::iterator iterator;

	iterator begin() { return this->c.begin(); }
	iterator end() { return this->c.end(); }
};
*/

int main(int argc, char** argv) {


	(void)argc;
	(void)argv;

	ft::vector<int> tmp;
	tmp.push_back(3);
	tmp.pop_back();

	//std::cout << tmp.at(0) << std::endl;
/*
	std::vector<int> tmp;
	tmp.push_back(1);
	tmp.push_back(2);
	ft::stack<int> int_vector(tmp);
	ft::stack<int> int_vector2;
	if (int_vector==int_vector2)
		std::cout << "==" << std::endl;
	else
		std::cout << "!=" << std::endl;
	int_vector2.pop();
	int_vector2.pop();
	int_vector2.pop();
*/
	//int_vector.push(4);
	//std::cout << int_vector.top() << std::endl;
	//int_vector.test();
	/*
	ft::stack<std::string> str_vector;
	std::cout << std::boolalpha <<str_vector.empty() << std::endl;
	str_vector.push("test");
	std::cout << str_vector.empty() << std::endl;
	std::cout << str_vector.top() << std::endl;
	str_vector.test();
	*/
	//ft::vector<std::string> vector_str;
	//ft::vector<int> vector_int;
	/*
	ft::stack<int> stack_int;
	ft::vector<Buffer> vector_buffer;
	ft::stack<Buffer, std::deque<Buffer> > stack_deq_buffer;
	ft::map<int, int> map_int;
	*/
	//for (int i = 0; i < COUNT; i++)
	//	vector_int.push_back(i);
	//ft::cout << vector_int[5] << ft::endl;
}


/*
	for (int i = 0; i < COUNT; i++)
	{
		const int idx = rand() % COUNT;
		vector_buffer[idx].idx = 5;
	}
	ft::vector<Buffer>().swap(vector_buffer);

	try
	{
		for (int i = 0; i < COUNT; i++)
		{
			const int idx = rand() % COUNT;
			vector_buffer.at(idx);
			std::cerr << "Error: THIS VECTOR SHOULD BE EMPTY!!" <<std::endl;
		}
	}
	catch(const std::exception& e)
	{
		//NORMAL ! :P
	}
	
	for (int i = 0; i < COUNT; ++i)
	{
		map_int.insert(ft::make_pair(rand(), rand()));
	}

	int sum = 0;
	for (int i = 0; i < 10000; i++)
	{
		int access = rand();
		sum += map_int[access];
	}
	std::cout << "should be constant with the same seed: " << sum << std::endl;

	{
		ft::map<int, int> copy = map_int;
	}
	MutantStack<char> iterable_stack;
	for (char letter = 'a'; letter <= 'z'; letter++)
		iterable_stack.push(letter);
	for (MutantStack<char>::iterator it = iterable_stack.begin(); it != iterable_stack.end(); it++)
	{
		std::cout << *it;
	}
	std::cout << std::endl;
	return (0);
}
*/