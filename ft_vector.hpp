#ifndef FT_VECTOR_HPP
#define FT_VECTOR_HPP

#include <memory>
#include <iostream>
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
			explicit vector(size_type n, const value_type& val = value_type(), const allocator_type& alloc = allocator_type());
			template <class InputIterator>
					vector (InputIterator first, InputIterator last, const allocator_type& alloc = allocator_type());
			vector (const vector& x);
			//Destructor
			~vector(void) {
				delete [] this->_arr;//alloc.destruct
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
			size_type		max_size() const  {return this->_alloc.max_size(); }
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
					this->_size = n;
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
						/////cas de size and cap == 0!!!!
						this->_size = n;
						// this->_cap = n;
						this->_cap *= 2;
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
			// reference		at(size_type n);
			// const_reference	at(size_type n) const;
			// 	//Front
			// reference		front();
			// const_reference	front() const;
			// 	//Back
			// reference		back();
			// const_reference	back() const;
			//Modifiers:
				//assign
			// template <class InputIterator>
			// void			assign(InputIterator first, InputIterator last);
			// void			assign(size_type n, const value_type& val);
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
			// iterator		insert(iterator position, const value_type& val);
			// void			insert(iterator position, size_type n, const value_type& val);
			// template <class InputIterator>
    		// void			insert(iterator position, InputIterator first, InputIterator last);
			// 	//Erase
			// iterator		erase(iterator position);
			// iterator 		erase(iterator first, iterator last);
			// 	//Swap
			// void 			swap(vector& x);
			// 	//Clear
			// void			clear();
			// 	//Get_Allocator
			// allocator_type	get_allocator() const;
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