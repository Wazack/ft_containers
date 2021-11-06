#include <iostream>
#include "Iterator.hpp"
#include "Bst.hpp"

namespace ft
{

template <class Iter>
class BstIterator : public ft::iterator<std::bidirectional_iterator_tag, Iter>
{
public:
	typedef typename ft::iterator<std::bidirectional_iterator_tag, Iter>::pointer	pointer;
	typedef typename ft::iterator<std::bidirectional_iterator_tag, Iter>::reference	reference;
	// typedef typename iterator_traits<iterator_type>::reference	reference;
	// typedef typename iterator_traits<iterator_type>::value_type	value_type;

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

	reference operator*() const {return *(_p->value);}

};

}