#ifndef FT_ITERATOR_HPP
#define FT_ITERATOR_HPP

#include <iostream>
#include <algorithm>
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
			my_iterator(void) : _ip(nullptr) {}
			my_iterator(pointer ip) : _ip(ip) {}//iterator::pointer
			my_iterator(my_iterator const & src) : _ip(src._ip) {}
			//Destructor
			~my_iterator(void);
			//assignemet operator
			my_iterator& operator=(my_iterator const & rhs) {
				if (this != &rhs) {
					this->_ip = rhs._ip;
				}
				return *this;
			}
			//comparison operator
			bool	operator ==(const my_iterator &b) const {
				return (this->_ip == b._ip);
			}
			bool	operator !=(const my_iterator &b) const {
				return  (this->_ip != b._ip);
			}
			bool	operator <(const my_iterator &b) const {
				return (this->_ip < b._ip);
			}
			bool	operator >(const my_iterator &b) const {
				return (this->_ip > b._ip);//compare addresses
			}
			bool	operator <=(const my_iterator &b) const {
				return (this->_ip <= b._ip);
			}
			bool	operator >=(const my_iterator &b) const {
				return (this->_ip >= b._ip);
			}
			//post and pre inc & dec
			my_iterator&	operator++() {//++a
				++_ip;
				return *this;
			}
			my_iterator&	operator--() {//--a
				--_ip;
				return *this;
			}
			my_iterator		operator++(int) {//a++
				my_iterator ret(*this);
				++_ip;
				return ret;
			}
			my_iterator		operator--(int) {//a--
				my_iterator ret(*this);
				--_ip;
				return ret;
			}
			//assignemet operator
			my_iterator&	operator +=(const unsigned int & b) {
				_ip += b;
				return *this;
			}
			my_iterator&	operator -=(const unsigned int & b) {
				_ip -= b;
				return *this;
			}
			//dereferenced as an rvalue
			value_type&	operator*() {//return  value_type
				return *this->_ip;
			}
			// value_type*	operator->();NOT IN ALL CAS WORK
			//dereference operator []
			value_type&	operator[](unsigned int b) {//return  value_type
				return *(this->_ip + b);
			}
			//arithmetic operators 
			my_iterator	operator+(const difference_type &b) const {
				return new my_iterator(this->_ip + b);
			}
			T	operator-(const difference_type &b) const {
				return new my_iterator(this->ip - b);
			}
		private:
			pointer _ip;//iterator::pointer
	};
	//a - b
	template <class Iterator>
	typename Iterator::difference_type operator-(const Iterator &a, const Iterator &b);//
}

#endif