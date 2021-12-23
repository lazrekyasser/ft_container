#ifndef FT_MAP_HPP
#define FT_MAP_HPP

#include <iostream>
#include "ft_pair.hpp"
// #include "../vector/ft_iterator.hpp"

namespace ft {
	///pair
	template<
		class Key, //map::key_type
		class T,   //map::mapped_type
		class Compare = std::less<Key>, //map::key::compare
		class Alloc = std::allocator<ft::pair<const Key, T> > //map::allocator_type
	>
	class map {
		public:
			typedef Key                         key_type;
			typedef T                           mapped_type;
			typedef ft::pair<Key, T>            value_type;
			typedef Compare                     key_compare;
			//nested class of value_compare
			class value_compare : public std::binary_function<value_type, value_type, bool> {//input pair , pir output bool with compaing with Compare (so comp two keys)
				protected:
					Compare		comp;//for compairing keys
					value_compare(Compare c) : comp(c) {}
				public:
					bool operator () (const value_type & x, const value_type & y) const {
						return comp(x.first, y.first);
					}
			};
			typedef Alloc                                            allocator_type;
			typedef typename allocator_type::reference               reference;
			typedef typename allocator_type::const_reference         const_reference;
			typedef typename allocator_type::pointer                 pointer;
			typedef typename allocator_type::const_pointer           const_pointer;
			// typedef T           iterator;
			// typedef T           const_iterator;
			// typedef T           reverse_iterator;
			// typedef T           const_reverse_iterator;
			typedef std::ptrdiff_t                          difference_type;
			typedef size_t                                  size_type;

			//Constructor
			explicit map (const key_compare& comp = key_compare(),
              				const allocator_type& alloc = allocator_type());	
			template <class InputIterator>
			map (InputIterator first, InputIterator last,
							const key_compare& comp = key_compare(),
							const allocator_type& alloc = allocator_type());	
			map (const map& x);
			//Destructor
			~map();
			//oprator =
			map& operator= (const map& x);
			//Iterator
			iterator begin();
			const_iterator begin() const;
			iterator end();
			const_iterator end() const;
			reverse_iterator rbegin();
			const_reverse_iterator rbegin() const;
			reverse_iterator rend();
			const_reverse_iterator rend() const;
			//capacity
			bool empty() const;
			size_type size() const;
			size_type max_size() const;
			//Element access
			mapped_type& operator[] (const key_type& k);
			//Modifiers
				//Insert
			pair<iterator,bool> insert (const value_type& val);	
			iterator insert (iterator position, const value_type& val);	
			template <class InputIterator>
			void insert (InputIterator first, InputIterator last);
				//Erase
			void erase (iterator position);
			size_type erase (const key_type& k);
			void erase (iterator first, iterator last);
				//Swap
			void swap (map& x);
				//clear
			void clear();
			//Observers
			key_compare key_comp() const;
			value_compare value_comp() const;
			//Operation
				//find
			iterator find (const key_type& k);
			const_iterator find (const key_type& k) const;
				//count
			size_type count (const key_type& k) const;
				//lower_bound
			iterator lower_bound (const key_type& k);
			const_iterator lower_bound (const key_type& k) const;
				//upper_bound
			iterator upper_bound (const key_type& k);
			const_iterator upper_bound (const key_type& k) const;
				//equal_range
			pair<const_iterator,const_iterator> equal_range (const key_type& k) const;
			pair<iterator,iterator>             equal_range (const key_type& k);
			//get_allocator
			allocator_type get_allocator() const;
		private:
			// Alloc       _alloc;
			// Compare     _objComp;//use functor to compare two objects
	};
}

#endif