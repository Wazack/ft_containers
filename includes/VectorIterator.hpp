#ifndef VECTORITERATOR_HPP
#define VECTORITERATOR_HPP

#include <type_traits>

#include <iostream>
#include "Iterator.hpp"

namespace ft
{
template <class Iter>
class VectorIterator
{
public:
	typedef	Iter														iterator_type;
	typedef	typename iterator_traits<iterator_type>::iterator_category	iterator_category;
	typedef	typename iterator_traits<iterator_type>::value_type 		value_type;
	typedef	typename iterator_traits<iterator_type>::difference_type 	difference_type;
	typedef	typename iterator_traits<iterator_type>::pointer 			pointer;
	typedef	typename iterator_traits<iterator_type>::reference 			reference;

private:
	iterator_type _i;

public:
	VectorIterator() : _i(){}
	VectorIterator(iterator_type u) : _i(u){}
	template <class U>
	VectorIterator(VectorIterator<U> const & src) : _i(src.base()){}
	~VectorIterator(){}

	template <class U>
	VectorIterator & operator=(const VectorIterator<U> & rhs){
		this->_i = rhs.base();
		return *this;
	}

	iterator_type base() const {return _i;}

	reference operator*(void){
		return (*_i);
	}

	reference operator[](int index){
		return *(_i + index);
	}

	pointer operator->(void){
		return (_i);
	}

	VectorIterator & operator++(void){
		_i++;
		return *this;
	}

	VectorIterator operator++(int){
		VectorIterator tmp(*this);
		++(*this);
		return (tmp);
	}

	VectorIterator operator-(difference_type n) const{
		return *this + (-n);
	}

	VectorIterator operator+(difference_type n) const{
		VectorIterator __w(*this);
		__w += n;
		return __w;
	}

	VectorIterator & operator+=(difference_type n){
		_i += n;
		return *this;
	}

	VectorIterator & operator-=(difference_type n){
		*this += -n;
		return *this;
	}

	VectorIterator & operator--(void){
		_i--;
		return *this;
	}

	VectorIterator operator--(int){
		VectorIterator tmp(*this);
		--(*this);
		return (tmp);
	}
};

template <class Iter1, class Iter2>
bool operator==(const VectorIterator<Iter1>& x, const VectorIterator<Iter2>& y)
{
	return x.base() == y.base();
}

template <class Iter1, class Iter2>
bool operator<(const VectorIterator<Iter1>& x, const VectorIterator<Iter2>& y)
{
	return x.base() < y.base();
}

template <class Iter1, class Iter2>
bool operator!=(const VectorIterator<Iter1>& x, const VectorIterator<Iter2>& y)
{
	return !(x == y);
}

template <class Iter1, class Iter2>
bool operator>(const VectorIterator<Iter1>& x, const VectorIterator<Iter2>& y)
{
	return y < x;
}

template <class Iter1, class Iter2>
bool operator>=(const VectorIterator<Iter1>& x, const VectorIterator<Iter2>& y)
{
	return !(x < y);
}

template <class Iter1, class Iter2>
bool operator<=(const VectorIterator<Iter1>& x, const VectorIterator<Iter2>& y)
{
	return !(y < x);
}

template <class Iter1>
bool operator!=(const VectorIterator<Iter1>& x, const VectorIterator<Iter1>& y)
{
	return !(x == y);
}

template <class Iter1>
bool operator>(const VectorIterator<Iter1>& x, const VectorIterator<Iter1>& y)
{
	return y < x;
}

template <class Iter1>
bool operator>=(const VectorIterator<Iter1>& x, const VectorIterator<Iter1>& y)
{
	return !(x < y);
}

template <class Iter1>
bool operator<=(const VectorIterator<Iter1>& x, const VectorIterator<Iter1>& y)
{
	return !(y < x);
}

template <class Iter1, class Iter2>
typename VectorIterator<Iter1>::difference_type
operator-(const VectorIterator<Iter1>& x, const VectorIterator<Iter2>& y)
{
	return x.base() - y.base();
}

template <class Iter>
VectorIterator<Iter>
operator+(typename VectorIterator<Iter>::difference_type n, VectorIterator<Iter> x)
{
	x += n;
	return x;
}


}

#endif