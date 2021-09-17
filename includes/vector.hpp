#include <iostream>
#include <vector>

namespace ft
{
	template < class T, class Alloc = std::allocator<T> >
    class Vector
    {
    public:
		typedef T value_type;
		typedef Alloc allocator_type;
		typedef value_type& reference;
		typedef const value_type& const_reference;
		typedef typename std::size_t	size_type;

	private:
		size_t _size = 0;
		size_t _capacity = 0;
		value_type* array;

	private:
		void ReAlloc(size_t newCapacity){
			
		}

	public:
		//Constructor
		explicit Vector(const allocator_type& alloc = allocator_type()) : _size(0){
			std::cout << "Default Constructor called" << std::endl;
			(void)alloc;
		}

		explicit Vector(size_type n, const value_type& val = value_type(),
		const allocator_type& alloc = allocator_type()) : _size(n){
			(void)val;
			(void)alloc;
			std::cout << "Fill Constructor called with size: " << this->_size << std::endl;
		}
    };
}