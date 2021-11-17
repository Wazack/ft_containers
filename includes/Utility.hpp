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

	pair& operator=(pair const& rhs)
	{
		first = rhs.first;
		second = rhs.second;
		return *this;
	}
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


//enable_if
template<bool Cond, class T = void> struct enable_if {};
template<class T> struct enable_if<true, T> { typedef T type; };


//is_integral
template <class T> struct type_is_integral : public std::false_type {};
template <> struct type_is_integral<bool> : public std::true_type {};
template <> struct type_is_integral<char> : public std::true_type {};
template <> struct type_is_integral<signed char> : public std::true_type {};
template <> struct type_is_integral<unsigned char> : public std::true_type {};
template <> struct type_is_integral<wchar_t> : public std::true_type {};
template <> struct type_is_integral<char16_t> : public std::true_type {};
template <> struct type_is_integral<char32_t> : public std::true_type {};
template <> struct type_is_integral<short> : public std::true_type {};
template <> struct type_is_integral<unsigned short> : public std::true_type {};
template <> struct type_is_integral<int> : public std::true_type {};
template <> struct type_is_integral<unsigned int> : public std::true_type {};
template <> struct type_is_integral<long> : public std::true_type {};
template <> struct type_is_integral<unsigned long> : public std::true_type {};
template <> struct type_is_integral<long long> : public std::true_type {};
template <> struct type_is_integral<unsigned long long> : public std::true_type {};
template <> struct type_is_integral<__int128_t> : public std::true_type {};
template <> struct type_is_integral<__uint128_t> : public std::true_type {};

template<class T>
struct is_integral : public type_is_integral<T> {};


//equal
template<class InputIt1, class InputIt2>
bool equal(InputIt1 first1, InputIt1 last1, 
		InputIt2 first2)
{
	for (; first1 != last1; ++first1, ++first2) {
		if (!(*first1 == *first2)) {
			return false;
		}
	}
	return true;
}

template<class InputIt1, class InputIt2, class BinaryPredicate>
bool equal(InputIt1 first1, InputIt1 last1, 
		InputIt2 first2, BinaryPredicate p)
{
	for (; first1 != last1; ++first1, ++first2) {
		if (!p(*first1, *first2)) {
			return false;
		}
	}
	return true;
}

template <class value_type> //A retirer
struct bst{
	value_type data;
	bst *left;
	bst *right;
	bst *parent;
};

}
#endif