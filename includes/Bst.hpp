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

template <class T, class Compare, class Alloc = std::allocator<tree<T> > >
class Bst
{
public:
	typedef T										value_type;
	typedef Compare									key_compare;
	typedef value_type&								reference;
	typedef value_type*								pointer;
	typedef	const value_type						const_value_type;
	typedef tree<T>									tree;
	typedef Alloc									allocator_type;
	typedef tree&									tree_reference;
	typedef tree*									tree_pointer;
	typedef BstIterator<value_type>					iterator;
	typedef BstConstIterator<value_type>			const_iterator;
	typedef ft::reverse_iterator<iterator>			reverse_iterator;
	typedef ft::reverse_iterator<const_iterator>	const_reverse_iterator;
	typedef std::bidirectional_iterator_tag			iterator_category;
	typedef ptrdiff_t								difference_type;
	typedef size_t									size_type;

private:
	allocator_type	_alloc_tree;
	tree_pointer	_root;
	tree_pointer	_last_node;
	tree_pointer	_begin_node;
	size_type		_size;

public:
	Bst(const allocator_type& alloc = allocator_type()) : _alloc_tree(alloc), _size(0){
		_root = _alloc_tree.allocate(1);
		_alloc_tree.construct(_root, tree(nullptr, nullptr, nullptr));
		_last_node = _root;
		_last_node = _root;
	}

	template <class InputIterator>
	Bst(InputIterator first, InputIterator last, const allocator_type& alloc = allocator_type()) : _alloc_tree(alloc), _size(0){
		_root = _alloc_tree.allocate(1);
		_alloc_tree.construct(_root, tree(nullptr, nullptr, nullptr));
		_last_node = _root;
		insert(first, last);
	}

	Bst(const Bst& x) : _alloc_tree(x._alloc_tree), _size(x._size){
		_root = _alloc_tree.allocate(1);
		_alloc_tree.construct(_root, tree(nullptr, nullptr, nullptr));
		_last_node = _root;
		insert(x.begin(), x.end());
	}

	Bst& operator=(const Bst& rhs){
		_alloc_tree = rhs._alloc_tree;
		_size = rhs._size;
		insert(rhs.begin(), rhs.end());
	}

	~Bst(){
		del_tree(_root);
		// _alloc_tree.destroy(_root);
	}

	size_type size() const{return _size;}

	bool empty() const{return _size == 0;}

	size_type max_size() const{return (std::numeric_limits<difference_type>::max());}

	iterator begin(){
		return (iterator(begin_tree(_root)));
	}

	const_iterator begin() const{
		return const_iterator(begin_tree(_root));
	}

	reverse_iterator rbegin(){
		return reverse_iterator(end());
	}

	const_reverse_iterator rbegin()const{
		return const_reverse_iterator(end());
	}

	iterator end(){
		return (iterator(end_tree()));
	}

	const_iterator end() const{
		return const_iterator(end_tree());
	}

	reverse_iterator rend(){
		return reverse_iterator(begin());
	}

	const_reverse_iterator rend()const{
		return const_reverse_iterator(begin());
	}

		//MODIFIER
	//Insert
	ft::pair<iterator, bool> insert(const value_type& val){
		iterator it;
		tree_pointer tmp = _root;
		bool ret = true;
		
		tmp = insert_util(&tmp, val, &it, &ret);
		_size++;
		return ft::pair<iterator, bool>(it, ret);
	}

	value_type assign_parent(iterator hint){
		value_type parent = *hint;

		return parent;
	}

	iterator insert(iterator hint, const value_type& val){
		ft::pair<iterator, bool> ret;
		ft::pair<tree_pointer, bool> find;
		value_type pos = *hint;
		value_type parent;
		iterator it;
		tree_pointer tmp = _root;
		bool boolean = true;
		
		if (hint != iterator(min(_root)))
			--hint;
		if (val.first > pos.first && val.first > _root->value.first)
			ret = insert(val);
		else if (hint != iterator(min(_root)) && assign_parent(hint).first > pos.first)
			ret = insert(val);
		else
		{
			find = find_tree(pos);
			if (find.second == false)
				ret = insert(val);
			else
				tmp = insert_util(&(find.first), val, &it, &boolean);
		}
		return ret.first;
	}

	template <class InputIterator>
	void insert(InputIterator first, InputIterator last){
		for (; first != last; ++first)
			insert(end(), *first);
	}

	void swap(Bst& x){
		allocator_type alloc = x._alloc_tree;
		size_type size = x._size;
		tree_pointer root = x._root;
		tree_pointer last_node = x._last_node;

		x._alloc_tree = this->_alloc_tree;
		x._size = this->_size;
		x._root = this->_root;
		x._last_node = this->_last_node;

		this->_alloc_tree = alloc;
		this->_size = size;
		this->_root = root;
		this->_last_node = last_node;
	}

