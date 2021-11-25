#include "../../../includes/map.hpp"
#include <map>
#include <iostream>

static void my_map()
{
	ft::map<char,int> first;

	first['a']=10;
	first['b']=30;
	first['c']=50;
	first['d']=70;

	ft::map<char,int> second(first.begin(),first.end());
	ft::map<char,int> third(first);
	ft::map<char,int> fourth = third;


	std::cout << "first:";
	for (ft::map<char, int>::iterator it = first.begin(); it != first.end(); ++it)
		std::cout << " " << it->first;
	std::cout << std::endl << std::endl;
	first.clear();
	std::cout << "*first.clear()*" << std::endl;
	std::cout << "second:";
	for (ft::map<char, int>::iterator it = second.begin(); it != second.end(); ++it)
		std::cout << " " << it->first;
	std::cout << std::endl << std::endl;
	std::cout << "third:";
	for (ft::map<char, int>::iterator it = third.begin(); it != third.end(); ++it)
		std::cout << " " << it->first;
	std::cout << std::endl << std::endl;
	std::cout << "fourth:";
	for (ft::map<char, int>::iterator it = fourth.begin(); it != fourth.end(); ++it)
		std::cout << " " << it->first;
	std::cout << std::endl;
}

static void map()
{
	std::map<char,int> first;

	first['a']=10;
	first['b']=30;
	first['c']=50;
	first['d']=70;

	std::map<char,int> second(first.begin(),first.end());
	std::map<char,int> third(first);
	std::map<char,int> fourth = third;


	std::cout << "first:";
	for (std::map<char, int>::iterator it = first.begin(); it != first.end(); ++it)
		std::cout << " " << it->first;
	std::cout << std::endl << std::endl;
	first.clear();
	std::cout << "*first.clear()*" << std::endl;
	std::cout << "second:";
	for (std::map<char, int>::iterator it = second.begin(); it != second.end(); ++it)
		std::cout << " " << it->first;
	std::cout << std::endl << std::endl;
	std::cout << "third:";
	for (std::map<char, int>::iterator it = third.begin(); it != third.end(); ++it)
		std::cout << " " << it->first;
	std::cout << std::endl << std::endl;
	std::cout << "fourth:";
	for (std::map<char, int>::iterator it = fourth.begin(); it != fourth.end(); ++it)
		std::cout << " " << it->first;
	std::cout << std::endl;
}

void std_map_constructor()
{
	std::cout << "\x1B[92m------Map constructor and copy------\033[0m" << std::endl;
	std::cout << "\x1B[91m------ft::map------\033[0m" << std::endl;
	my_map();
	std::cout << std::endl;
	std::cout << "\x1B[91m------std::map------\033[0m" << std::endl;
	map();
}