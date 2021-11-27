#ifndef FT_ITERATOR_HPP
#define FT_ITERATOR_HPP

#include <iostream>

namespace ft {
	template <class Category, class T, class Distance = ptrdiff_t,
		class Pointer = T*, class Reference = T&>
	struct iterator {
		typedef T         value_type;
		typedef Distance  difference_type;
		typedef Pointer   pointer;
		typedef Reference reference;
		typedef Category  iterator_category;
	};

	template <class T>//T --> is myVector type
	class my_iterator : public iterator<std::random_access_iterator_tag, T> {
		public:
			typedef iterator<std::random_access_iterator_tag, T>::value_type value_type;
			typedef iterator<std::random_access_iterator_tag, T>::pointer	pointer;
			typedef iterator<std::random_access_iterator_tag, T>::reference	reference;
			typedef iterator<std::random_access_iterator_tag, T>::difference_type	difference_type;
			//constructor
			my_iterator(void);
			my_iterator(pointer ip);//iterator::pointer
			my_iterator(my_iterator const & src);
			//Destructor
			~my_iterator(void);
			//assignemet operator
			my_iterator& operator=(my_iterator const & rhs);
			//comparison operator
			bool T::operator ==(const T2 &b) const;
			bool T::operator !=(const T2 &b) const;
			bool T::operator <(const T2 &b) const;
			bool T::operator >(const T2 &b) const;
			bool T::operator <=(const T2 &b) const;
			bool T::operator >=(const T2 &b) const;
			//post and pre inc & dec
			T& T::operator++();//++a
			T& T::operator--();//--a
			T T::operator++(int);//a++
			T T::operator--(int);//a--
			//assignemet operator
			T& T::operator +=(const T2& b);
			T& T::operator -=(const T2& b);
			//dereferenced as an rvalue
			R& T::operator*();
			R* T::operator->();
			//dereference operator []
			R& T::operator[](S b);
			//arithmetic operators 
			T T::operator+(const T2 &b) const;//!
			T T::operator-(const T2 &b) const;//!
		private:
			pointer _ip;//iterator::pointer
	};
	T operator-(const T &a, const T &b);
}

#endif