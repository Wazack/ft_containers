#ifndef BST_HPP
#define BST_HPP

#include <iostream>
#include "Utility.hpp"
#include "BstIterator.hpp"

namespace ft
{

template <class T>
class BstIterator; 

template <class T>
struct tree
{
public:

	typedef	T	value_type;

	value_type	value;
	tree*		parent;
	tree*		left;
	tree*		right;

	tree() : value(), parent(nullptr), left(nullptr), right(nullptr){}

	tree(tree* parent = nullptr, tree* left = nullptr, tree* right = nullptr) : value(), parent(parent), left(left), right(right){} 

	tree(const value_type& val, tree* parent, tree* left, tree* right) : value(val), parent(parent), left(left), right(right){}
};

template <class T, class Compare = std::less<T>, class Alloc = std::allocator<tree<T> > >
class Bst
{
public:
	typedef T									value_type;
	typedef tree<T>								tree;
	typedef Alloc								allocator_type;
	typedef tree&								tree_reference;
	typedef tree*								tree_pointer;
	typedef value_type&							reference;
	typedef value_type*							pointer;
	typedef BstIterator<tree>				iterator;
	typedef std::bidirectional_iterator_tag		iterator_category;
	typedef ptrdiff_t							difference_type;

	typedef size_t								size_type;

private:
	allocator_type	_alloc_tree;
	tree_pointer	_root;
	size_type		_size;

public:
	Bst(const allocator_type& alloc = allocator_type()) : _alloc_tree(alloc), _size(0){
		_root = _alloc_tree.allocate(1);
		_alloc_tree.construct(_root, tree(_root, _root, _root));
		_root = nullptr;
	}

	~Bst(){}

	iterator begin(){
		return (iterator(_root));
	}

	bool insert(const value_type& val){ //Replace by ft::pair
		if (_root == nullptr)
			_root = insert_util(_root, val, nullptr);
		else
		{
			if (!already_exist(_root, val))
				return false;
			_root = insert_util(_root, val, _root->parent);
		}
		return true;
	}

private:
		tree_pointer getNewNode(value_type data, tree_pointer parent){
			tree_pointer newNode = _alloc_tree.allocate(1);
			_alloc_tree.construct(newNode, tree(data, parent, nullptr, nullptr));

			return newNode;
		}

		tree_pointer insert_util(tree_pointer bst, value_type data, tree_pointer parent){
			if (bst == nullptr)
				bst = getNewNode(data, parent);
			else if (data.first < bst->value.first)
				bst->left = insert_util(bst->left, data, bst);
			else if (data.first > bst->value.first)
				bst->right = insert_util(bst->right, data, bst);
			return bst;
		}

		bool already_exist(tree_pointer tree, const value_type& val){ // Replace by ft::pair
			while (tree != nullptr)
			{
				if (val.first < tree->value.first)
					tree = tree->left;
				else if (val.first > tree->value.first)
					tree = tree->right;
				else
				{
					std::cout << "Already exist" << std::endl;
					return false;
				}
			}
			return true;
		}
};

}

#endif