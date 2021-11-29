#ifndef VECTOR_HPP
#define VECTOR_HPP

#include <iostream>
#include <math.h>
#include "VectorIterator.hpp"
#include "Iterator.hpp"
#include "Utility.hpp"
#include <type_traits>

namespace ft
{
	template <class vector>
	class VectorIterator;

	template < class T, class Alloc = std::allocator<T> >
    class vector
    {
	public:
		typedef T											value_type;
		typedef Alloc										allocator_type;
		typedef typename allocator_type::reference			reference;
		typedef typename allocator_type::const_reference	const_reference;
		typedef typename allocator_type::pointer			pointer;
		typedef typename allocator_type::const_pointer		const_pointer;
		typedef VectorIterator<pointer> 					iterator;
		typedef VectorIterator<const_pointer>				const_iterator;
		typedef ft::reverse_iterator<iterator> 				reverse_iterator;
		typedef ft::reverse_iterator<const_iterator> 		const_reverse_iterator;
		typedef ptrdiff_t 									difference_type;
		typedef size_t										size_type;

	private:
		size_type		_size;
		size_type		_capacity;
		allocator_type	_alloc;
		pointer		array;

	private:
		void reAlloc(size_type newCapacity){
			value_type* newArray = _alloc.allocate(newCapacity);

			for (size_t i = 0; i < _size; i++)
				newArray[i] = array[i];
			_alloc.deallocate(array, _capacity);
			array = newArray;
			_capacity = newCapacity;			
		}

		void reAllocInsert(value_type val, size_type find, size_type n){
			pointer	newArray;
			size_type	y = 0;

			_size += n;
			newArray = _alloc.allocate(_size);
			for (size_t i = 0; i < _size; i++)
			{
				if (i == find)
				{
					while (n--)
						_alloc.construct(newArray + i++, val);
					i--;
				}
				else
					newArray[i] = array[y++];
			}
			_alloc.deallocate(array, _size);
			array = newArray;
		}

		template <class InputIterator>
		void reAllocInsertIt(size_type find, size_type n, InputIterator first){
			pointer	newArray;
			size_type	y = 0;

			_size += n;
			newArray = _alloc.allocate(_size);
			for (size_t i = 0; i < _size; i++)
			{
				if (i == find)
				{
					while (n--)
						_alloc.construct(newArray + i++, *first++);
					i--;
				}
				else
					newArray[i] = array[y++];
			}
			_alloc.deallocate(array, _size);
			array = newArray;
		}

	public:
		//Constructor
		explicit vector(const allocator_type& alloc = allocator_type()) : _size(0), _capacity(0), _alloc(alloc), array(){}

		explicit vector(size_type n, const_reference val = value_type(),
		const allocator_type& alloc = allocator_type()) : _size(n), _capacity(n), _alloc(alloc){
			array = _alloc.allocate(_capacity);
			for (size_t i = 0; i < _capacity; i++)
				_alloc.construct(array + i, val);
		}

		template <class InputIterator>
		vector(InputIterator first, InputIterator last,	const allocator_type& alloc = allocator_type(),
				typename enable_if<!is_integral<InputIterator>::value>::type* = 0) : _alloc(alloc)
		{
			size_type size = 0;

			for (InputIterator it = first; it != last; ++it)
				size++;
			_capacity = size;
			_size = size;
			array = _alloc.allocate(size);
			for (size_t i = 0; i < size; i++)
				_alloc.construct(array + i, *first++);
		}

		vector(const vector& x) : _size(x._size), _capacity(x._size), _alloc(x._alloc){
			array = _alloc.allocate(_capacity);
			for (size_t i = 0; i < _size; i++)
				array[i] = x.array[i];
		}

		~vector(){
			_alloc.deallocate(array, _capacity);
			if (_capacity)
				_alloc.destroy(array);
		}

