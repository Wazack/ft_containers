#ifndef UTILITY_HPP
#define UTILITY_HPP

namespace ft
{
template <class T1, class T2>
struct pair
{
	typedef T1 first_type;
	typedef T2 second_type;

	T1 first;
	T2 second;

	pair() : first(), second(){}
	pair(first_type const& a, second_type const& b) : first(a), second(b){}
	template <class U, class V>
	pair(const pair<U, V>& pr) : first(pr.first), second(pr.second){}

	// pair& operator=(pair const& rhs)
	// {
	// 	this->first = rhs.first;
	// 	this->second = rhs.second;
	// 	return *this;
	// }
};

template <class T1, class T2>
bool operator==(const pair<T1, T2>& lhs, const pair<T1, T2>& rhs){return (lhs.first == rhs.first && lhs.second == rhs.second);}

template <class T1, class T2>
bool operator!=(const pair<T1, T2>& lhs, const pair<T1, T2>& rhs){return !(lhs == rhs);}

template <class T1, class T2>
bool operator<(const pair<T1, T2>& lhs, const pair<T1, T2>& rhs){return lhs.first<rhs.first || (!(rhs.first<lhs.first) && lhs.second<rhs.second);}

template <class T1, class T2>
bool operator<=(const pair<T1, T2>& lhs, const pair<T1, T2>& rhs){return !(rhs < lhs);}

template <class T1, class T2>
bool operator>(const pair<T1, T2>& lhs, const pair<T1, T2>& rhs){return (rhs < lhs);}

template <class T1, class T2>
bool operator>=(const pair<T1, T2>& lhs, const pair<T1, T2>& rhs){return !(lhs < rhs);}

template <class T1, class T2>
pair<T1, T2> make_pair(T1 x, T2 y)
{
	return (pair<T1, T2>(x, y));
}

template <class value_type>
struct bst{
	value_type data;
	bst *left;
	bst *right;
	bst *parent;
};
}
#endif