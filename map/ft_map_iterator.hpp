#ifndef FT_MAP_ITERATOR_HPP
#define FT_MAP_ITERATOR_HPP

#include "../vector/ft_iterator.hpp"
#include <iostream>

namespace ft {
    template<class T>//Node
    class map_iterator : public ft::iterator<std::bidirectional_iterator_tag, T> {
        public:
            typedef typename iterator<std::bidirectional_iterator_tag, T>::value_type::value_type value_type;
            typedef typename iterator<std::bidirectional_iterator_tag, T>::iterator_category iterator_category;
            typedef typename iterator<std::bidirectional_iterator_tag, T>::pointer	pointer;
            typedef typename iterator<std::bidirectional_iterator_tag, T>::reference	reference;
            typedef typename iterator<std::bidirectional_iterator_tag, T>::difference_type	difference_type;

            map_iterator(void) : _ip(nullptr) {}
            map_iterator(map_iterator const & src) : _ip(src._ip) {}
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
                std::cout <<"pre inc\n";
                if (this->_ip != NULL) {
                    if (this->_ip->right != NULL) {
                        pointer succ = this->_ip;
                        while (succ->right != NULL)///wa9ila ghalate hhh
                            succ = succ->right->minimum();
                        this->_ip = succ;
                        /*
                        if (succ->right != NUll)
                            this->_ip = succ->right->minimum();
                        */
                    }
                    else {
                        pointer tmp = this->_ip;
                        if (tmp->parent && tmp->parent->left == tmp) {
                            tmp = tmp->parent;
                            this->_ip = tmp;
                        }
                        else {
                            this->_ip = NULL;
                        }
                    }
                }
				return *this;
			}
			map_iterator&	operator--() {//--a
                std::cout <<"pre dec\n";
                if (this->_ip != NULL) {
                    if (this->_ip->left != NULL) {
                        pointer pre = this->_ip;
                        while (pre->left != NULL)
                            pre = pre->left->maximum();
                        this->_ip = pre;
                    }
                    else {
                        pointer tmp = this->_ip;
                        if (tmp->parent && tmp->parent->right == tmp) {
                            tmp = tmp->parent;
                            this->_ip = tmp;
                        }
                        else {
                            this->_ip = NULL;
                        }
                    }
                }
				return *this;
			}
			map_iterator		operator++(int) {//a++
				map_iterator ret(*this);
                if (this->_ip != NULL) {
                    if (this->_ip->right != NULL) {
                        pointer succ = this->_ip;
                        while (succ->right != NULL)
                            succ = succ->right->minimum();
                        this->_ip = succ;
                    }
                    else {
                        pointer tmp = this->_ip;
                        if (tmp->parent && tmp->parent->left == tmp) {
                            tmp = tmp->parent;
                            this->_ip = tmp;
                        }
                        else {
                            this->_ip = NULL;
                        }
                    }
                }
				return ret;
			}
			map_iterator		operator--(int) {//a--
                std::cout <<"post dec\n";
				map_iterator ret(*this);
                if (this->_ip != NULL) {
                    if (this->_ip->left != NULL) {
                        pointer pre = this->_ip;
                        while (pre->left != NULL)
                            pre = pre->left->maximum();
                        this->_ip = pre;
                    }
                    else {
                        pointer tmp = this->_ip;
                        if (tmp->parent && tmp->parent->right == tmp) {
                            tmp = tmp->parent;
                        }
                        this->_ip = tmp;
                    }
                }
				return ret;
			}
            //base
            pointer	 base(void) const {
                return this->_ip;
            }
        private:
            pointer _ip;
    };
}

#endif