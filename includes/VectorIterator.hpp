#ifndef VECTORITERATOR_HPP
#define VECTORITERATOR_HPP

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
		pointer array;

	public:
		VectorIterator() : array(NULL){}
		VectorIterator(pointer ptr) : array(ptr){}
		VectorIterator(VectorIterator const & src) : array(src.array){}
		~VectorIterator(){}

		VectorIterator & operator=(VectorIterator const & rhs){
			this->array = rhs.array;
			return *this;
		}

		reference operator*(void){
			return (*array);
		}

		reference operator[](int index){
			return *(array + index);
		}

		pointer operator->(void){
			return (array);
		}

		VectorIterator & operator++(void){
			array++;
			return *this;
		}

		VectorIterator operator++(int){
			VectorIterator tmp = *this;
			this->array++;
			return (tmp);
		}

		VectorIterator operator-(difference_type n) const{
			VectorIterator __w(*this);
			__w.array -= n;
			return __w;
		}

		VectorIterator operator+(difference_type n) const{
			VectorIterator __w(*this);
			__w.array += n;
			return __w;
		}

		VectorIterator & operator+=(difference_type n){
			*this = *this + n;
			return *this;
		}

		VectorIterator & operator-=(difference_type n){
			*this = *this - n;
			return *this;
		}

		VectorIterator & operator--(void){
			array--;
			return *this;
		}

		VectorIterator operator--(int){
			VectorIterator tmp = *this;
			this->array--;
			return (tmp);
		}

		bool operator==(VectorIterator const & rhs) const{
			return this->array == rhs.array;
		}

		bool operator!=(VectorIterator const & rhs) const{
			return this->array != rhs.array;
		}

		bool operator>(VectorIterator const & rhs) const{
			return (this->array > rhs.array);
		}
		
		bool operator<(VectorIterator const & rhs) const{
			return (this->array < rhs.array);
		}
		
		bool operator>=(VectorIterator const & rhs) const{
			return (this->array >= rhs.array);
		}
		
		bool operator<=(VectorIterator const & rhs) const{
			return (this->array <= rhs.array);
		}
	};
}

#endif