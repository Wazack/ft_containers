#include "../../../includes/map.hpp"
#include <map>
#include <iostream>

static void my_map()
{
	ft::map<char,int> mymap;

	mymap['b'] = 100;
	mymap['a'] = 200;
	mymap['c'] = 300;

	// show content:


	for (ft::map<char,int>::iterator it=mymap.begin(); it!=mymap.end(); ++it)
		std::cout << it->first << " => " << it->second << '\n';
	std::cout << std::endl;
	for (ft::map<char,int>::const_iterator it=mymap.begin(); it!=mymap.end(); ++it)
		std::cout << it->first << " => " << it->second << '\n';
	std::cout << std::endl;
	for (ft::map<char,int>::iterator it=mymap.end(); it!=mymap.begin(); --it)
		std::cout << it->first << " => " << it->second << '\n';
	std::cout << std::endl;
	for (ft::map<char,int>::reverse_iterator it=mymap.rbegin(); it!=mymap.rend(); ++it)
		std::cout << it->first << " => " << it->second << '\n';
	std::cout << std::endl;
	for (ft::map<char,int>::const_reverse_iterator it=mymap.rbegin(); it!=mymap.rend(); ++it)
		std::cout << it->first << " => " << it->second << '\n';
	std::cout << std::endl;
}

static void map()
{
	std::map<char,int> mymap;

	mymap['b'] = 100;
	mymap['a'] = 200;
	mymap['c'] = 300;

	// show content:

	for (std::map<char,int>::iterator it=mymap.begin(); it!=mymap.end(); ++it)
		std::cout << it->first << " => " << it->second << '\n';
	std::cout << std::endl;
	for (std::map<char,int>::const_iterator it = mymap.begin(); it!=mymap.end(); ++it)
		std::cout << it->first << " => " << it->second << '\n';
	std::cout << std::endl;
	for (std::map<char,int>::iterator it=mymap.end(); it!=mymap.begin(); --it)
		std::cout << it->first << " => " << it->second << '\n';
	std::cout << std::endl;
	for (std::map<char,int>::reverse_iterator it=mymap.rbegin(); it!=mymap.rend(); ++it)
		std::cout << it->first << " => " << it->second << '\n';
	std::cout << std::endl;
	for (std::map<char,int>::const_reverse_iterator it=mymap.rbegin(); it!=mymap.rend(); ++it)
		std::cout << it->first << " => " << it->second << '\n';
}

void std_map_iterator()
{
	std::cout << "\x1B[92m------Map iterator------\033[0m" << std::endl;
	std::cout << "\x1B[91m------ft::map------\033[0m" << std::endl;
	my_map();
	std::cout << std::endl;
	std::cout << "\x1B[91m------std::map------\033[0m" << std::endl;
	map();
}