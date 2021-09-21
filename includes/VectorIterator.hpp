#include <iostream>

namespace ft
{

	template <class Vector>
	class VectorIterator
	{
	public:
		typedef typename Vector::value_type value_type;
		typedef value_type& reference;
		typedef value_type* pointer;
		typedef ptrdiff_t difference_type;

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

		VectorIterator operator-(difference_type n){
			VectorIterator __w(*this);
			__w.array -= n;
			return __w;
		}
		
		VectorIterator operator+(difference_type n){
			VectorIterator __w(*this);
			__w.array += n;
			return __w;
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