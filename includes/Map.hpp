#include <iostream>
#include <Utility.hpp>
#include <map>

template <class Key, class T, class Compare = std::less<Key>, class Alloc = std::allocator<ft::pair<const Key, T> > >
class Map
{
private:
	typedef Key key_type;
	typedef T mapped_type;
	typedef ft::pair<const Key, T> value_type;
	typedef Compare key_compare;
	typedef Alloc allocator_type;
	typedef typename allocator_type::reference reference;
	typedef typename allocator_type::const_reference const_reference;
	typedef typename allocator_type::pointer pointer;
	typedef typename allocator_type::const_pointer const_pointer;
	typedef ptrdiff_t difference_type
	typedef size_t size_type;

private:
	allocator_type _alloc;
	size_type	_size;

public:
	Map();
	~Map();

	//Capacity
	size_type size() const {return _size;}

	bool empty() const {return _size == 0;}

	size_type max_size() const {return _alloc.max_size();}

	allocator_type get_allocator() const{return _alloc;}
};
