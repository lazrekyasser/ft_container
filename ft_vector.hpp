#ifndef FT_VECTOR_HPP
#define FT_VECTOR_HPP

#include <memory>
#include <iostream>
#include <iterator>
#include "ft_iterator.hpp"

namespace ft
{
	template <class T, class Alloc = std::allocator<T> >
	class vector {
		public:
			//typedef's
			typedef T                               value_type;
			typedef Alloc							allocator_type;
			typedef T&								reference;
			typedef const T&						const_reference;
			typedef T*								pointer;
			typedef const T*						const_pointer;
			typedef my_iterator<T>  				iterator;
			// typedef const_iterator
			// typedef reverse_iterator
			// typedef const_reverse_iterator
			typedef std::ptrdiff_t					difference_type;
			typedef size_t							size_type;

			//Constructor
			explicit vector(const allocator_type& alloc = allocator_type()) : _size(0), _cap(0), _alloc(alloc), _arr(NULL)  {
				std::cout <<"alloc Constructor Test Called"<< std::endl;
			}
			explicit vector(size_type n, const value_type& val = value_type(), const allocator_type& alloc = allocator_type()) : _size(n), _alloc(alloc), _cap(n), _arr(NULL) {
				std::cout <<"NNNN Constructor Test Called"<< std::endl;
				this->_arr = this->_alloc.allocate(n);
				for (size_type i = 0; i < this->_size; i++) {
					this->_alloc.construct(this->_arr + i, val);
				}
			}
			// template <class InputIterator>

			// 		vector (InputIterator first, InputIterator last, const allocator_type& alloc = allocator_type());
			vector (const vector& x);
			//Destructor
			~vector(void) {
				if (this->_cap == 0)
					return ;
				this->clear();
				this->_alloc.deallocate(this->_arr, this->_cap);
			}//DELETTEEEEERERRETEE

			//assignement operator
			vector&		operator=(const vector & rhs);

			// Iterator's Methodes
			iterator				begin() {
				return iterator(this->_arr);
			}
			// const_iterator			begin() const;
			iterator				end() {
				return iterator(this->_arr + this->_size);
			};
			// const_iterator			end() const;
			// reverse_iterator 		rbegin();
			// const_reverse_iterator	rbegin() const;
			// reverse_iterator		rend();
			// const_reverse_iterator	rend() const;

