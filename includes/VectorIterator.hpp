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

	template <class Iter>
	class VectorReverseIter
	{
	private:
		typedef Iter iterator_type;
		typedef typename ft::VectorIterator<Iter>::value_type value_type;
		typedef typename ft::VectorIterator<Iter>::difference_type difference_type;
		typedef typename ft::VectorIterator<Iter>::pointer pointer;
		typedef typename ft::VectorIterator<Iter>::reference reference;

	private:
		iterator_type _it;

	public:
		VectorReverseIter() : _it(NULL){}
		VectorReverseIter(iterator_type it) : _it(it){}
		VectorReverseIter(VectorReverseIter const & src) : _it(src._it){}
		~VectorReverseIter(){}

		VectorReverseIter & operator=(VectorReverseIter const & rhs){
			this->_it = rhs._it;
			return *this;
		}

		iterator_type base() const {
			return (_it + 1);
		}

		reference operator*(){
			return (*_it);
		}

		pointer operator->() const{
			return (_it);
		}


		VectorReverseIter & operator++(){
			_it--;
			return *this;
		}

		VectorReverseIter operator++(int){
			VectorReverseIter tmp = *this;
			_it--;
			return tmp;
		}

		VectorReverseIter operator+(difference_type n) const {return (VectorReverseIter(_it - n));}

		VectorReverseIter & operator+=(difference_type n){
			_it -= n;
			return *this;
		}
		
		VectorReverseIter & operator--(){
			_it++;
			return *this;
		}

		VectorReverseIter operator--(int){
			VectorReverseIter tmp = *this;
			_it++;
			return tmp;
		}

		VectorReverseIter operator-(difference_type n) const {return (VectorReverseIter(_it + n));}
		
		VectorReverseIter & operator-=(difference_type n){
			_it += n;
			return *this;
		}
		reference operator[](difference_type __n) const{return *(*this + __n);}
	};
}