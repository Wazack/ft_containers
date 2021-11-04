#include "../../includes/vector.hpp"
#include <iostream>
#include <vector>

static void my_vec()
{
	ft::vector<int> myvector (3,100);
	ft::vector<int>::iterator it;
	std::cout << "\x1B[92m------Vector modifier------\033[0m" << std::endl;
	std::cout << "\x1B[91m------ft::vector------\033[0m" << std::endl;

	it = myvector.begin();
	it = myvector.insert ( it , 200 );
	it = myvector.insert ( it , 300 );
	it = myvector.insert ( it , 400 );
	it = myvector.insert ( it , 1201 );

	myvector.insert (it, 200, 300);

	it = myvector.begin();

	// ft::vector<int> anothervector (2,400);
	// myvector.insert (it+2,anothervector.begin(),anothervector.end());

	// int myarray [] = { 501,502,503 };
	// myvector.insert (myvector.begin(), myarray, myarray+3);

	std::cout << "myvector contains:";
	for (it=myvector.begin(); it<myvector.end(); it++)
		std::cout << ' ' << *it;
	std::cout << '\n';
}

static void vec()
{
	std::vector<int> myvector (3,100);
	std::vector<int>::iterator it;
	std::cout << "\x1B[91m------std::vector------\033[0m" << std::endl;

	it = myvector.begin();
	it = myvector.insert ( it , 200 );
	it = myvector.insert ( it , 300 );
	it = myvector.insert ( it , 400 );
	it = myvector.insert ( it , 1201 );

	myvector.insert (it,200,300);

	it = myvector.begin();

	// std::vector<int> anothervector (2,400);
	// myvector.insert (it+2,anothervector.begin(),anothervector.end());

	// int myarray [] = { 501,502,503 };
	// myvector.insert (myvector.begin(), myarray, myarray+3);

	std::cout << "myvector contains:";
	for (it=myvector.begin(); it<myvector.end(); it++)
		std::cout << ' ' << *it;
	std::cout << '\n';
}

void vector_modifier()
{
	my_vec();
	std::cout << std::endl;
	vec();
}