	size_type erase(const value_type& val){
		size_type ret = 0;

		_root = erase_util(_root, val, &ret);
		return ret;
	}

		//OPERATIONS
	//Find
	ft::pair<iterator, bool> find(value_type to_find){
		tree_pointer tmp = _root;

		if (_size != 0)
		{
			while (tmp)
			{
				if (to_find.first > tmp->value.first)
					tmp = tmp->right;
				else if (to_find.first < tmp->value.first)
					tmp = tmp->left;
				else
					return ft::pair<iterator, bool>(iterator(tmp), true);
			}
		}
		return (ft::pair<iterator, bool>(iterator(end_tree()), false));
	}
	
	ft::pair<const_iterator, bool> find(value_type to_find) const{
		tree_pointer tmp = _root;

		while (tmp)
		{
			if (to_find.first > tmp->value.first)
				tmp = tmp->right;
			else if (to_find.first < tmp->value.first)
				tmp = tmp->left;
			else
				return ft::pair<const_iterator, bool>(const_iterator(tmp), true);
		}
		return (ft::pair<const_iterator, bool>(const_iterator(end_tree()), false));
	}

	iterator lower_bound(value_type val){
		tree_pointer tmp = _root;
		tree_pointer ret;

		while (tmp)
		{
			if (!key_compare()(tmp->value.first, val.first))
			{
				ret = tmp;
				tmp = tmp->left;
			}
			else
				tmp = tmp->right;
		}
		return iterator(ret);
	}
	
	const_iterator lower_bound(value_type val)const{
		tree_pointer tmp = _root;
		tree_pointer ret;

		while (tmp)
		{
			if (!key_compare()(tmp->value.first, val.first) || tmp->value == value_type())
			{
				ret = tmp;
				tmp = tmp->left;
			}
			else
				tmp = tmp->right;
		}
		return const_iterator(ret);
	}

	iterator upper_bound(value_type val){
		tree_pointer tmp = _root;
		tree_pointer ret;

		while (tmp)
		{
			if (key_compare()(val.first, tmp->value.first))
			{
				ret = tmp;
				tmp = tmp->left;
			}
			else
				tmp = tmp->right;
		}
		return iterator(ret);		
	}
	
	const_iterator upper_bound(value_type val)const{
		tree_pointer tmp = _root;
		tree_pointer ret;

		while (tmp)
		{
			if (key_compare()(val.first, tmp->value.first))
			{
				ret = tmp;
				tmp = tmp->left;
			}
			else
				tmp = tmp->right;
		}
		return const_iterator(ret);		
	}

	pair<iterator, iterator> equal_range(value_type val){
		tree_pointer ret = end_tree();
		tree_pointer tmp = _root;

		while (tmp)
		{
			if (key_compare()(val.first, tmp->value.first))
			{
				ret = tmp;
				tmp = tmp->left;
			}
			else if (key_compare()(tmp->value.first, val.first))
				tmp = tmp->right;
			else
				return pair<iterator, iterator>(iterator(tmp), iterator(tmp->right ? tmp->right : ret));
		}
		return (pair<iterator, iterator>(iterator(ret), iterator(ret)));
	}
	
	pair<const_iterator, const_iterator> equal_range(value_type val)const{
		tree_pointer ret = end_tree();
		tree_pointer tmp = _root;

		while (tmp)
		{
			if (key_compare()(val.first, tmp->value.first))
			{
				ret = tmp;
				tmp = tmp->left;
			}
			else if (key_compare()(tmp->value.first, val.first))
				tmp = tmp->right;
			else
				return pair<const_iterator, const_iterator>(const_iterator(tmp), const_iterator(tmp->right ? tmp->right : ret));
		}
		return (pair<const_iterator, const_iterator>(const_iterator(ret), const_iterator(ret)));
	}

	void clear(){
		del_tree(_root);
		_size = 0;
		_root = _alloc_tree.allocate(1);
		_alloc_tree.construct(_root, tree(nullptr, nullptr, nullptr));
		_last_node = _root;
	}

	allocator_type get_allocator() const{
		return (_alloc_tree);
	}


private:

	ft::pair<tree_pointer, bool> find_tree(value_type to_find){
		tree_pointer tmp = _root;

		if (_size != 0)
		{
			while (tmp)
			{
				if (to_find.first > tmp->value.first)
					tmp = tmp->right;
				else if (to_find.first < tmp->value.first)
					tmp = tmp->left;
				else
					return pair<tree_pointer, bool>(tmp, false);
			}
		}
		return (pair<tree_pointer, bool>(end_tree(), false));
	}