			//capacity
			size_type		size() const { return this->_size; }
			size_type		max_size() const  {
				if (sizeof(value_type) == 1)
					return std::numeric_limits<difference_type>::max();
				else
					return std::numeric_limits<difference_type>::max() / (sizeof(value_type) / 2);
				// return this->_alloc.max_size();
			}
			void			resize(size_type n, value_type val = value_type()) {
				if (this->_size == 0 && this->_cap == 0) {
					this->_size = n;
					this->_cap = n;
					this->_arr = this->_alloc.allocate(n);
					for (size_type i = 0; i < this->_size; i++) {
						this->_alloc.construct(this->_arr + i, val);
					}
					return ;
				}
				size_type old_size = this->_size;
				if (n == this->_size)
					return ;
				if (n < this->_size) {
					for (size_type i = n; i < this->_size; i++) {
						this->_alloc.destroy(this->_arr + i);//destroy all elem from n to size;
						// this->_alloc.construct(this->_arr + i, val);
					}
					this->_size = n;///
					return ;	
				}
				if (n > this->_size) {
					if (n <= this->_cap) {
						this->_size = n;
						for (size_type i = 0; i < this->_cap; i++) {
							if (i >= old_size && i < this->_size) {/////
								this->_alloc.destroy(this->_arr + i);//
								this->_alloc.construct(this->_arr + i, val);//ecrase???
							}
						}
					}
					else {
						this->_size = n;
						if (n > this->_cap * 2)
							this->reserve(n);
						else
							this->reserve(this->_cap *= 2);//
						for (size_type i = 0; i < this->_cap; i++) {
							if (i >= old_size && i < this->_size) {//i >= old_size && i < this->_size
								this->_alloc.destroy(this->_arr + i);//
								this->_alloc.construct(this->_arr + i, val);//ecrase???
							}
						}
					}
				}
			}
			size_type		capacity() const { return this->_cap; }
			bool			empty() const { return (this->_size == 0);}
			void			reserve(size_type n) {//can throw bad_alloc
				if (n > this->max_size())
				throw std::length_error("vector::_M_fill_insert");
				if (n < this->_cap)//=
					return ;
				size_type old_cap = this->_cap;
				pointer tmp = this->_arr;
				this->_arr = this->_alloc.allocate(n);
				this->_cap = n;
				for (int i = 0; i < this->_cap; i++) {
					if (i < this->_size)
						this->_alloc.construct(this->_arr + i, *(tmp + i));//assigne an object 
					this->_alloc.destroy(tmp + i);
				}
				this->_alloc.deallocate(tmp, old_cap);
			}
			//element access
				//operator []
			reference		operator[](size_type n) { 
				return *(this->_arr + n);
			}//check n 
			const_reference	operator[](size_type n) const {
				return *(this->_arr + n);
			}
			// 	//  AT
			reference		at(size_type n) {
				if (n >= this->_size || n < 0) {
					throw std::out_of_range("vector::_M_range_check");
				}
				return *(this->_arr + n);
			}
			const_reference	at(size_type n) const {
				if (n >= this->_size || n < 0) {
					throw std::out_of_range("vector::_M_range_check");
				}
				return *(this->_arr + n);
			}
			// 	//Front
			reference		front() {
				return (*this->_arr);
			}
			const_reference	front() const {
				return (*this->_arr);
			}
			// 	//Back
			reference		back() {
				return *(this->_arr + this->_size - 1);
			}
			const_reference	back() const {
				return *(this->_arr + this->_size - 1);
			}
			//Modifiers:
				//assign
			template <class InputIterator>
			void			assign(InputIterator first, InputIterator last) {
				difference_type diff = last - first;
				if (diff < 0)
					throw std::length_error("vector");
				// std::cout <<"distance betweenn first and last n = "<<diff<< std::endl;
				if (diff > this->_cap)
					this->reserve(diff);
				for (unsigned int i = 0; i < this->_size; i++)
					this->_alloc.destroy(this->_arr + i);
				size_type i = 0;
				while (first != last) {
					this->_alloc.construct(this->_arr + i, *first);
					++first;
					++i;
				}
				this->_size = diff;
			}
			void			assign(size_type n, const value_type& val) {
				if (n > this->_cap)
					this->reserve(n);
				for (unsigned int i = 0; i < this->_size; i++)
					this->_alloc.destroy(this->_arr + i);
				for (unsigned int i = 0; i < n; i++)
					this->_alloc.construct(this->_arr + i, val);
				this->_size = n;
			}
			// 	//Push_Back
			void			push_back(const value_type& val) {
				if (this->_cap == 0) {
					this->_arr = this->_alloc.allocate(1);
					++this->_cap;
				}
				else if (this->_size == this->_cap) {
					this->reserve(this->_cap *= 2);
				}
				this->_alloc.construct(this->_arr + this->_size, val);
				++this->_size;
			}
				//Pop_Back
			void			pop_back() {
				if (this->_size == 0)
					return ;
				this->_alloc.destroy(this->_arr + this->_size - 1);
				// this->_alloc.construct(this->_arr + this->_size - 1, value_type());
				--this->_size;
			}
			// 	//insert
			iterator		insert(iterator position, const value_type& val) {
				// if (this->_size + 1 <= this->_cap) {
				// }
				iterator oldEnd = this->end();
				iterator oldBegin = this->begin();
				difference_type dis = oldEnd - oldBegin;
				difference_type fEnd = position - oldEnd;
				difference_type disFEnd = oldEnd - position;
				difference_type fbegin = position - oldBegin;
				if (this->_size + 1 > this->_cap) {
					this->reserve(this->_cap * 2);
				}
				if (position >= oldEnd) {
					this->_alloc.destroy(this->_arr + this->_size + fEnd);
					this->_alloc.construct(this->_arr + this->_size + fEnd, val);
					this->_size += fEnd + 1;
					return iterator(this->_arr + this->_size - 1);
				}
				else if (position < oldBegin){
					memmove(this->_arr, this->_arr - 1, (this->_size + 1) * sizeof(value_type));
					this->_size++;
					return position;//
				}
				else {
					memmove(this->_arr + fbegin + 1, this->_arr + fbegin, (this->_size - fbegin) * sizeof(value_type));
					this->_alloc.construct(this->_arr + fbegin, val);
					this->_size++;
					return iterator(this->_arr + fbegin);
				}
				return position;
			}
			// void			insert(iterator position, size_type n, const value_type& val);
			// template <class InputIterator>
    		// void			insert(iterator position, InputIterator first, InputIterator last);
			// 	//Erase
			iterator		erase(iterator position) {
				// difference_type size = position - this->begin();
				// std::cout <<"size of position = "<< size<<std::endl;
				iterator tmp = position;
				if (position >= this->end()/*|| size >= this->_size*/)//
					return this->end();//segfault
				if (position < this->begin())
					tmp = this->begin();
				// this->_alloc.destroy(this->_arr + size);
				iterator itcp = tmp + 1;
				if (itcp == this->end()) {
					this->_size--;
					this->_alloc.destroy(tmp.base());
					return position;
				}
				else {
					this->_alloc.destroy(tmp.base());
					while (itcp != this->end()) {
						this->_alloc.construct(tmp.base(), *itcp);
						this->_alloc.destroy(itcp.base());
						++itcp;
						++tmp;
					}
				}
				--this->_size;
				return position;
			}
			iterator 		erase(iterator first, iterator last) {
				// difference_type diff = last - first;
				int i = 0;
				while (first != last) {
					this->_alloc.destroy(this->_arr + (first - this->begin()));
					this->_alloc.construct(this->_arr + (first - this->begin()), *(this->_arr + (last - this->begin() + i)));
					++i;
					++first;
					--this->_size;
				}
				///add boucle
				
				return first;
			}
			// 	//Swap
			// void 			swap(vector& x);
			// 	//Clear
			void			clear() {
				for (size_type i = 0; i < this->_size; i++) {
					this->_alloc.destroy(this->_arr + i);
				}
				this->_size = 0;
			}
			// 	//Get_Allocator
			allocator_type	get_allocator() const {
				return this->_alloc;
			}
		private:
			pointer			_arr;
			size_type		_size;
			size_type		_cap;
			allocator_type	_alloc;//bach an alloci wach b default Alloc ola li dakhel mn l constructeur
	};
	//Non-Member Function Overloads
		//Relational Operators
	template <class T, class Alloc>
	bool operator== (const vector<T,Alloc>& lhs, const vector<T,Alloc>& rhs);
	template <class T, class Alloc>
	bool operator!= (const vector<T,Alloc>& lhs, const vector<T,Alloc>& rhs);
	template <class T, class Alloc>
	bool operator<  (const vector<T,Alloc>& lhs, const vector<T,Alloc>& rhs);
	template <class T, class Alloc>
	bool operator<= (const vector<T,Alloc>& lhs, const vector<T,Alloc>& rhs);
	template <class T, class Alloc>
	bool operator>  (const vector<T,Alloc>& lhs, const vector<T,Alloc>& rhs);
	template <class T, class Alloc>
	bool operator>= (const vector<T,Alloc>& lhs, const vector<T,Alloc>& rhs);
		//Swap
	template <class T, class Alloc>
	void			swap(vector<T,Alloc>& x, vector<T,Alloc>& y);
} // namespace ft


// int int() -> 0
// string ""

#endif