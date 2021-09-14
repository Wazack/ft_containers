#include <iostream>

template <typename Vector>
class vectorIterator
{
public:
	typedef typename Vector::value_type value_type;
	typedef value_type* pointer_type;
	typedef value_type& reference_type;

	vectorIterator(pointer_type ptr) : _ptr(ptr){}

private:
	pointer_type _ptr;
};

namespace ft
{
	template < class T, class Alloc = std::allocator<T> >
    class vector
    {
    public:
		typedef T value_type;
		typedef Alloc allocator_type;
		typedef typename allocator_type::reference reference;
		typedef typename allocator_type::const_reference const_reference;
		typedef typename allocator_type::pointer pointer;
		typedef typename allocator_type::const_pointer const_pointer;

		typedef vectorIterator<vector<T>> iterator;
    };
}