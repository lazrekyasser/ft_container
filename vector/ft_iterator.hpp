#ifndef FT_ITERATOR_HPP
#define FT_ITERATOR_HPP

#include <iostream>
#include <algorithm>
#include "ft_iterator_traits.hpp"

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
			typedef typename iterator<std::random_access_iterator_tag, T>::value_type value_type;
			// typedef typename iterator<std::random_access_iterator_tag, T>::const_value_type const_value_type;
			typedef typename iterator<std::random_access_iterator_tag, T>::pointer	pointer;
			typedef typename iterator<std::random_access_iterator_tag, T>::reference	reference;
			typedef typename iterator<std::random_access_iterator_tag, T>::difference_type	difference_type;
			//constructor
			my_iterator(void) : _ip(nullptr) {}
			my_iterator(pointer ip) : _ip(ip) {}//iterator::pointer
			my_iterator(my_iterator const & src) : _ip(src._ip) {}///////
			//Destructor
			~my_iterator(void) {}
			operator my_iterator<const T>() {
				std::cout <<"const T called\n";
				return my_iterator<const T>(this->_ip);
			}
			//assignemet operator
			my_iterator& operator=(my_iterator const & rhs) {
				if (this != &rhs) {
					this->_ip = rhs._ip;
				}
				return *this;
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
			value_type*	operator->() {//NOT IN ALL CASES WORK
				return &(operator*());
			}
			//dereference operator []
			value_type&	operator[](unsigned int b) {//return  value_type
				return *(this->_ip + b);
			}
			//arithmetic operators 
			my_iterator	operator+(const difference_type &b) const {
				return my_iterator(this->_ip + b);
			}
			my_iterator	operator-(const difference_type &b) const {
				return my_iterator(this->_ip - b);
			}
			/*
	
	bool	operator ==(const iterator &b) {
		return (a.base() == b.base());
	}
	bool	operator !=(const iterator &b) {
		return  (a.base() != b.base());
	}
	bool	operator <(const iterator &b) {
		return (a.base() < b.base());
	}
	bool	operator >(const iterator &b) {
		return (a.base() > b.base());//compare addresses
	}
	bool	operator <=(const iterator &b) {
		return (a.base() <= b.base());
	}
	bool	operator >=(const iterator &b) {
		return (a.base() >= b.base());
	}
			*/
			pointer	 base(void) const {
				return this->_ip;
			}
		private:
			pointer _ip;//iterator::pointer
	};
	//REVERSE_ITERATOR
	template<class Iterator>
	// class reverse_iterator : public ft::iterator_traits<Iterator> {
	class reverse_iterator : public iterator<typename iterator_traits<Iterator>::iterator_category,
                      typename iterator_traits<Iterator>::value_type,
                      typename iterator_traits<Iterator>::difference_type,
                      typename iterator_traits<Iterator>::pointer,
                      typename iterator_traits<Iterator>::reference> {
		public:
			typedef Iterator													iterator_type;
			typedef typename ft::iterator_traits<Iterator>::iterator_category	iterator_category;
			typedef typename ft::iterator_traits<Iterator>::value_type			value_type;
			typedef typename ft::iterator_traits<Iterator>::difference_type		difference_type;
			typedef typename ft::iterator_traits<Iterator>::pointer				pointer;
			typedef typename ft::iterator_traits<Iterator>::reference			reference;
			
			reverse_iterator(void) : _ip(nullptr) {}
			reverse_iterator(pointer ip) : _ip(ip) {}//iterator::pointer
			reverse_iterator(reverse_iterator const & src) : _ip(src._ip) {}///////
			//Destructor
			~reverse_iterator(void) {}

			template<class v>
			operator reverse_iterator<v>() {
				std::cout <<"Iterator called\n";
				return reverse_iterator<v>(this->_ip);
			}//cast to ==>const_reverse_iterator
			
			//assignemet operator
			reverse_iterator& operator=(reverse_iterator const & rhs) {
				if (this != &rhs) {
					this->_ip = rhs._ip;
				}
				return *this;
			}
			
			//post and pre inc & dec
			reverse_iterator&	operator++() {//++a
				--_ip;
				return *this;
			}
			reverse_iterator&	operator--() {//--a
				++_ip;
				return *this;
			}
			reverse_iterator		operator++(int) {//a++
				reverse_iterator ret(*this);
				--_ip;
				return ret;
			}
			reverse_iterator		operator--(int) {//a--
				reverse_iterator ret(*this);
				++_ip;
				return ret;
			}
			//assignemet operator
			reverse_iterator&	operator +=(const unsigned int & b) {
				_ip -= b;
				return *this;
			}
			reverse_iterator&	operator -=(const unsigned int & b) {
				_ip += b;
				return *this;
			}
			//dereferenced as an rvalue
			value_type&	operator*() {//return  value_type
				return *(this->_ip - 1);
			}
			value_type*	operator->() {//NOT IN ALL CAS WORK
				return &(operator*());
			}
			//dereference operator []
			value_type&	operator[](unsigned int b) {//return  value_type
				return *(this->_ip + b);
			}
			//arithmetic operators 
			reverse_iterator	operator+(const difference_type &b) const {
				return reverse_iterator(this->_ip - b);//-
			}
			reverse_iterator	operator-(const difference_type &b) const {
				return reverse_iterator(this->_ip + b);//+
			}
			pointer	 base(void) const {
				return this->_ip;
			}
			/*
	
	bool	operator ==(const reverse_iterator &b) {
		return (a.base() == b.base());
	}
	bool	operator !=(const reverse_iterator &b) {
		return  (a.base() != b.base());
	}
	bool	operator <(const reverse_iterator &b) {
		return (a.base() < b.base());
	}
	bool	operator >(const reverse_iterator &b) {
		return (a.base() > b.base());//compare addresses
	}
	bool	operator <=(const reverse_iterator &b) {
		return (a.base() <= b.base());
	}
	bool	operator >=(const reverse_iterator &b) {
		return (a.base() >= b.base());
	}
			*/
		private:
			pointer _ip;//iterator::pointer
	};
	//comparison operator // non-membre function
	template<class Iterator1, class Iterator2>
	bool	operator ==(const Iterator1 &a, const Iterator2 &b) {
		return (a.base() == b.base());
	}
	template<class Iterator1, class Iterator2>
	bool	operator !=(const Iterator1 &a, const Iterator2 &b) {
		return  (a.base() != b.base());
	}
	template<class Iterator1, class Iterator2>
	bool	operator <(const Iterator1 &a, const Iterator2 &b) {
		return (a.base() < b.base());
	}
	template<class Iterator1, class Iterator2>
	bool	operator >(const Iterator1 &a, const Iterator2 &b) {
		return (a.base() > b.base());//compare addresses
	}
	template<class Iterator1, class Iterator2>
	bool	operator <=(const Iterator1 &a, const Iterator2 &b) {
		return (a.base() <= b.base());
	}
	template<class Iterator1, class Iterator2>
	bool	operator >=(const Iterator1 &a, const Iterator2 &b) {
		return (a.base() >= b.base());
	}
	//a - b
	template <class Iterator>
	typename Iterator::difference_type operator-(const Iterator &a, const Iterator &b) {
		return a.base() - b.base();
	}
}

#endif