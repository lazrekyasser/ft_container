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
            typedef typename iterator<std::bidirectional_iterator_tag, T>::value_type val_type;//
            typedef typename iterator<std::bidirectional_iterator_tag, T>::iterator_category iterator_category;
            typedef typename iterator<std::bidirectional_iterator_tag, T>::pointer	pointer;
            typedef typename iterator<std::bidirectional_iterator_tag, T>::reference	reference;
            typedef typename iterator<std::bidirectional_iterator_tag, T>::difference_type	difference_type;

            map_iterator(void) : _ip(nullptr), _end(nullptr), _rend(nullptr), _root(nullptr) {}
            map_iterator(map_iterator const & src) : _ip(src._ip), _end(src._end), _rend(src._rend), _root(src._root) {}
            map_iterator(pointer ip, pointer end, pointer rend, pointer root) : _ip(ip), _end(end), _rend(rend), _root(root) {
            }
            map_iterator(pointer ip) : _ip(ip) {}

            ~map_iterator(void) {}
            //operator =
            map_iterator& operator=(map_iterator const & rhs) {
                if (this != &rhs) {
					this->_ip = rhs._ip;
                    this->_end = rhs._end;
                    this->_rend = rhs._rend;
				}
				return *this;
            }
            operator map_iterator<const T>() {
				std::cout <<"const T called\n";
				return map_iterator<const T>(this->_ip);
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
                else if (this->_ip == _rend) {
                    this->_ip = this->_root->minTree();
                }
                else if (this->_ip == this->_root->maxTree()) {
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
                else if (this->_ip == _end) {
                    std::cout <<"okk\n";
                    std::cout <<this->_ip->data->first <<std::endl;
                    this->_ip = this->_root->maxTree();
                    std::cout <<this->_ip->data->first <<std::endl;
                }
                else if (this->_ip == this->_root->minTree()) {
                    this->_ip = _rend;
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
                else if (this->_ip == _rend) {
                    this->_ip = this->_root->minTree();
                }
                else if (this->_ip == this->_root->maxTree()) {
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
                else if (this->_ip == _end) {
                    this->_ip = this->_root->maxTree();
                }
                else if (this->_ip == this->_root->minTree()) {
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
            pointer _root;
    };
    template<class Iterator>//Node
    class map_reverse_iterator : public ft::iterator<std::bidirectional_iterator_tag, Iterator> {
        public:
            typedef Iterator								iterator_type;
            typedef typename iterator<std::bidirectional_iterator_tag, Iterator>::value_type::value_type value_type;
            typedef typename iterator<std::bidirectional_iterator_tag, Iterator>::value_type val_type;//
            typedef typename iterator<std::bidirectional_iterator_tag, Iterator>::iterator_category iterator_category;
            typedef typename iterator<std::bidirectional_iterator_tag, Iterator>::pointer	pointer;
            typedef typename iterator<std::bidirectional_iterator_tag, Iterator>::reference	reference;
            typedef typename iterator<std::bidirectional_iterator_tag, Iterator>::difference_type	difference_type;

            map_reverse_iterator(void) : _ip(nullptr), _end(nullptr), _rend(nullptr), _root(nullptr) {}
            map_reverse_iterator(map_reverse_iterator const & src) : _ip(src._ip), _end(src._end), _rend(src._rend), _root(src._root) {}
            map_reverse_iterator(pointer ip, pointer end, pointer rend, pointer root) : _ip(ip), _end(end), _rend(rend), _root(root) {
            }
            map_reverse_iterator(pointer ip) : _ip(ip) {}

            ~map_reverse_iterator(void) {}
            //operator =
            map_reverse_iterator& operator=(map_reverse_iterator const & rhs) {
                if (this != &rhs) {
					this->_ip = rhs._ip;
                    this->_end = rhs._end;
                    this->_rend = rhs._rend;
				}
				return *this;
            }
            template<V>
            operator map_reverse_iterator<V>() {
				std::cout <<"V called\n";
				return map_reverse_iterator<V>(this->_ip);
			}
            //compairing
            bool	operator ==(const map_reverse_iterator &b) {
                return (this->base() == b.base());
            }
            bool	operator !=(const map_reverse_iterator &b) {
                return  (this->base() != b.base());
            }
            //dereferenced as an rvalue
			value_type&	operator*() {
                this->operator--();
                return *(this->_ip->data);
            }
            value_type*	operator->() {//NOT IN ALL CASES WORK
				return &(operator*());
			}
            //inc and dec
            map_reverse_iterator&	operator++() {//++a
                if (this->_ip == _end) {
                    this->_ip = NULL;
                }
                else if (this->_ip == _rend) {
                    this->_ip = this->_root->minTree();
                }
                else if (this->_ip == this->_root->maxTree()) {
                    this->_ip = _end;
                }
                else {
                    this->_ip = this->_ip->successor();
                }
				return *this;
			}
			map_reverse_iterator&	operator--() {//--a
                std::cout <<"pre dec\n";
                if (this->_ip == _rend) {
                    this->_ip = NULL;
                }
                else if (this->_ip == _end) {
                    this->_ip = this->_root->maxTree();
                }
                else if (this->_ip == this->_root->minTree()) {
                    this->_ip = _rend;
                }
                else {
                    this->_ip = this->_ip->predecessor();
                }
				return *this;
			}
			map_reverse_iterator		operator++(int) {//a++
				map_reverse_iterator ret(*this);
                if (this->_ip == _end) {
                    this->_ip = NULL;
                }
                else if (this->_ip == _rend) {
                    this->_ip = this->_root->minTree();
                }
                else if (this->_ip == this->_root->maxTree()) {
                    this->_ip = _end;
                }
                else {
                    this->_ip = this->_ip->successor();
                }
				return ret;
			}
			map_reverse_iterator		operator--(int) {//a--
                std::cout <<"post dec\n";
				map_reverse_iterator ret(*this);
                if (this->_ip == _rend) {
                    this->_ip = NULL;
                }
                else if (this->_ip == _end) {
                    this->_ip = this->_root->maxTree();
                }
                else if (this->_ip == this->_root->minTree()) {
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
            pointer _root;
    };
}

#endif