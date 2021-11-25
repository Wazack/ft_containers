#include <iostream>
#include "Utility.hpp"
#include "vector.hpp"
#include "Bst.hpp"

namespace ft
{
template <class Key, class T, class Compare = std::less<Key>, class Alloc = std::allocator<ft::pair<const Key, T> > >
class map
{
public:
	typedef Key											key_type;
	typedef T 											mapped_type;
	typedef ft::pair<const key_type, mapped_type>		value_type;
	typedef Compare										key_compare;
	typedef Alloc										allocator_type;
	typedef typename allocator_type::reference			reference;
	typedef typename allocator_type::const_reference	const_reference;
	typedef typename allocator_type::pointer			pointer;
	typedef typename allocator_type::const_pointer		const_pointer;
	typedef Bst<value_type, key_compare>				base;
	typedef typename base::iterator						iterator;
	typedef typename base::const_iterator				const_iterator;
	typedef typename base::reverse_iterator				reverse_iterator;
	typedef typename base::const_reverse_iterator		const_reverse_iterator;
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
	allocator_type _alloc;
	key_compare _comp;

public:
	explicit map(const key_compare& comp = key_compare(), const allocator_type& alloc = allocator_type())
	: _tree(), _alloc(alloc), _comp(comp){}

	template <class InputIterator>
	map(InputIterator first, InputIterator last, const key_compare& comp = key_compare(),
	const allocator_type& alloc = allocator_type()) : _tree(first, last), _alloc(alloc), _comp(comp){}

	map(const map& x) : _alloc(x._alloc), _comp(x._comp){
		insert(x.begin(), x.end());
	}

	map& operator=(const map& rhs){
		if (this != &rhs)
		{
			clear();
			_alloc = rhs._alloc;
			_comp = rhs._comp;
			insert(rhs.begin(), rhs.end());
		}

		return *this;
	}

	~map(){}

	//Capacity
	size_type size() const {return _tree.size();}

	size_type max_size() const{return _tree.max_size();}

	bool empty() const{return _tree.empty();}

	iterator end(){return _tree.end();}

	const_iterator end()const{return _tree.end();}

	reverse_iterator rend(){return reverse_iterator(begin());}
	
	const_reverse_iterator rend()const{return _tree.rend();}

	iterator begin() {return _tree.begin();}

	const_iterator begin() const {return _tree.begin();}

	reverse_iterator rbegin(){return _tree.rbegin();}
	
	const_reverse_iterator rbegin()const{return _tree.rbegin();}

	//Modifier
	ft::pair<iterator, bool> insert(const value_type& val){return _tree.insert(val);}

	iterator insert(iterator hint, const value_type& val){return _tree.insert(hint, val);}

	template <class InputIterator>
	void insert(InputIterator first, InputIterator last){
		size_type i = 0;

		for (; first != last; ++first)
		{
			_tree.insert(*first);
			std::cout << i++ << std::endl;
		}
	}

	void erase(iterator position){
		_tree.erase(*position);
	}

	size_type erase(const key_type& k){
		value_type to_erase(k, mapped_type());

		return _tree.erase(to_erase);
	}

	void erase(iterator first, iterator last){
		for (; first != last; ++first)
			_tree.erase(*first);
	}

	void swap(map& x){
		_tree.swap(x._tree);
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

	mapped_type& at (const key_type& k){
		ft::pair<iterator, bool> ret;
		iterator it;
		value_type to_find(k, mapped_type());

		ret = _tree.find(to_find);
		if (ret.second == false)
			throw(std::out_of_range("map::at:  key not found"));
		it = ret.first;
		return it->second;
	}

	//Operation
	iterator find(const key_type& k){
		value_type to_find(k, mapped_type());
		return _tree.find(to_find).first;
	}

	const_iterator find(const key_type& k)const{
		value_type to_find(k, mapped_type());
		return _tree.find(to_find).first;
	}

	size_type count(const key_type& k) const{
		value_type to_find(k, mapped_type());

		if (_tree.find(to_find).second == false)
			return 0;
		return 1;
	}

	iterator lower_bound(const key_type& k){
		value_type val(k, mapped_type());

		return _tree.lower_bound(val);
	}

	const_iterator lower_bound(const key_type& k)const{
		value_type val(k, mapped_type());

		return _tree.lower_bound(val);
	}

	iterator upper_bound(const key_type& k){
		value_type val(k, mapped_type());

		return _tree.upper_bound(val);
	}

	const_iterator upper_bound(const key_type& k)const{
		value_type val(k, mapped_type());

		return _tree.upper_bound(val);
	}

	pair<iterator, iterator> equal_range(const key_type& k){
		value_type val(k, mapped_type());

		return _tree.equal_range(val);
	}
	
	pair<const_iterator, const_iterator> equal_range(const key_type& k)const{
		value_type val(k, mapped_type());

		return _tree.equal_range(val);
	}

	key_compare key_comp()const{return key_compare();}

	value_compare value_comp()const{return value_compare(key_compare());}

	void clear(){_tree.clear();}

	allocator_type get_allocator()const{
		return _tree.get_allocator();
	}

};

template <class Key, class T, class Compare, class Allocator>
bool operator==(const map<Key, T, Compare, Allocator>& x, const map<Key, T, Compare, Allocator>& y)
{
	return x.size() == y.size() && ft::equal(x.begin(), x.end(), y.begin());
}

template <class Key, class T, class Compare, class Allocator>
bool operator!=(const map<Key, T, Compare, Allocator>& x, const map<Key, T, Compare, Allocator>& y)
{
	return !(x == y);
}

template <class Key, class T, class Compare, class Allocator>
bool operator<(const map<Key, T, Compare, Allocator>& x, const map<Key, T, Compare, Allocator>& y)
{
	return ft::lexicographical_compare(x.begin(), x.end(), y.begin(), y.end());
}

template <class Key, class T, class Compare, class Allocator>
bool operator>(const map<Key, T, Compare, Allocator>& x, const map<Key, T, Compare, Allocator>& y)
{
	return y < x;
}

template <class Key, class T, class Compare, class Allocator>
bool operator>=(const map<Key, T, Compare, Allocator>& x, const map<Key, T, Compare, Allocator>& y)
{
	return !(x < y);
}

template <class Key, class T, class Compare, class Allocator>
bool operator<=(const map<Key, T, Compare, Allocator>& x, const map<Key, T, Compare, Allocator>& y)
{
	return !(y < x);
}

template <class Key, class T, class Compare, class Allocator>
void swap (map<Key, T, Compare, Allocator>& x, map<Key, T, Compare, Allocator>& y)
{
	x.swap(y);
}

}