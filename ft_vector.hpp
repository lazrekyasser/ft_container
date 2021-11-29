#ifndef FT_VECTOR_HPP
#define FT_VECTOR_HPP

#include <memory>
#include <iostream>

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
			// typedef   my_iterator<T>  iterator
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
			~vector(void);
			//assignement operator
			vector&		operator=(const vector & rhs);
			// Iterator's Methodes
			iterator				begin();
			const_iterator			begin() const;
			iterator				end();
			const_iterator			end() const;
			reverse_iterator 		rbegin();
			const_reverse_iterator	rbegin() const;
			reverse_iterator		rend();
			const_reverse_iterator	rend() const;
			//capacity
			size_type		size() const { return this->_size; }
			size_type		max_size() const  {return this->_alloc.max_size(); }
			void			resize(size_type n, value_type val = value_type());
			size_type		capacity() const { return this->_cap; }
			bool			empty() const { return (this->_size == 0);}
			void			reserve(size_type n) {//can throw bad_alloc
				if (n > this->max_size())
					throw std::length_error("vector::_M_fill_insert");
				
			}
			//element access
				//operator []
			reference		operator[](size_type n);
			const_reference	operator[](size_type n) const;
				//  AT
			reference		at(size_type n);
			const_reference	at(size_type n) const;
				//Front
			reference		front();
			const_reference	front() const;
				//Back
			reference		back();
			const_reference	back() const;
			//Modifiers:
				//assign
			template <class InputIterator>
			void			assign(InputIterator first, InputIterator last);
			void			assign(size_type n, const value_type& val);
				//Push_Back
			void			push_back(const value_type& val) {
				// if (this->size == 0) {
				// 	this->_arr = this->_alloc.allocate(1);
				// 	++this->_cap;
				// }
				// else if (this->_size == this->_cap) {
				// 	this->_cap *= 2;
				// 	this->_arr = this->allocate(this->_cap);
				// }
				// this->_alloc.construct(this->_arr + this->_size, val);
				// ++this->_size;
			}
				//Pop_Back
			void			pop_back();
				//insert
			iterator		insert(iterator position, const value_type& val);
			void			insert(iterator position, size_type n, const value_type& val);
			template <class InputIterator>
    		void			insert(iterator position, InputIterator first, InputIterator last);
				//Erase
			iterator		erase(iterator position);
			iterator 		erase(iterator first, iterator last);
				//Swap
			void 			swap(vector& x);
				//Clear
			void			clear();
				//Get_Allocator
			allocator_type	get_allocator() const;
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