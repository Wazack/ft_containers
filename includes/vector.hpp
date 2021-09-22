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
		typedef VectorIterator<Vector<T> > iterator;

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
		iterator begin(){
			return (iterator(array));
		}
		
		iterator end(){
			return (iterator(array + _size));
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
		template <class InputIterator>
		void assign(InputIterator first, InputIterator last){
			iterator tmp = first;
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

		iterator insert(iterator position, const_reference val){
			size_t idx = 0;
			value_type* newArray;
			size_t newCapacity = 0;
			size_t y = 0;

			for (iterator it = this->begin(); it != position; ++it)
				idx++;
			if (_size >= _capacity)
			{
				if (_size == 0)
					newCapacity = 1;
				else
					newCapacity = _capacity * 2;
			}
			_size++;
			newArray = _alloc.allocate(newCapacity);
			for (size_t i = 0; i < _size; i++)
			{
				if (i == idx)
					_alloc.construct(newArray + i, val);
				else
					newArray[i] = array[y++];
			}
			_alloc.deallocate(array, _capacity);
			if (newCapacity)
				_capacity = newCapacity;
			array = newArray;
			return (iterator(array));
		}

		void insert(iterator position, size_type n, const value_type& val){
			size_t idx = 0;
			value_type* newArray;
			size_t newCapacity = 0;
			size_t y = 0;
			size_t i = 0;

			for (iterator it = this->begin(); it != position; ++it)
				idx++;
			if (_size >= _capacity)
			{
				if (_size == 0)
					newCapacity = n;
				else if (_capacity * 2 < _size + n)
					newCapacity = _size + n;
				else
					newCapacity = _capacity * 2;
			}
			_size += n;
			newArray = _alloc.allocate(newCapacity);
			while(i < _size)
			{
				if (i == idx)
					for (size_t u = 0; u < n; u++)
						_alloc.construct(newArray + i++, val);
				else
					newArray[i++] = array[y++];
			}
			_alloc.deallocate(array, _capacity);
			if (newCapacity)
				_capacity = newCapacity;
			array = newArray;			
		}

		void insert(iterator position, iterator first, iterator last){
			size_t n = 0;
			size_t idx = 0;
			size_t y = 0;
			size_t i = 0;
			size_t newCapacity = 0;
			value_type* newArray;
			reference val = *first;

			for (iterator tmp = first; tmp != last; ++tmp)
				n++;
			for (iterator it = this->begin(); it != position; ++it)
				idx++;
			if (_size >= _capacity)
			{
				if (_size == 0)
					newCapacity = n;
				else if (_capacity * 2 < _size + n)
					newCapacity = _size + n;
				else
					newCapacity = _capacity * 2;
			}
			_size += n;
			newArray = _alloc.allocate(newCapacity);
			while (i < _size)
			{
				if (i == idx)
					for (size_t u = 0; u < n; u++)
					{
						val = *first++;
						_alloc.construct(newArray + i++, val);
					}
				else
					newArray[i++] = array[y++];					
			}
			_alloc.deallocate(array, _capacity);
			if (newCapacity)
				_capacity = newCapacity;
			array = newArray;
		}

		//Erase
		iterator erase(iterator position){
			size_t i = 0;
			size_t y = 0;
			value_type* newArray;

			newArray = _alloc.allocate(_capacity);
			for (iterator it = this->begin(); it != this->end(); ++it)
			{
				if (it != position)
					newArray[i++] = array[y];
				y++;
			}
			_alloc.deallocate(array, _capacity);
			_size--;
			array = newArray;
			return (iterator(array));
		}

		iterator erase(iterator first, iterator last){
			value_type* newArray;
			size_t y = 0;
			size_t i = 0;
			iterator it;

			newArray = _alloc.allocate(_capacity);
			for (it = this->begin(); it != this->end(); ++it)
			{
				while (it == first && first != last)
				{
					y++;
					first++;
					it++;
				}
				newArray[i++] = array[y++];
			}
			_alloc.deallocate(array, _capacity);
			_size -= y - i;
			array = newArray;
			std::cout << "y: " << y - i << std::endl;
			return (iterator(array));
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