		vector& operator=(const vector& rhs){
			_size = rhs._size;
			_capacity = rhs._size;
			_alloc = rhs._alloc;
			array = _alloc.allocate(_capacity);
			for (size_t i = 0; i < _size; i++)
				array[i] = rhs.array[i];
			return *this;
		}

		//Iterator
		iterator begin(){
			return (array);
		}

		const_iterator begin() const{
			return (array);
		}

		iterator end(){
			return (iterator(array + _size));
		}

		const_iterator end() const{
			return (const_iterator(array + _size));
		}

		reverse_iterator rbegin(){
			return reverse_iterator(end());
		}

		const_reverse_iterator rbegin() const{
			return const_reverse_iterator(end());
		}

		reverse_iterator rend(){
			return reverse_iterator(begin());
		}

		const_reverse_iterator rend() const{
			return const_reverse_iterator(begin());
		}

		//Capacity
		size_type size(void) const {return this->_size;}

		size_type capacity(void) const {return this->_capacity;}

		size_type max_size(void) const {return (_alloc.max_size());}

		bool empty(void) const {return _size == 0;}

		void resize(size_type n, value_type val = value_type()){
			if (n > _capacity)
			{
				if (_capacity * 2 > n)
					reAlloc(_capacity * 2);
				else
					reAlloc(n);
			}
			for (size_t i = _size; i < n; i++)
				_alloc.construct(array + i, val);
			_size = n;
		}

		void reserve(size_type n){
			value_type* tmp ;

			if (n > _capacity)
			{
				tmp = array;
				_alloc.deallocate(array, _capacity);
				array = _alloc.allocate(n);
				for (size_t i = 0; i < _size; i++)
					array[i] = tmp[i];
				_capacity = n;
				for (size_t i = _size; i < n; i++)
					_alloc.construct(array + i);
			}
		}

		//Modifier
			//ASSIGN
		template <class InputIterator>
		typename enable_if<!is_integral<InputIterator>::value>::type
			assign(InputIterator first, InputIterator last){
			InputIterator tmp = first;
			size_t size = 0;
			reference val = *first;

			for (; tmp != last; ++tmp)
				size++;
			if (size > _capacity)
				reAlloc(size);
			for (size_t i = 0; i < size; i++)
			{
				val = *first++;
				_alloc.construct(array + i, val);
			}
			_size = size;
		}

		void assign(size_type n, const_reference val){
			if (_capacity < n)
				reAlloc(n);
			for (size_t i = 0; i < n; i++)
				_alloc.construct(array + i, val);
			_size = n;
		}
			//PUSH_BACK
		void push_back(const_reference val){
			if (_size >= _capacity)
			{
				if (_size == 0)
					reAlloc(1);
				else
					reAlloc(_size * 2);
			}
			_alloc.construct(array + _size, val);
			_size++;
		}
			//POP_BACK
		void pop_back(void){
			_size--;
			array[_size].~T();
		}
			//INSERT
		iterator insert(iterator position, const_reference val){
			size_type	idx = 0;
			for (iterator it = begin(); it != position; ++it)
				idx++;
			if (_size >= _capacity)
			{
				if (_size == 0)
					reAlloc(1);
				else
					reAlloc(_capacity * 2);
			}
			reAllocInsert(val, idx, 1);
			return (begin());
		}
			//INSERT
		void insert(iterator position, size_type n, const value_type& val){
			size_t idx = 0;

			for (iterator it = this->begin(); it != position; ++it)
				idx++;
			if (_size >= _capacity)
			{
				if (_size == 0)
					reAlloc(n);
				else if (_capacity * 2 < _size + n)
					reAlloc(_size + n);
				else
					reAlloc(_capacity * 2);
			}
			reAllocInsert(val, idx, n);		
		}

		template <class InputIterator>
		typename enable_if<!is_integral<InputIterator>::value>::type
			insert(iterator position, InputIterator first, InputIterator last){
			size_t n = 0;
			size_t idx = 0;

			for (InputIterator tmp = first; tmp != last; ++tmp)
				n++;
			for (iterator it = this->begin(); it != position; ++it)
				idx++;
			if (_size >= _capacity)
			{
				if (_size == 0)
					reAlloc(n);
				else if (_capacity * 2 < _size + n)
					reAlloc(_size + n);
				else
					reAlloc(_capacity * 2);
			}
			reAllocInsertIt(idx, n, first);
		}

