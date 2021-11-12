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
	tree_pointer	_last_node;
	size_type		_size;

public:
	Bst(const allocator_type& alloc = allocator_type()) : _alloc_tree(alloc), _size(0){
		_root = _alloc_tree.allocate(1);
		_alloc_tree.construct(_root, tree(nullptr, nullptr, nullptr));
		_last_node = _root;
	}

	~Bst(){		
		del_tree(_root);
		_alloc_tree.destroy(_root);
	}

	size_type size() const{return _size;}

	bool empty() const{return _size == 0;}

	size_type max_size() const{return (std::numeric_limits<difference_type>::max());}

	iterator begin(){
		return (iterator(begin_tree(_root)));
	}

	iterator end(){
		return (iterator(end_tree()));
	}

		//MODIFIER
	//Insert
	ft::pair<iterator, bool> insert(const value_type& val){
		iterator it;
		tree_pointer tmp = _root;

		if (tmp == nullptr)
			insert_util(&tmp, val, nullptr, &it);
		else
		{
			if (!already_exist(_root, val, &it))
				return ft::pair<iterator, bool>(it, false);
			tmp = insert_util(&tmp, val, tmp->parent, &it);
		}
		_size++;
		return ft::pair<iterator, bool>(it, true);
	}

	iterator insert(iterator hint, const value_type& val){
		ft::pair<iterator, bool> ret;
		(void)hint;

		ret = insert(val);
		return ret.first;
	}

	template <class InputIterator>
	void insert(InputIterator first, InputIterator last){
		for (; first != last; ++first)
			insert(*first);
	}

	size_type erase(const value_type& val){
		// tree_pointer tmp = _root;

		_root = erase_util(_root, val);
		return 1;
	}

		//OPERATIONS
	//Find
	ft::pair<iterator, bool> find(value_type to_find) const{
		tree_pointer tmp = _root;

		while (tmp)
		{
			if (to_find.first > tmp->value.first)
				tmp = tmp->right;
			else if (to_find.first < tmp->value.first)
				tmp = tmp->left;
			else
				return ft::pair<iterator, bool>(iterator(tmp), true);
		}
		return (ft::pair<iterator, bool>(iterator(end_tree()), false));
	}


private:

	tree_pointer erase_util(tree_pointer tree, value_type val){
		if (tree == nullptr)
			return tree;
		if (val.first > tree->value.first)
			tree->right = erase_util(tree->right, val);
		else if (val.first < tree->value.first)
			tree->left = erase_util(tree->left, val);
		else if (val.first == tree->value.first)
		{
			if (tree->left == nullptr)
			{
				tree_pointer tmp = tree->right;
				tmp->parent = tree->parent;
				_alloc_tree.deallocate(tree, 1);
				tree = tmp;
				// return tmp;
			}
			else if (tree->right == nullptr)
			{
				tree_pointer tmp = tree->left;
				tmp->parent = tree->parent;
				_alloc_tree.deallocate(tree, 1);
				tree = tmp;
				// return tmp;
			}
			// else
			// {
			// 	tree_pointer tmp = min(tree->right);
			// 	tree_pointer parent = tmp->parent;
			// 	tree->value = tmp->value;
			// 	_alloc_tree.deallocate(tmp, 1);
			// 	if (parent.)
			// }
		}
		return tree;
	}

	tree_pointer min(tree_pointer node)
	{
		while (node->left)
			node = node->left;
		return node;
	}

	void getNewNode(value_type data, tree_pointer parent, tree_pointer *bst){
		if (*bst == _last_node)
		{
			_alloc_tree.construct(*bst, tree(data, parent, nullptr, nullptr));
			(*bst)->right = _alloc_tree.allocate(1);
			_alloc_tree.construct((*bst)->right, tree(*bst, nullptr, nullptr));
			_last_node = (*bst)->right;
		}
		else if (data.first < (*bst)->value.first)
		{
			(*bst)->left = _alloc_tree.allocate(1);
			_alloc_tree.construct((*bst)->left, tree(data, *bst, nullptr, nullptr));
			*bst = (*bst)->left;
		}
		else
		{
			(*bst)->right = _alloc_tree.allocate(1);
			_alloc_tree.construct((*bst)->right, tree(data, *bst, nullptr, nullptr));
			*bst = (*bst)->right;
		}
	}

	tree_pointer insert_util(tree_pointer *bst, value_type data, tree_pointer parent, iterator *it){
		if (_size == 0 || ((*bst)->left == nullptr && data.first < (*bst)->value.first) ||
			((*bst)->right == nullptr && data.first > (*bst)->value.first))
		{
			getNewNode(data, parent, bst);
			*it = iterator(*bst);
		}
		else if (data.first < (*bst)->value.first)
		{
			*bst = (*bst)->left;
			insert_util(bst, data, (*bst)->parent, it);
		}
		else if (data.first > (*bst)->value.first)
		{
			*bst = (*bst)->right;
			insert_util(bst, data, (*bst)->parent, it);
		}
		return *bst;
	}

	bool already_exist(tree_pointer tree, const value_type& val, iterator *it){
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

	tree_pointer end_tree() const{
		return (_last_node);
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