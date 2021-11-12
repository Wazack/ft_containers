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

		// size_type max_size() const{return _tree.max_size();}

		bool empty() const{return _tree.empty();}

		iterator end(){return _tree.end();}

		iterator begin(){return _tree.begin();}

		//Modifier
		ft::pair<iterator, bool> insert(const value_type& val){return _tree.insert(val);}
	
		iterator insert(iterator hint, const value_type& val){return _tree.insert(hint, val);}

		template <class InputIterator>
		void insert(InputIterator first, InputIterator last){_tree.insert(first, last);}

		size_type erase(const key_type& k){
			value_type to_erase(k, mapped_type());

			_tree.erase(to_erase);
			return 1;
		}

		mapped_type& operator[] (const key_type& k){
			ft::pair<iterator, bool> ret;
			iterator it;
			value_type to_find(k, mapped_type());

			ret = _tree.find(to_find);
			if (ret.second == false)
				return (insert(ft::make_pair(k, mapped_type())).first->second);
			it = ret.first;
			return (it->second);
		}

		//Operation
		iterator find(const key_type& k){
			value_type to_find(k, mapped_type());
			return _tree.find(to_find).first;
		}

		size_type count(const key_type& k) const{
			value_type to_find(k, mapped_type());
			ft::pair<iterator, bool> ret;

			ret = _tree.find(to_find);
			if (ret.second == false)
				return 0;
			return 1;
		}

	};

}