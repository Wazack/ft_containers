#include "Iterator.hpp"
#include "Utility.hpp"

namespace ft{
template <class Iter>
class MapIterator
{
public:
	typedef	Iter														iterator_type;
	typedef	typename iterator_traits<iterator_type>::iterator_category	iterator_category;
	typedef	typename iterator_traits<iterator_type>::value_type			value_type;
	typedef	typename iterator_traits<iterator_type>::difference_type	difference_type;
	typedef	typename iterator_traits<iterator_type>::pointer			pointer;
	typedef	typename iterator_traits<iterator_type>::reference			reference;

private:
	typedef bst<value_type> tree;

private:
	tree *_bst;

public:
	MapIterator() : _bst(NULL){}
	MapIterator(tree *bst) : _bst(bst){}
	MapIterator(MapIterator const & src) : _bst(src._bst){}
	// ~MapIterator();

	MapIterator & operator=(MapIterator const & rhs){
		_bst = rhs._bst;
		return *this;
	}

	reference operator*() const {return _bst->data;}

	MapIterator & operator++(){
		if (_bst->right == NULL)
		{
			while (_bst->data.first > _bst->parent->data.first)
				_bst = _bst->parent;
			_bst = _bst->parent;
		}
		else
			_bst = _bst->right;
		return (*this);
	}

	bool operator!=(MapIterator const & rhs) const{
		return _bst->data.first != rhs._bst->data.first;
	}
};


}