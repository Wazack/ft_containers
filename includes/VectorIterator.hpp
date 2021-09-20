#include <iostream>

template <class Vector>
class VectorIterator
{
public:
	typedef typename Vector::value_type value_type;
	typedef value_type& reference;
	typedef value_type* pointer;

private:
	pointer _ptr;

public:
	VectorIterator(pointer ptr) : _ptr(ptr){}
};
