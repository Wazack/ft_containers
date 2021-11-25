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
	typedef std::bidirectional_iterator_tag			iterator_category;
	typedef typename iterator_type::value_type	value_type;
	typedef typename iterator_type::pointer	pointer;
	typedef typename iterator_type::reference	reference;
	typedef typename iterator_type::difference_type	difference_type;

	typedef tree<value_type>	tree;
	typedef tree*				tree_pointer;

private:
	tree_pointer	_tree;
	value_type		_val;

public:
	BstIterator() : _tree(nullptr){}
	BstIterator(tree_pointer ptr) : _tree(ptr), _val(ptr->value){}
	BstIterator(BstIterator const & src) : _tree(src._tree), _val(src._val){}
	~BstIterator(){}

	BstIterator & operator=(BstIterator const & rhs){
		_tree = rhs._tree;
		return *this;
	}

	reference operator*() const {
		return (_tree->value);
	}

	pointer operator->() const {
		return &(_tree->value);
	}

	BstIterator & operator++(){
		tree_pointer prev;

		if (_tree->right != nullptr)
		{
			prev = _tree;
			_tree = _tree->right;
			while (_tree->left)
				_tree = _tree->left;
			return *this;
		}
		prev = _tree;
		_tree = _tree->parent;
		if (_tree->value.first > prev->value.first)
			return *this;
		while (_tree->value.first < prev->value.first)
		{
			prev = _tree;
			_tree = _tree->parent;
		}
		return *this;
	}

	BstIterator operator++(int){
		BstIterator	tmp(*this);

		++(*this);
		return tmp;
	}

	BstIterator & operator--(){
		tree_pointer prev;

		if (_tree->left != nullptr)
		{
			prev = _tree;
			_tree = _tree->left;
			while (_tree->right)
				_tree = _tree->right;
			return *this;
		}
		prev = _tree;
		_tree = _tree->parent;
		if (prev->value == value_type() || _tree->value.first < prev->value.first)
			return *this;
		while (_tree->value.first > prev->value.first)
		{
			prev = _tree;
			_tree = _tree->parent;
		}
		return *this;
	}

	BstIterator operator--(int){
		BstIterator tmp(*this);

		--(*this);
		return tmp;
	}

	friend bool operator==(const BstIterator& x, const BstIterator& y){return x._tree == y._tree;}
	
	friend bool operator!=(const BstIterator& x, const BstIterator& y){return x._tree != y._tree;}

	template <class> friend class BstConstIterator;
};

template <class Iter>
class BstConstIterator : public ft::iterator<std::bidirectional_iterator_tag, Iter>
{
public:
	typedef ft::iterator<std::bidirectional_iterator_tag, Iter>	iterator_type;
	typedef std::bidirectional_iterator_tag			iterator_category;
	typedef typename iterator_type::value_type	value_type;
	typedef typename iterator_type::pointer	pointer;
	typedef typename iterator_type::reference	reference;
	typedef typename iterator_type::difference_type	difference_type;

	typedef tree<value_type>	tree;
	typedef tree*				tree_pointer;

private:
	value_type		_val;
	tree_pointer	_tree;

public:
	BstConstIterator() : _tree(){}
	BstConstIterator(tree_pointer ptr) : _val(ptr->value), _tree(ptr){}
	BstConstIterator(BstIterator<Iter> const & src) : _val(src._val), _tree(src._tree){}
	~BstConstIterator(){}

	BstConstIterator & operator=(BstIterator<Iter> const & rhs){
		_tree = rhs._tree;
		return *this;
	}

	reference operator*() const {
		return (_tree->value);
	}

	pointer operator->() const {
		return &(_tree->value);
	}

	BstConstIterator & operator++(){
		tree_pointer prev;

		if (_tree->right != nullptr)
		{
			prev = _tree;
			_tree = _tree->right;
			while (_tree->left)
				_tree = _tree->left;
			return *this;
		}
		prev = _tree;
		_tree = _tree->parent;
		if (_tree->value.first > prev->value.first)
			return *this;
		while (_tree->value.first < prev->value.first)
		{
			prev = _tree;
			_tree = _tree->parent;
		}
		return *this;
	}

	BstConstIterator operator++(int){
		BstConstIterator	tmp(*this);

		++(*this);
		return tmp;
	}

	BstConstIterator & operator--(){
		tree_pointer prev;

		if (_tree->left != nullptr)
		{
			prev = _tree;
			_tree = _tree->left;
			while (_tree->right)
				_tree = _tree->right;
			return *this;
		}
		prev = _tree;
		_tree = _tree->parent;
		if (prev->value == value_type() || _tree->value.first < prev->value.first)
			return *this;
		while (_tree->value.first > prev->value.first)
		{
			prev = _tree;
			_tree = _tree->parent;
		}
		return *this;
	}

	BstConstIterator operator--(int){
		BstConstIterator tmp(*this);

		--(*this);
		return tmp;
	}

	friend bool operator==(const BstConstIterator& x, const BstConstIterator& y){return x._tree == y._tree;}
	
	friend bool operator!=(const BstConstIterator& x, const BstConstIterator& y){return x._tree != y._tree;}
};

}