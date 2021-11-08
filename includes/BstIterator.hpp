#include <iostream>
#include "Iterator.hpp"
#include "Bst.hpp"

namespace ft
{

template <class T>
struct tree;


template <class Iter>
class BstIterator : public ft::iterator<std::bidirectional_iterator_tag, Iter>
{
public:
	typedef ft::iterator<std::bidirectional_iterator_tag, Iter>	iterator_type;
	typedef typename iterator_type::value_type	value_type;
	typedef typename iterator_type::pointer	pointer;
	typedef typename iterator_type::reference	reference;

	typedef tree<value_type>	tree;
	typedef tree*				tree_pointer;

private:
	value_type		_val;
	tree_pointer	_tree;

public:
	BstIterator() : _tree(nullptr){}
	BstIterator(tree_pointer ptr) : _val(ptr->value), _tree(ptr){}
	BstIterator(BstIterator const & src) : _val(src._val), _tree(src._tree){}
	~BstIterator(){}

	BstIterator & operator=(BstIterator const & rhs){
		_tree = rhs._tree;
		_val = rhs._val;
		return *this;
	}

	reference operator*() const {
		return (_tree->value);
	}

	pointer operator->() const {
		return &(_tree->value);
	}

	BstIterator & operator++(){
		tree_pointer buf;

		if (_tree->right == nullptr)
		{
			while (_tree->right == buf)
		}
	}

};

}