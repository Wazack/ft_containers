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
	typedef value_type&							reference;
	typedef value_type*							pointer;
	typedef tree<T>								tree;
	typedef Alloc								allocator_type;
	typedef tree&								tree_reference;
	typedef tree*								tree_pointer;
	typedef BstIterator<value_type>				iterator;
	typedef std::bidirectional_iterator_tag		iterator_category;
	typedef ptrdiff_t							difference_type;

	typedef size_t								size_type;

private:
	allocator_type	_alloc_tree;
	tree_pointer	_root;
	size_type		_size;

public:
	Bst(const allocator_type& alloc = allocator_type()) : _alloc_tree(alloc), _size(0){
		// _root = _alloc_tree.allocate(1);
		// _alloc_tree.construct(_root, tree(_root, _root, _root));
		_root = nullptr;
	}

	~Bst(){
		if (_size)
		{			
			del_tree(_root);
			_alloc_tree.destroy(_root);
		}
	}

	iterator begin(){
		return (iterator(begin_tree(_root)));
	}

	iterator end(){
		return (iterator(end_tree(_root)));
	}

	ft::pair<iterator, bool> insert(const value_type& val){
		iterator it;

		if (_root == nullptr)
			_root = insert_util(_root, val, nullptr, &it);
		else
		{
			if (!already_exist(_root, val, &it))
				return ft::pair<iterator, bool>(it, false);
			_root = insert_util(_root, val, _root->parent, &it);
		}
		_size++;
		return ft::pair<iterator, bool>(it, true);
	}

	size_type size() const{return _size;}

private:
		tree_pointer getNewNode(value_type data, tree_pointer parent){
			tree_pointer newNode = _alloc_tree.allocate(1);
			_alloc_tree.construct(newNode, tree(data, parent, nullptr, nullptr));

			return newNode;
		}

		tree_pointer insert_util(tree_pointer bst, value_type data, tree_pointer parent, iterator *it){
			if (bst == nullptr)
			{
				bst = getNewNode(data, parent);
				*it = iterator(bst);
			}
			else if (data.first < bst->value.first)
				bst->left = insert_util(bst->left, data, bst, it);
			else if (data.first > bst->value.first)
				bst->right = insert_util(bst->right, data, bst, it);
			return bst;
		}

		bool already_exist(tree_pointer tree, const value_type& val, iterator *it){ // Replace by ft::pair
			while (tree != nullptr)
			{
				if (val.first < tree->value.first)
					tree = tree->left;
				else if (val.first > tree->value.first)
					tree = tree->right;
				else
				{
					*it = iterator(tree);
					return false;
				}
			}
			return true;
		}

		tree_pointer begin_tree(tree_pointer bst){
			while (bst->left)
				bst = bst->left;
			return bst;
		}

		tree_pointer end_tree(tree_pointer bst){
			while (bst->right)
				bst = bst->right;
			// bst->right = _alloc_tree.allocate(1);
			// bst = bst->right;
			return (bst);
		}

		void del_tree(tree_pointer bst){
			if (bst)
			{
				del_tree(bst->left);
				_alloc_tree.deallocate(bst, 1);
				del_tree(bst->right);
			}
		}
};

}

#endif