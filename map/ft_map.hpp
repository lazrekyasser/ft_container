#ifndef FT_MAP_HPP
#define FT_MAP_HPP

#include <iostream>
#include "ft_pair.hpp"
#include <vector>
// #include "../vector/ft_iterator.hpp"

///NOTE'
//!!!!!If two or more nodes bvecame inBalance in one insertion we should balance the first(closest) one to the elementy inserted
namespace ft {
	//Node
	template <class T>
	struct Node {
		public:
		T			*data;//allocate with _alloc.construct(data, pairObj);
		struct Node	*right;
		struct Node	*left;
		struct Node	*parent;		
	};
	//Map
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
			typedef ft::pair<const Key, T>      value_type;//const Key wa9ila
			typedef Compare                     key_compare;
			//nested class of value_compare
			class value_compare : public std::binary_function<value_type, value_type, bool> {//input pair , pir output bool with compaing with Compare (so comp two keys)
				public://protected
					Compare		comp;//for compairing keys
					value_compare(Compare c) : comp(c) {}
				public:
					bool operator () (const value_type & x, const value_type & y) const {
						return comp(x.first, y.first);
					}
			};
			typedef typename Alloc::template rebind<Node<value_type> >::other node_allocator;//other === allocator_type<Node<value_type>>
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
			  	const allocator_type& alloc = allocator_type()) : _alloc(alloc), _keyComp(comp) {
					this->_comp =  new value_compare(comp);////////////
					this->_size = 0;
					this->_root = NULL;//init Node
			}
			//////////
			//tool's
			void deleteNode(Node<value_type> *node) {
				if (node == NULL)
					return ;
				deleteNode(node->left);
				deleteNode(node->right);
				this->_alloc.destroy(node->data);
				this->_alloc.deallocate(node->data, 1);
				this->_nAlloc.deallocate(node, 1);
				--this->_size;
			}
			Node<value_type> *newNode(const value_type & val) {
				Node<value_type> *node = NULL;
				node = this->_nAlloc.allocate(1);
				node->data = this->_alloc.allocate(1);
				this->_alloc.construct(node->data, val);
				node->right = NULL;
				node->left = NULL;
				node->parent = NULL;
				return node;
			}
			void insert_(Node<value_type> *root, const value_type& val) {
				if (this->_root == NULL) {
					this->_root = newNode(val);
					this->_size++;
					return ;
				}
				this->_pathInsert.clear();
				while (root != NULL) {
					if (/**(root->data) > val*/(*this->_comp)(val, *(root->data))) {
						if (root->left == NULL) {
							root->left = newNode(val);
							root->left->parent = root;
							this->_pathInsert.push_back('L');
							this->_size++;
							return ;
						}
						this->_pathInsert.push_back('L');
						root = root->left;
						continue ;
					}
					if (/**(root->data) < val*/(*this->_comp)(*(root->data), val)) {
						if (root->right == NULL) {
							root->right = newNode(val);
							root->right->parent = root;
							this->_pathInsert.push_back('R');
							this->_size++;
							return ;
						}
						this->_pathInsert.push_back('R');
						root = root->right;
						continue ;
					}
					this->_pathInsert.clear();
					return ;
				}
				//recusive way
				// if (*(root->data) > val) {//use this->_comp for comparing  
				// 	if (root->left == NULL) {
				// 		root->left = newNode(val);
				// 		root->left->parent = root;
				// 		this->_pathInsert.push_back('L');
				// 		return ;
				// 	}
				// 	this->_pathInsert.push_back('L');
				// 	return insert_(root->left, val);
				// }
				// if (*(root->data) < val) {
				// 	if (root->right == NULL) {
				// 		root->right = newNode(val);
				// 		root->right->parent = root;
				// 		this->_pathInsert.push_back('R');
				// 		return ;
				// 	}
				// 	this->_pathInsert.push_back('R');
				// 	return insert_(root->right, val);
				// }
			}
			void r_rotation(Node<value_type> *node) {
				Node<value_type> *a = node;
				Node<value_type> *p = a->parent;
				Node<value_type> *b = a->left;
				Node<value_type> *d = b->right;
				
				if (p != NULL) {
					if (p->left == a)
						p->left = b;
					else if (p->right == a)
						p->right = b;
					b->parent = p;
				}
				else {
					this->_root = b;
					b->parent = NULL;
				}
				a->left = d;
				a->parent = b;
				b->right = a;
				if (d)
					d->parent = a;
			}
			Node<value_type> *getRoot(void) {
				return this->_root;
			}
			void accedeTo(Node<value_type> *root, int i) {
				int j = 0;
				while (i > 0) {
					if (this->_pathInsert[j] == 'R') {
						root = root->right;
					}
					else if (this->_pathInsert[j] == 'L') {
						root = root->left;
					}
					++j;
					--i;
				}
				//call parent while is diff to NULL////!!!!!!!!!!!!!!
				std::cout <<"acced = "<<root->data->first<< " | ";
			}
			void calcule_FactB(Node<value_type> *root) {
				///root balance here if no balance
				for (size_t i = this->_pathInsert.size() - 1; i > 0; --i) {//from pathSize to parent'ssss
					accedeTo(root, i);//!!!!!!ONe Timee
				}
				std::cout << std::endl;
			}
			void print(Node<value_type> *root)  {
				if (root == NULL)
					return ;
				std::cout <<root->data->first<<" : ↑ his parent => ";
				if (root->parent != nullptr)
					std::cout << root->parent->data->first << std::endl;
				else
					std::cout <<"(null)"<< std::endl;
				print(root->left);
				print(root->right);
			}
			void affichPath(void) {
				for (int i = 0; i < this->_pathInsert.size();i++)
					std::cout <<this->_pathInsert[i]<<"->";
				std::cout <<"\n";
			}
			Node<value_type> *getRootT(void) {return this->_root; }
			/////////////////////////////////
			template <class InputIterator>
			map (InputIterator first, InputIterator last,
							const key_compare& comp = key_compare(),
							const allocator_type& alloc = allocator_type());	
			map (const map& x);
			//Destructor
			~map() {delete this->_comp;}//heyed new delete
			//oprator =
			map& operator= (const map& x);
			//Iterator
			// iterator begin();
			// const_iterator begin() const;
			// iterator end();
			// const_iterator end() const;
			// reverse_iterator rbegin();
			// const_reverse_iterator rbegin() const;
			// reverse_iterator rend();
			// const_reverse_iterator rend() const;
			//capacity
			bool empty() const;
			size_type size() const {return this->_size;}
			size_type max_size() const;
			//Element access
			mapped_type& operator[] (const key_type& k);
			//Modifiers
				//Insert
			/*pair<iterator,bool>*/void insert (const value_type& val) {
				insert_(this->_root, val);
				if (this->_size >= 10 && this->_pathInsert.size() > 1) {//propapiliter de prob when path>=2
					//balancin
					calcule_FactB(this->_root);
				}
			}
			// iterator insert (iterator position, const value_type& val);	
			// template <class InputIterator>
			// void insert (InputIterator first, InputIterator last);
			// 	//Erase
			// void erase (iterator position);
			// size_type erase (const   & k);
			// void erase (iterator first, iterator last);
			// 	//Swap
			// void swap (map& x);
			// 	//clear
			void clear() {
				if (this->_size == 0 || this->_root == NULL)
					return ;
				this->deleteNode(this->_root);
			}
			// //Observers
			// key_compare key_comp() const;
			// value_compare value_comp() const;
			// //Operation
			// 	//find
			// iterator find (const key_type& k);
			// const_iterator find (const key_type& k) const;
			// 	//count
			// size_type count (const key_type& k) const;
			// 	//lower_bound
			// iterator lower_bound (const key_type& k);
			// const_iterator lower_bound (const key_type& k) const;
			// 	//upper_bound
			// iterator upper_bound (const key_type& k);
			// const_iterator upper_bound (const key_type& k) const;
			// 	//equal_range
			// pair<const_iterator,const_iterator> equal_range (const key_type& k) const;
			// pair<iterator,iterator>             equal_range (const key_type& k);
			//get_allocator
			allocator_type get_allocator() const;
		private:
			Alloc       		_alloc;//for allocating value_type's
			Compare     		_keyComp;//use functor to compare two key of pair's
			size_type			_size;
			node_allocator		_nAlloc;//call def const of allocator<Node<value_type> >()
			Node<value_type>	*_root;
			std::vector<char>	_pathInsert;
			value_compare		*_comp;
	};
}

#endif