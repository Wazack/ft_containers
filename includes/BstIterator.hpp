#include <iostream>
#include "Iterator.hpp"
#include "Bst.hpp"

namespace ft
{

template <class Iter>
class BstIterator
{
public:
	typedef typename Iter::pointer			pointer;

private:
	pointer _p;

public:
	BstIterator() : _p(nullptr){}
	BstIterator(pointer ptr) : _p(ptr){}
	BstIterator(BstIterator const & src) : _p(src._p){}
	~BstIterator(){}

	BstIterator & operator=(BstIterator const & rhs){
		this->_p = rhs._p;
		return *this;
	}

};

}