#ifndef FT_VECTOR_HPP
#define FT_VECTOR_HPP

#include <memory>
#include <iostream>
#include <iterator>
#include <algorithm>
#include "ft_iterator.hpp"
#include "equal.hpp"
#include "lexicographical_compare.hpp"
#include "ft_enable_if.hpp"




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
			typedef ft::my_iterator<T>  				iterator;
			typedef ft::my_iterator<const T>			const_iterator;
			typedef ft::reverse_iterator<iterator>		reverse_iterator;
			typedef ft::reverse_iterator<const_iterator>	const_reverse_iterator;
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
			template <class InputIterator>
			vector (InputIterator first, InputIterator last, const allocator_type& alloc = allocator_type(), typename ft::enable_if<!is_integral<InputIterator>::value, InputIterator>::type a = InputIterator()) {
				std::cout << "Constructor of InputIterator\n";
				if (last < first)
					return ;///abort throw exception
				this->_alloc = alloc;
				difference_type dis = last - first;
				this->_size = dis;
				this->_cap = dis;
				this->_arr = this->_alloc.allocate(dis);
				for (size_type i = 0; i < this->_size; i++) {
					this->_alloc.construct(this->_arr + i, *first);
					++first;
				}
			}
			vector (const vector& x) : _size(x._size), _cap(x._size), _arr(NULL) {//catch assignament exception for the EXCEPTION SAFETY FOR GENERIC CONTAINERS
				// *this = x;
				try {
					this->_arr = this->_alloc.allocate(this->_size);
					for (size_type i = 0; i < this->_size; i++) {
						this->_alloc.construct(this->_arr + i, *(x._arr + i));
					}
				}
				catch(const std::exception& e)
				{
					std::cerr << e.what() << '\n';
					if (this->_cap == 0)
						return ;
					this->clear();
					this->_alloc.deallocate(this->_arr, this->_cap);
				}
				
			}
			//Destructor
			~vector(void) {
				if (this->_cap == 0)
					return ;
				this->clear();
				this->_alloc.deallocate(this->_arr, this->_cap);
			}//DELETTEEEEERERRETEE

			//assignement operator
			vector&		operator=(const vector & rhs) {
				if (this != &rhs) {
					this->_cap = (rhs._size < this->_cap)? this->_cap: rhs._size;
					pointer tmp = this->_alloc.allocate(this->_cap);////
					for (size_type i = 0; i < rhs._size; i++) {
						this->_alloc.construct(tmp + i, rhs._arr[i]);
					}
					this->~vector();
					this->_size = rhs._size;
					this->_arr = tmp;
				}
				return *this;
			}

			// Iterator's Methodes
			iterator				begin() {
				return iterator(this->_arr);
			}
			// ft::enable_if<std::<typename const_iterator::>>
			const_iterator			begin() const {
				return const_iterator(this->_arr);
			}
			iterator				end() {
				return iterator(this->_arr + this->_size);
			};
			const_iterator			end() const {
				return const_iterator(this->_arr + this->_size);
			}
			reverse_iterator 		rbegin() {
				return reverse_iterator(this->_arr + this->_size);
			}
			const_reverse_iterator	rbegin() const {//
				return const_reverse_iterator(this->_arr + this->_size);
			}
			reverse_iterator		rend() {
				return reverse_iterator(this->_arr);
			}
			const_reverse_iterator	rend() const {//
				return const_reverse_iterator(this->_arr);
			}

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
				/*possiblr cas
				if (position > size && position < cap)
					alloc.construct(arr + position, val);
				*/
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
			void			insert(iterator position, size_type n, const value_type& val) {
				iterator 		oldEnd = this->end();
				iterator 		oldBegin = this->begin();
				difference_type	pos = position - oldBegin;
				difference_type len = this->_size - pos;
				if (this->_size + n > this->_cap)
					this->reserve(this->_cap * 2 + (((n - this->_cap) < 0)? 0: (n - this->_cap)));
				memmove(this->_arr + pos + n, this->_arr + pos, (len) * sizeof(value_type));
				for (int i = 0; i < n; i++) {
					this->_alloc.construct(this->_arr + pos + i, val);
					this->_size++;
				}
			}
			// template <class InputIterator>
    		// typename ft::enable_if<!ft::is_integral<InputIterator>::value, void>::type	insert(iterator position, InputIterator first, InputIterator last) {
			// 	std::cout <<"insert of Inpust Iterator >>>>>"<< std::endl;
			// }
			template <class InputIterator>
    		void	insert(iterator position, InputIterator first, InputIterator last, typename ft::enable_if<!is_integral<InputIterator>::value, InputIterator>::type a = InputIterator()) {
				std::cout <<"insert of Inpust Iterator >>>>>"<< std::endl;
				if (last < first)
					return ;
				iterator 		oldEnd = this->end();
				iterator 		oldBegin = this->begin();
				difference_type	pos = position - oldBegin;
				difference_type len = this->_size - pos;
				difference_type n = last - first;
				if (this->_size + n > this->_cap)///test it in insert of n element
					this->reserve(this->_cap * 2 + (((n - this->_cap) < 0)? 0: (n - this->_cap)));/// + sifff 
				memmove(this->_arr + pos + n, this->_arr + pos, (len) * sizeof(value_type));
				for (int i = 0; i < n; i++) {
					this->_alloc.construct(this->_arr + pos + i, *first);
					this->_size++;
					++first;///copie of first
				}
			}
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
				iterator oldEnd = this->end();
				int i = 0;
				int c = 0;
				while (first != last) {
					this->_alloc.destroy(this->_arr + (first - this->begin()));
					this->_alloc.construct(this->_arr + (first - this->begin()), *(this->_arr + (last - this->begin() + i)));
					++i;
					++first;
					--this->_size;
					++c;
				}
				///add boucle
				iterator ret(first);
				while (ret != oldEnd) {////////////////////prob
					this->_alloc.destroy(this->_arr + (ret - this->begin()));
					this->_alloc.construct(this->_arr + (ret - this->begin()), *(this->_arr + (last - this->begin() + i)));
					++i;
					++ret;
				}
				return first - c;//prob ret
			}
			// 	//Swap
			void 			swap(vector& x) {
				std::swap(x._cap, this->_cap);
				vector<T> tmp = x;
				x = *this;
				*this = tmp;
				// x._arr.swap(this->_arr);
				// std::unique_ptr<T[]>(x._arr).swap(std::unique_ptr<T[]>(this->_arr));
			}
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
	bool operator== (const vector<T,Alloc>& lhs, const vector<T,Alloc>& rhs) {
		if (lhs.size() != rhs.size())
			return false;
		return equal(lhs.begin(), lhs.end(), rhs.begin());
	}
	template <class T, class Alloc>
	bool operator!= (const vector<T,Alloc>& lhs, const vector<T,Alloc>& rhs) {
		return !(lhs == rhs);
	}
	template <class T, class Alloc>
	bool operator<  (const vector<T,Alloc>& lhs, const vector<T,Alloc>& rhs) {
		return lexicographical_compare(lhs.begin(), lhs.end(),rhs.begin(), rhs.end());
	}
	template <class T, class Alloc>
	bool operator<= (const vector<T,Alloc>& lhs, const vector<T,Alloc>& rhs) {
		return !(rhs < lhs);
	}
	template <class T, class Alloc>
	bool operator>  (const vector<T,Alloc>& lhs, const vector<T,Alloc>& rhs) {
		return (rhs < lhs);
	}
	template <class T, class Alloc>
	bool operator>= (const vector<T,Alloc>& lhs, const vector<T,Alloc>& rhs) {
		return !(lhs < rhs);
	}
		//Swap
	template <class T, class Alloc>
	void			swap(vector<T,Alloc>& x, vector<T,Alloc>& y){
		x.swap(y);
	}
} // namespace ft


// int int() -> 0
// string ""

#endif