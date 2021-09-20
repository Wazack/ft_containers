#include <iostream>
#include <math.h>
#include "VectorIterator.hpp"


namespace ft
{
	template <class Vector>
	class VectorIterator;

	template < class T, class Alloc = std::allocator<T> >
    class Vector
    {
    public:
		typedef T value_type;
		typedef Alloc allocator_type;
		typedef value_type& reference;
		typedef const value_type& const_reference;
		typedef size_t	size_type;
		// typedef VectorIterator<Vector<T> > iterator;

	private:
		size_t _size;
		size_t _capacity;
		allocator_type _alloc;
		value_type* array;

	private:
		void reAlloc(size_type newCapacity){
			value_type* newArray = _alloc.allocate(newCapacity);

			for (size_t i = 0; i < _size; i++)
				newArray[i] = array[i];
			_alloc.deallocate(array, _capacity);
			array = newArray;
			_capacity = newCapacity;			
		}

	public:
		//Constructor
		explicit Vector(const allocator_type& alloc = allocator_type()) : _size(0), _capacity(0), _alloc(alloc), array(NULL){}

		explicit Vector(size_type n, const_reference val = value_type(),
		const allocator_type& alloc = allocator_type()) : _size(n), _capacity(n), _alloc(alloc){
			array = _alloc.allocate(_capacity);
			for (size_t i = 0; i < _capacity; i++)
				_alloc.construct(array + i, val);
		}

		~Vector(){
			_alloc.deallocate(array, _capacity);
			_alloc.destroy(array);
		}

		//Iterator
		VectorIterator begin(){
			return (VectorIterator(array));
		}

		//Capacity
		value_type size(void) const {return this->_size;}

		value_type capacity(void) const {return this->_capacity;}

		size_type max_size(void) const {return (_alloc.max_size());}

		bool empty(void) const {return _size == 0;}

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
				{
					_alloc.construct(array + i);
				}
			}
		}

		//Modifier
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

		void pop_back(void){
			_size--;
			array[_size].~T();
		}

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
    };
}