		//ERASE
		iterator erase(iterator position){
			difference_type ps = position - begin();
			pointer p = array + ps;

			if (position + 1 != end())
				for (; (size_type)ps < _size; ps++)
					array[ps] = array[ps + 1];
			_alloc.destroy(array + _size);		
			_size--;
			return (iterator(p));
		}

		iterator erase(iterator first, iterator last){
			pointer p = array + (first - begin());

			last--;
			for (; first - 1 != last; --last)
				erase(last);
			return (iterator(p));
		}
			//SWAP
		void swap(vector& x){
			size_type size = x._size;
			size_type capacity = x._capacity;
			value_type* arr = x.array;

			x._size = this->_size;
			x._capacity = this->_capacity;
			x.array = this->array;

			this->_size = size;
			this->_capacity = capacity;
			this->array = arr;
		}
			//CLEAR
		void clear(void){
			for (size_t i = 0; i < _size; i++)
				array[i].~T();
			_size = 0;
		}

		//Element access
		reference operator[](size_type index){return (array[index]);}
		
		const_reference operator[](size_type index) const{return (array[index]);}

		reference at(size_type n){
			if (n >= _size)
				throw(std::out_of_range("vector"));
			return (array[n]);
		}
		
		const_reference at(size_type n) const{
			if (n >= _size)
				throw(std::out_of_range("vector"));
			return (array[n]);
		}

		reference front(){return (array[0]);}
		
		const_reference front() const{return (array[0]);}

		reference back(){return (array[_size - 1]);}
		
		const_reference back() const{return (array[_size - 1]);}

		allocator_type get_allocator() const{return _alloc;}
    };

	template <class T, class Alloc>
	bool operator==(const vector<T, Alloc>& lhs, const vector<T, Alloc>& rhs){
		if (lhs.size() != rhs.size())
			return false;
		for (size_t i = 0; i < lhs.size(); i++)
			if (lhs[i] != rhs[i])
				return false;		
		return true;
	}

	template <class T, class Alloc>
	bool operator!=(const vector<T, Alloc>& lhs, const vector<T, Alloc>& rhs){
		if (lhs.size() != rhs.size())
			return true;
		for (size_t i = 0; i < lhs.size(); i++)
			if (lhs[i] != rhs[i])
				return true;
		return false;
	}
	
	template <class T, class Alloc>
	bool operator<(const vector<T, Alloc>& lhs, const vector<T, Alloc>& rhs){
		for (size_t i = 0; i < lhs.size(); i++)
			if (lhs[i] < rhs[i])
				return true;
		if (lhs.size() < rhs.size())
			return true;
		return false;		
	}

	template <class T, class Alloc>
	bool operator<=(const vector<T, Alloc>& lhs, const vector<T, Alloc>& rhs){
		for (size_t i = 0; i < lhs.size(); i++)
			if (lhs[i] <= rhs[i])
				return true;
		if (lhs.size() < rhs.size())
			return true;
		return false;
	}

	template <class T, class Alloc>
	bool operator>(const vector<T, Alloc>& lhs, const vector<T, Alloc>& rhs){
		for (size_t i = 0; i < lhs.size(); i++)
			if (lhs[i] > rhs[i])
				return true;
		return false;		
	}

	template <class T, class Alloc>
	bool operator>=(const vector<T, Alloc>& lhs, const vector<T, Alloc>& rhs){
		for (size_t i = 0; i < lhs.size(); i++)
			if (lhs[i] >= rhs[i])
				return true;
		return false;		
	}

	template <class T, class Alloc>
	void swap(vector<T, Alloc>& lhs, vector<T, Alloc>& rhs){lhs.swap(rhs);}
}

#endif