#include "../../../includes/stack.hpp"
#include <iostream>
#include <stack>

static void my_stack()
{
	ft::stack<int> stack;

	std::cout << "\x1B[92m------Stack Tester------\033[0m" << std::endl;
	std::cout << "\x1B[91m------ft::stack------\033[0m" << std::endl;

	std::cout << "stack empty: " << stack.empty() << std::endl;
	std::cout << "*push*" << std::endl;
	for (size_t i = 0; i < 10; i++)
	{
		std::cout << ' ' << i;
		stack.push(i);
	}
	std::cout << std::endl;
	std::cout << "top: " << stack.top() << std::endl;
	std::cout << "*pop*" << std::endl;
	stack.pop();
	std::cout << "top: " << stack.top() << std::endl;
	std::cout << "size: " << stack.size() << std::endl;
	std::cout << "empty: " << stack.empty() << std::endl;
}

static void stack()
{
	std::stack<int> stack;

	std::cout << "\x1B[91m------std::stack------\033[0m" << std::endl;

	std::cout << "stack empty: " << stack.empty() << std::endl;
	std::cout << "*push*" << std::endl;
	for (size_t i = 0; i < 10; i++)
	{
		std::cout << ' ' << i;
		stack.push(i);
	}
	std::cout << std::endl;
	std::cout << "top: " << stack.top() << std::endl;
	std::cout << "*pop*" << std::endl;
	stack.pop();
	std::cout << "top: " << stack.top() << std::endl;
	std::cout << "size: " << stack.size() << std::endl;
	std::cout << "empty: " << stack.empty() << std::endl;
}

void std_stack_tester()
{
	my_stack();
	std::cout << std::endl;
	stack();
}