	tree_pointer erase_util(tree_pointer tree, value_type val, size_type *ret){
		if (tree == nullptr)
			return tree;
		if (val.first > tree->value.first)
			tree->right = erase_util(tree->right, val, ret);
		else if (val.first < tree->value.first)
			tree->left = erase_util(tree->left, val, ret);
		else if (val.first == tree->value.first)
		{
			if (tree->left == nullptr && tree->right == nullptr)
			{
				_alloc_tree.deallocate(tree, 1);
				tree = nullptr;
			}
			else if (tree->right == nullptr)
			{
				tree_pointer tmp = tree->left;
				tmp->parent = tree->parent;
				_alloc_tree.deallocate(tree, 1);
				tree = tmp;
			}
			else if (tree->left == nullptr)
			{
				tree_pointer tmp = tree->right;
				tmp->parent = tree->parent;
				_alloc_tree.deallocate(tree, 1);
				tree = tmp;
			}
			else
			{
				tree_pointer tmp;
				tmp = erase_double_child(tree->right);
				tmp->parent = tree->parent;
				if (tree->right != tmp)
					tmp->right = tree->right;
				tmp->left = tree->left;
				tmp->left->parent = tmp;
				_alloc_tree.deallocate(tree, 1);
				tree = tmp;
			}
			(*ret)++;
		}
		return tree;
	}

	tree_pointer erase_double_child(tree_pointer tree){
		tree_pointer ret = tree;
		tree_pointer ret_parent;
		bool brw = false;

		while (ret->left)
		{
			ret = ret->left;
			brw = true;
		}
		if (ret->right && ret->right->value.first != value_type().first)
		{
			if (ret->right->value.first < tree->value.first)
			{
				tree = ret->right;
				ret_parent = ret->parent;
				ret->parent->left = tree;
				tree->parent = ret_parent;
			}
		}
		else if (brw)
		{
			ret_parent = ret->parent;
			ret->parent->left = nullptr;
		}
		return ret;
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
		else if (data.first < parent->value.first)
		{
			(*bst) = _alloc_tree.allocate(1);
			_alloc_tree.construct(*bst, tree(data, parent, nullptr, nullptr));
			parent->left = *bst;
		}
		else
		{
			(*bst) = _alloc_tree.allocate(1);
			_alloc_tree.construct((*bst), tree(data, parent, nullptr, nullptr));
			parent->right = *bst;
		}
	}

	// tree_pointer insert_util(tree_pointer *bst, value_type data, tree_pointer parent, iterator *it){
	// 	if (_size == 0 || ((*bst)->left == nullptr && data.first < (*bst)->value.first) ||
	// 		((*bst)->right == nullptr && data.first > (*bst)->value.first))
	// 	{
	// 		getNewNode(data, parent, bst);
	// 		*it = iterator(*bst);
	// 	}
	// 	else if (data.first < (*bst)->value.first)
	// 	{
	// 		*bst = (*bst)->left;
	// 		insert_util(bst, data, (*bst)->parent, it);
	// 	}
	// 	else if (data.first > (*bst)->value.first)
	// 	{
	// 		*bst = (*bst)->right;
	// 		insert_util(bst, data, (*bst)->parent, it);
	// 	}
	// 	return *bst;
	// }

	tree_pointer insert_util(tree_pointer *bst, value_type val, iterator *it, bool *ret)
	{
		tree_pointer parent = nullptr;

		while ((*bst) != nullptr && *bst != _last_node)
		{
			parent = (*bst);
			if ((*bst)->value.first > val.first)
				(*bst) = (*bst)->left;
			else if ((*bst)->value.first < val.first)
				(*bst) = (*bst)->right;
			else
			{
				*ret = false;
				*it = iterator(*bst);
				return *bst;
			}
		}
		getNewNode(val, parent, bst);
		*it = iterator(*bst);
		return *bst;
	}

	bool already_exist(tree_pointer tree, const value_type& val, iterator *it){
		while (tree)
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

	tree_pointer begin_tree(tree_pointer bst) const{
		while (bst->left)
			bst = bst->left;
		return bst;
	}

	tree_pointer end_tree() const{
		return (_last_node);
	}

	// void del_tree(tree_pointer bst){
	// 	if (bst)
	// 	{
	// 		del_tree(bst->left);
	// 		_alloc_tree.deallocate(bst, 1);
	// 		_alloc_tree.destroy(bst);
	// 		del_tree(bst->right);
	// 	}
	// }

	void del_tree(tree_pointer bst){
		if (!bst)
			return ;
		del_tree(bst->left);
		del_tree(bst->right);
		_alloc_tree.deallocate(bst, 1);
		_alloc_tree.destroy(bst);
	}
};

}

#endif