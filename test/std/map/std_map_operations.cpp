#include "../../../includes/map.hpp"
#include <map>
#include <iostream>

static void my_map()
{
	ft::map<char, int> foo;
	ft::map<char, int>::iterator it;
	ft::pair<ft::map<char,int>::iterator,ft::map<char,int>::iterator> ret;

	foo['a'] = 100;
	foo['d'] = 200;
	foo['k'] = 300;
	std::cout << "foo.count('a'): " << foo.count('a') << std::endl;
	std::cout << "foo.count('g'): " << foo.count('g') << std::endl;
	std::cout << std::endl;

	it = foo.lower_bound('b');
	std::cout << "it = foo.lower_bound(b): ";
	std::cout << "it: " << it->first << ", " << it->second << std::endl;

	it = foo.lower_bound('l');
	std::cout << "it = foo.lower_bound(l): ";
	std::cout << "it: " << it->first << ", " << it->second << std::endl;
	std::cout << std::endl;
	
	it = foo.upper_bound('d');
	std::cout << "it = foo.upper_bound(d): ";
	std::cout << "it: " << it->first << ", " << it->second << std::endl;

	it = foo.upper_bound('l');
	std::cout << "it = foo.upper_bound(l): ";
	std::cout << "it: " << it->first << ", " << it->second << std::endl;
	std::cout << std::endl;

	ret = foo.equal_range('d');
	std::cout << "ret = foo.equal_range(d): " << std::endl;
	std::cout << "lower bound points to: ";
	std::cout << ret.first->first << " => " << ret.first->second << '\n';

	std::cout << "upper bound points to: ";
	std::cout << ret.second->first << " => " << ret.second->second << '\n';
	std::cout << std::endl;

	ret = foo.equal_range('l');
	std::cout << "ret = foo.equal_range(d): " << std::endl;
	std::cout << "lower bound points to: ";
	std::cout << ret.first->first << " => " << ret.first->second << '\n';
}

static void map()
{
	std::map<char, int> foo;
	std::map<char, int>::iterator it;
	std::pair<std::map<char,int>::iterator,std::map<char,int>::iterator> ret;

	foo['a'] = 100;
	foo['d'] = 200;
	foo['k'] = 300;
	std::cout << "foo.count('a'): " << foo.count('a') << std::endl;
	std::cout << "foo.count('g'): " << foo.count('g') << std::endl;
	std::cout << std::endl;

	it = foo.lower_bound('b');
	std::cout << "it = foo.lower_bound(b): ";
	std::cout << "it: " << it->first << ", " << it->second << std::endl;

	it = foo.lower_bound('l');
	std::cout << "it = foo.lower_bound(l): ";
	std::cout << "it: " << it->first << ", " << it->second << std::endl;
	std::cout << std::endl;
	
	it = foo.upper_bound('d');
	std::cout << "it = foo.upper_bound(d): ";
	std::cout << "it: " << it->first << ", " << it->second << std::endl;

	it = foo.upper_bound('l');
	std::cout << "it = foo.upper_bound(l): ";
	std::cout << "it: " << it->first << ", " << it->second << std::endl;
	std::cout << std::endl;

	ret = foo.equal_range('d');
	std::cout << "ret = foo.equal_range(d): " << std::endl;
	std::cout << "lower bound points to: ";
	std::cout << ret.first->first << " => " << ret.first->second << '\n';

	std::cout << "upper bound points to: ";
	std::cout << ret.second->first << " => " << ret.second->second << '\n';
	std::cout << std::endl;

	ret = foo.equal_range('l');
	std::cout << "ret = foo.equal_range(d): " << std::endl;
	std::cout << "lower bound points to: ";
	std::cout << ret.first->first << " => " << ret.first->second << '\n';
}

void std_map_operations()
{
	std::cout << "\x1B[92m------Map operations------\033[0m" << std::endl;
	std::cout << "\x1B[91m------ft::map------\033[0m" << std::endl;
	my_map();
	std::cout << std::endl;
	std::cout << "\x1B[91m------std::map------\033[0m" << std::endl;
	map();
}