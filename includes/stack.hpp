#include <iostream>
#include "Vector.hpp"
namespace ft
{
template <class T, class Container = ft::Vector<T> >
class stack
{
public:
	typedef Container									container_type;
	typedef typename container_type::value_type			value_type;
	typedef typename container_type::reference			reference;
	typedef typename container_type::const_reference	const_reference;
	typedef typename container_type::size_type			size_type;

protected:
	container_type c;

public:
	explicit stack(const container_type& cont = container_type()) : c(cont){}
	~stack(){}

	stack& operator=(const stack& other){
		this->c = other.c;
		return *this;
	}

	bool empty() const{return c.empty();}

	value_type& top(){return c.back();}
	const value_type& top() const{return c.back();}

	size_type size() const{return c.size();}

	void push(const value_type& value){c.push_back(value);}

	void pop(){c.pop_back();}

	template <class T1, class Container1>
	friend bool operator==(const stack<T1, Container1>& lhs, const stack<T1, Container1>& rhs);
	template <class T1, class Container1>
	friend bool operator!=(const stack<T1, Container1>& lhs, const stack<T1, Container1>& rhs);
	template <class T1, class Container1>
	friend bool operator<(const stack<T1, Container1>& lhs, const stack<T1, Container1>& rhs);
	template <class T1, class Container1>
	friend bool operator<=(const stack<T1, Container1>& lhs, const stack<T1, Container1>& rhs);
	template <class T1, class Container1>
	friend bool operator>(const stack<T1, Container1>& lhs, const stack<T1, Container1>& rhs);
	template <class T1, class Container1>
	friend bool operator>=(const stack<T1, Container1>& lhs, const stack<T1, Container1>& rhs);
};

template <class T, class Container>
bool operator==(const stack<T, Container>& lhs, const stack<T, Container>& rhs){return lhs.c == rhs.c;}
template <class T, class Container>
bool operator!=(const stack<T, Container>& lhs, const stack<T, Container>& rhs){return lhs.c != rhs.c;}
template <class T, class Container>
bool operator<(const stack<T, Container>& lhs, const stack<T, Container>& rhs){return lhs.c < rhs.c;}
template <class T, class Container>
bool operator<=(const stack<T, Container>& lhs, const stack<T, Container>& rhs){return lhs.c <= rhs.c;}
template <class T, class Container>
bool operator>(const stack<T, Container>& lhs, const stack<T, Container>& rhs){return lhs.c > rhs.c;}
template <class T, class Container>
bool operator>=(const stack<T, Container>& lhs, const stack<T, Container>& rhs){return lhs.c >= rhs.c;}
}