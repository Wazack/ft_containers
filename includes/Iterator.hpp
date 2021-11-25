#ifndef ITERATOR_HPP
#define ITERATOR_HPP

#include <iostream>

namespace ft
{
	template <class Category, class T, class Distance = ptrdiff_t, class Pointer = T*, class Reference = T&>
	struct iterator
	{
		typedef	T			value_type;
		typedef	Distance	difference_type;
		typedef	Pointer		pointer;
		typedef	Reference	reference;
		typedef	Category	iterator_category;
	};

	template <class Iter>
	struct iterator_traits
	{
		typedef typename Iter::difference_type difference_type;
		typedef typename Iter::value_type value_type;
		typedef typename Iter::pointer pointer;
		typedef typename Iter::reference reference;
		typedef typename Iter::iterator_category iterator_category;
	};

	template <class T>
	struct iterator_traits<T*>
	{
		typedef	ptrdiff_t								difference_type;
		typedef	T										value_type;
		typedef	T*										pointer;
		typedef	T&										reference;
		typedef	std::random_access_iterator_tag			iterator_category;
	};
	
	template <class T>
	struct iterator_traits<const T*>
	{
		typedef	ptrdiff_t										difference_type;
		typedef	T												value_type;
		typedef	const	T*										pointer;
		typedef	const	T&										reference;
		typedef	std::random_access_iterator_tag					iterator_category;
	};

	template <class Iter>
	class reverse_iterator
	{
	public:
		typedef 			Iter										iterator_type;
		typedef typename	iterator_traits<Iter>::iterator_category	iterator_category;
		typedef typename	iterator_traits<Iter>::value_type			value_type;
		typedef typename 	iterator_traits<Iter>::difference_type		difference_type;
		typedef typename 	iterator_traits<Iter>::pointer				pointer;
		typedef typename 	iterator_traits<Iter>::reference			reference;

	private:
		iterator_type _t;
		iterator_type _current;

	public:
		reverse_iterator() : _t(), _current(){}
		explicit reverse_iterator(iterator_type it) : _t(it), _current(it){}
		template <class U>
		reverse_iterator(const reverse_iterator<U>& rev_it) : _t(rev_it.base()), _current(rev_it.base()) {}

		template <class U>
		reverse_iterator& operator=(const reverse_iterator<U>& rhs){
			_t = _current = rhs.base();
			return (*this);
		}

		iterator_type base() const{return (_current);}

		reference operator*() const{
			Iter tmp = _current;
			return (*--tmp);
		}

		pointer operator->() const{return std::addressof(operator*());};

		reference operator[](difference_type n) const{ return *(*this + n);}

		reverse_iterator& operator++(){
			--_current;
			return *this;
		}

		reverse_iterator operator++(int){
			reverse_iterator tmp(*this);
			--_current;
			return tmp;
		}

		reverse_iterator& operator--(){
			++_current;
			return *this;
		}
		
		reverse_iterator operator--(int){
			reverse_iterator tmp(*this);
			++_current;
			return tmp;
		}

		reverse_iterator operator+(difference_type n) const{return (reverse_iterator(_current - n));}
		
		reverse_iterator operator-(difference_type n) const{return reverse_iterator(_current + n);}

		reverse_iterator& operator+=(difference_type n){
			_current -= n;
			return *this;
		}
		
		reverse_iterator& operator-=(difference_type n){
			_current += n;
			return *this;
		}
	};
	template <class Iter1, class Iter2>
	bool operator==(const reverse_iterator<Iter1>& lhs, const reverse_iterator<Iter2>& rhs){return lhs.base() == rhs.base();}
	
	template <class Iter1, class Iter2>
	bool operator!=(const reverse_iterator<Iter1>& lhs, const reverse_iterator<Iter2>& rhs){return lhs.base() != rhs.base();}
	
	template <class Iter1, class Iter2>
	bool operator<(const reverse_iterator<Iter1>& lhs, const reverse_iterator<Iter2>& rhs){return lhs.base() < rhs.base();}
	
	template <class Iter1, class Iter2>
	bool operator<=(const reverse_iterator<Iter1>& lhs, const reverse_iterator<Iter2>& rhs){return lhs.base() <= rhs.base();}
	
	template <class Iter1, class Iter2>
	bool operator>(const reverse_iterator<Iter1>& lhs, const reverse_iterator<Iter2>& rhs){return lhs.base() > rhs.base();}
	
	template <class Iter1, class Iter2>
	bool operator>=(const reverse_iterator<Iter1>& lhs, const reverse_iterator<Iter2>& rhs){return lhs.base() >= rhs.base();}

	template <class Iter1, class Iter2>
	typename reverse_iterator<Iter1>::difference_type operator-(const reverse_iterator<Iter1>& lhs, const reverse_iterator<Iter2>& rhs){return rhs.base() - lhs.base();}
	
	template <class Iter>
	reverse_iterator<Iter> operator+(typename reverse_iterator<Iter>::difference_type n, const reverse_iterator<Iter>& it){return it.base() - n;}

}
#endif