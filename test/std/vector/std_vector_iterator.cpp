#include "../../../includes/vector.hpp"
#include <iostream>
#include <vector>

static void vec()
{
	std::vector<int> i_vec;
	std::vector<std::string> s_vec;
	for (size_t i = 0; i < 8; i++)
		i_vec.push_back(i);
	s_vec.push_back("bonjour ");
	s_vec.push_back("tout ");
	s_vec.push_back("le ");
	s_vec.push_back("monde !");
	std::cout << "\x1B[91m------std::vector------\033[0m" << std::endl;

	for (std::vector<int>::iterator it = i_vec.begin(); it != i_vec.end(); ++it)
		std::cout << *it;
	std::cout << std::endl;
	for (std::vector<std::string>::iterator it = s_vec.begin(); it != s_vec.end(); ++it)
		std::cout << *it;
	std::cout << std::endl;
	for (std::vector<int>::reverse_iterator it = i_vec.rbegin(); it != i_vec.rend(); ++it)
		std::cout << *it;
	std::cout << std::endl;
	for (std::vector<std::string>::reverse_iterator it = s_vec.rbegin(); it != s_vec.rend(); ++it)
		std::cout << *it;
	std::cout << std::endl;
}

static void my_vec()
{
	ft::vector<int> i_vec;
	ft::vector<std::string> s_vec;
	for (size_t i = 0; i < 8; i++)
		i_vec.push_back(i);
	s_vec.push_back("bonjour ");
	s_vec.push_back("tout ");
	s_vec.push_back("le ");
	s_vec.push_back("monde !");
	std::cout << "\x1B[92m------Vector iterator------\033[0m" << std::endl;
	std::cout << "\x1B[91m------ft::vector------\033[0m" << std::endl;

	for (ft::vector<int>::iterator it = i_vec.begin(); it != i_vec.end(); ++it)
		std::cout << *it;
	std::cout << std::endl;
	for (ft::vector<std::string>::iterator it = s_vec.begin(); it != s_vec.end(); ++it)
		std::cout << *it;
	std::cout << std::endl;
	for (ft::vector<int>::reverse_iterator it = i_vec.rbegin(); it != i_vec.rend(); ++it)
		std::cout << *it;
	std::cout << std::endl;
	for (ft::vector<std::string>::reverse_iterator it = s_vec.rbegin(); it != s_vec.rend(); ++it)
		std::cout << *it;
	
	std::cout << std::endl;
}

void std_vector_iterator()
{
	my_vec();
	std::cout << std::endl;
	vec();
}