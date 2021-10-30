#include <iostream>
#include "Utility.hpp"

namespace ft
{

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

	tree(const value_type& val, tree* parent = nullptr, tree* left = nullptr, tree* right = nullptr) : value(val), parent(parent), left(left), right(right){}
};

template <class T, class Compare = std::less<T>, class Alloc = std::allocator<T> >
class Bst
{
public:
	typedef T						value_type;
	typedef tree<T>					tree;
	typedef tree* 					tree_pointer;
	typedef std::allocator<tree>	tree_alloc;

	typedef size_t		size_type;

private:
	tree_alloc		_alloc_tree;
	tree_pointer	_root;
	size_type		_size;

public:
	Bst(const tree_alloc& alloc = tree_alloc()) : _alloc_tree(alloc){
		_root = _alloc_tree.allocate(1);
		_alloc_tree.construct(_root, tree(_root, _root, _root));
	}

	void insert(const value_type& val){ // retourne ft::pair
		tree_pointer n = _alloc_tree.allocate(1);
		tree_pointer tmp = _root;
		tree_pointer buf = nullptr; //Parent de racine = NULL
		int i = 0; //A retirer

		while (tmp != nullptr)
		{
			buf = tmp;
			if (n->value.first < tmp->value.first)
				tmp = tmp->left;
			else if (n->value.first > tmp->value.first)
				tmp = tmp->right;
			else
			{
				delete n;
				std::cout << "Already exist" << std::endl; // A retirer
				return ;//Return false ft::pair
			}
			i++;
		}
		std::cout << i << std::endl;
		(void)val;
	}

};

}