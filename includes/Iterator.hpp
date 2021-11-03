#ifndef ITERATOR_HPP
#define ITERATOR_HPP

#include <iostream>

namespace ft
{
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
		iterator_type _it;

	public:
		reverse_iterator() : _it(NULL){}
		explicit reverse_iterator(iterator_type it) : _it(it){}
		reverse_iterator(const reverse_iterator<Iter>& rev_it) : _it(rev_it._it){}

		template <class U>
		reverse_iterator& operator=(const reverse_iterator<U>& rhs){
			this->_it = rhs._it;
			return (*this);
		}

		iterator_type base() const{return (_it + 1);}

		reference operator*() const{
			Iter tmp = _it;
			return (*--tmp);
		}

		pointer operator->() const{return std::addressof(operator*());};

		reference operator[](difference_type n) const{ return *(*this + n);}

		reverse_iterator& operator++(){
			_it--;
			return *this;
		}

		reverse_iterator operator++(int){
			reverse_iterator tmp = *this;
			_it--;
			return tmp;
		}

		reverse_iterator& operator--(){
			_it++;
			return *this;
		}
		
		reverse_iterator operator--(int){
			reverse_iterator tmp = *this;
			_it++;
			return tmp;
		}

		reverse_iterator operator+(difference_type n) const{return _it - n;}
		
		reverse_iterator operator-(difference_type n) const{return _it + n;}

		reverse_iterator& operator+=(difference_type n){
			_it -= n;
			return *this;
		}
		
		reverse_iterator& operator-=(difference_type n){
			_it += n;
			return *this;
		}
	};
	template <class Iterator>
	bool operator==(const reverse_iterator<Iterator>& lhs, const reverse_iterator<Iterator>& rhs){return lhs.base() == rhs.base();}
	
	template <class Iterator>
	bool operator!=(const reverse_iterator<Iterator>& lhs, const reverse_iterator<Iterator>& rhs){return lhs.base() != rhs.base();}
	
	template <class Iterator>
	bool operator<(const reverse_iterator<Iterator>& lhs, const reverse_iterator<Iterator>& rhs){return lhs.base() < rhs.base();}
	
	template <class Iterator>
	bool operator<=(const reverse_iterator<Iterator>& lhs, const reverse_iterator<Iterator>& rhs){return lhs.base() <= rhs.base();}
	
	template <class Iterator>
	bool operator>(const reverse_iterator<Iterator>& lhs, const reverse_iterator<Iterator>& rhs){return lhs.base() > rhs.base();}
	
	template <class Iterator>
	bool operator>=(const reverse_iterator<Iterator>& lhs, const reverse_iterator<Iterator>& rhs){return lhs.base() >= rhs.base();}

	template <class Iter>
	reverse_iterator<Iter> operator+(typename reverse_iterator<Iter>::difference_type n, const reverse_iterator<Iter>& it){return it.base() - n;}

	template <class Iterator>
	typename reverse_iterator<Iterator>::difference_type operator-(const reverse_iterator<Iterator>& lhs, const reverse_iterator<Iterator>& rhs){return rhs.base() - lhs.base();}
}
#endif