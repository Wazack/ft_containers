#include <iostream>
#include "Iterator.hpp"

namespace ft
{

template <class Iter>
class BstIterator
{
public:
	typedef	Iter														iterator_type;
	typedef typename iterator_traits<iterator_type>::iterator_category	iterator_category;
	typedef typename iterator_traits<iterator_type>::value_type			value_type;
	typedef typename iterator_traits<iterator_type>::difference_type	difference_type;
	typedef typename iterator_traits<iterator_type>::pointer			pointer;
	typedef typename iterator_traits<iterator_type>::reference			reference;

private:
	pointer p;

public:
	BstIterator() : p(nullptr){}
	BstIterator(pointer ptr) : p(ptr){}
	BstIterator(BstIterator const & src) : p(src.p){}
	~BstIterator(){}

	BstIterator & operator=(BstIterator const & rhs){
		this->p = rhs.p;
		return *this;
	}

	reference operator*(){
		return (*p);
	}
	
};

}