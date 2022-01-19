#ifndef FT_MAP_ITERATOR_HPP
#define FT_MAP_ITERATOR_HPP

#include "../vector/ft_iterator.hpp"
#include "../vector/ft_iterator_traits.hpp"
#include <iostream>

namespace ft {
    template<class T>//Node
    class map_iterator : public ft::iterator<std::bidirectional_iterator_tag, T> {
        public:
            typedef typename iterator<std::bidirectional_iterator_tag, T>::value_type::value_type value_type;
            typedef typename iterator<std::bidirectional_iterator_tag, T>::value_type val_type;
            typedef typename iterator<std::bidirectional_iterator_tag, T>::iterator_category iterator_category;
            typedef typename iterator<std::bidirectional_iterator_tag, T>::pointer	pointer;
            typedef typename iterator<std::bidirectional_iterator_tag, T>::reference	reference;
            typedef typename iterator<std::bidirectional_iterator_tag, T>::difference_type	difference_type;

            map_iterator(void) : _ip(nullptr) {}
            map_iterator(map_iterator const & src) : _ip(src._ip) {}
            map_iterator(pointer ip, pointer end) : _ip(ip), _end(end) {
            }
            map_iterator(pointer ip) : _ip(ip) {}

            ~map_iterator(void) {}
            //operator =
            map_iterator& operator=(map_iterator const & rhs) {
                if (this != &rhs) {
					this->_ip = rhs._ip;
				}
				return *this;
            }
            //compairing
            bool	operator ==(const map_iterator &b) {
                return (this->base() == b.base());
            }
            bool	operator !=(const map_iterator &b) {
                return  (this->base() != b.base());
            }
            //dereferenced as an rvalue
			value_type&	operator*() {
                return *(this->_ip->data);
            }
            value_type*	operator->() {//NOT IN ALL CASES WORK
				return &(operator*());
			}
            //inc and dec
            map_iterator&	operator++() {//++a
                if (this->_ip == _end) {
                    this->_ip = NULL;
                }
                else if (this->_ip == this->_ip->maxTree()) {
                    this->_ip = _end;
                }
                else {
                    this->_ip = this->_ip->successor();
                }
				return *this;
			}
			map_iterator&	operator--() {//--a
                std::cout <<"pre dec\n";
                if (this->_ip == _rend) {
                    this->_ip = NULL;
                }
                else if (this->_ip == this->_ip->minTree()) {
                    this->_ip = _end;
                }
                else {
                    this->_ip = this->_ip->predecessor();
                }
				return *this;
			}
			map_iterator		operator++(int) {//a++
				map_iterator ret(*this);
                if (this->_ip == _end) {
                    this->_ip = NULL;
                }
                else if (this->_ip == this->_ip->maxTree()) {
                    this->_ip = _end;
                }
                else {
                    this->_ip = this->_ip->successor();
                }
				return ret;
			}
			map_iterator		operator--(int) {//a--
                std::cout <<"post dec\n";
				map_iterator ret(*this);
                if (this->_ip == _rend) {
                    this->_ip = NULL;
                }
                else if (this->_ip == this->_ip->minTree()) {
                    this->_ip = _end;
                }
                else {
                    this->_ip = this->_ip->predecessor();
                }
				return ret;
			}
            //base
            pointer	 base(void) const {
                return this->_ip;
            }
        private:
            pointer _ip;
            pointer _end;
            pointer _rend;////////
    };
}

#endif