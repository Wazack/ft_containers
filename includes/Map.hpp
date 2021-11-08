#include <iostream>
#include "Utility.hpp"
#include "vector.hpp"
#include "Bst.hpp"

namespace ft
{
	template <class Key, class T, class Compare = std::less<Key>, class Alloc = std::allocator<ft::pair<Key, T> > >
	class map
	{
	public:
		typedef Key											key_type;
		typedef T 											mapped_type;
		typedef ft::pair<Key, T>							value_type; //const Key ?
		typedef Compare										key_compare;
		typedef Alloc										allocator_type;
		typedef typename allocator_type::reference			reference;
		typedef typename allocator_type::const_reference	const_reference;
		typedef typename allocator_type::pointer			pointer;
		typedef typename allocator_type::const_pointer		const_pointer;
		typedef Bst<value_type>								base;
		typedef typename base::iterator						iterator;
		typedef ptrdiff_t									difference_type;
		typedef size_t										size_type;

		class value_compare : public std::binary_function<value_type, value_type, bool>
		{
			friend class map;
		protected:
			key_compare comp;
			value_compare(key_compare c) : comp(c){}

		public:
			bool operator()(const value_type& x, const value_type& y) const {return comp(x.first, y.first);}
		};

	private:
		base	_tree;

	private:
		allocator_type _alloc;
		key_compare _comp;

	public:
		explicit map(const key_compare& comp = key_compare(), const allocator_type& alloc = allocator_type()) : _tree(), _alloc(alloc), _comp(comp){}
		~map(){}

		//Capacity
	size_type size() const {return _tree.size();}

	ft::pair<iterator, bool> insert(const value_type& val){return _tree.insert(val);}

	iterator end(){return _tree.end();}

	iterator begin(){return _tree.begin();}

	// 	bool empty() const {return _bst == NULL;}

	// 	size_type max_size() const {return _alloc.max_size();}

	// 	allocator_type get_allocator() const{return _alloc;}

	// 	ft::pair<iterator, bool> insert(const value_type& val){
	// 		_bst = insert_util(_bst, val, NULL);
	// 		return (ft::pair<iterator, bool>(begin(), true));
	// 	}

	// public: //Change to private

	// 	void test(){print_test(_bst);}

	// 	void print_test(tree *bst){
	// 		if (bst)
	// 		{
	// 			print_test(bst->left);
	// 			std::cout << "[" << bst->data.first << "]" << " [" << bst->data.second << ']' << std::endl;
	// 			print_test(bst->right);
	// 		}
	// 	}
	// private: //<--A retirer
	// 	//Accessor
	// 	tree* begin_tree(tree* bst){
	// 		while (bst->left)
	// 			bst = bst->left;
	// 		return (bst);
	// 	}

	// 	tree* end_tree(tree* bst){
	// 		while (bst->right)
	// 		{
	// 			bst = bst->right;
	// 		}
	// 		bst = bst->right;
	// 		return (bst);
	// 	}

	// 	//Tree utility
	// 	tree* getNewNode(value_type data, tree* parent){
	// 		tree* newNode = new tree();
	// 		newNode->left = newNode->right = NULL;
	// 		newNode->data = data;
	// 		newNode->parent = parent;

	// 		return newNode;
	// 	}

	// 	tree* insert_util(tree* bst, value_type data, tree *parent){
	// 		if (bst == NULL)
	// 			bst = getNewNode(data, parent);
	// 		else if (data.first <= bst->data.first)
	// 			bst->left = insert_util(bst->left, data, bst);
	// 		else
	// 			bst->right = insert_util(bst->right, data, bst);
	// 		return bst;
	// 	}
	};

}