#ifndef FT_MAP_HPP
#define FT_MAP_HPP

#include <iostream>
#include "ft_pair.hpp"
#include <vector>
#include "ft_map_iterator.hpp"
// #include "../vector/ft_iterator.hpp"

///NOTE'
//!!!!!If two or more nodes bvecame inBalance in one insertion we should balance the first(closest) one to the elementy inserted
namespace ft {
	
	//Node
	template <class T>
	struct Node {
		T			*data;//allocate with _alloc.construct(data, pairObj);
		struct Node	*right;
		struct Node	*left;
		struct Node	*parent;

		Node* minimum() {
			Node* tmp = this;
			while (tmp->left) {
				tmp = tmp->left;
			}
			return tmp;
		}
		Node* maximum() {
			Node* tmp = this;
			while (tmp->right) {
				tmp = tmp->right;
			}
			return tmp;
		}
		Node *maxTree() {
			Node *root = this;
			while (root->parent)
				root = root->parent;
			return  root->maximum();
		}
		Node *minTree() {
			Node *root = this;
			while (root->parent)
				root = root->parent;
			return  root->minimum();
		}
		Node* predecessor() {
			Node *root = this;
			if (root->left) {
				return root->left->maximum();
			}
			else {
				Node *pre = nullptr;
				if (root->parent && root->parent->left == root) {
					Node *p = root->parent;
					while (p->parent && p->parent->left == p) {
						p = p->parent;
					}
					if (p->parent && p->parent->right == p) {
						pre = p->parent;
					}
					return pre;
				}
				else if (root->parent && root->parent->right == root) {
					return root->parent;
				}
				return pre;
			}
			//return succ or the root ???? map.rend()
		}
		Node* successor() {
			Node *root = this;
			if (root->right) {
				return root->right->minimum();
			}
			else {
				Node *succ = nullptr;
				if (root->parent && root->parent->right == root) {
					Node *p = root->parent;
					while (p->parent && p->parent->right == p) {
						p = p->parent;
					}
					if (p->parent && p->parent->left == p) {
						succ = p->parent;
					}
					return succ;
				}
				else if (root->parent && root->parent->left == root) {
					return root->parent;
				}
				return succ;
			}
			//return succ or the root ???? map.end()
		}
		typedef T			value_type;
	};
	//NULL NODE Globale variable in FT namespace
	// ft::Node<ft::map<>:: > *Nill;
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
			typedef ft::map_iterator<Node<value_type> >				iterator;
			typedef ft::map_iterator<const Node<value_type> >       const_iterator;
			typedef ft::map_reverse_iterator<Node<value_type> >       reverse_iterator;
			typedef ft::map_reverse_iterator<const Node<value_type> >       const_reverse_iterator;
			typedef std::ptrdiff_t                          difference_type;
			typedef size_t                                  size_type;

			//////////
			//tool's
			void printTreeHelper(Node<value_type> *root ,int space)
			{
				int i;
				if(root != NULL)
				{
					space = space + 10;
					printTreeHelper(root->right, space);
					std::cout << std::endl;
					for ( i = 10; i < space; i++){
						std::cout << " ";
					}
					std::cout << root->data->first  << std::endl;
					printTreeHelper(root->left, space);
				}
			}
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
			void deleteOneNode(Node<value_type> *node) {
				if (node == NULL)
					return ;
				node->right = NULL;
				node->left = NULL;
				node->parent = NULL;
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
			ft::pair<iterator, bool> insert_(Node<value_type> *root, const value_type& val) {
				if (this->_root == NULL) {
					this->_root = newNode(val);
					this->_size++;
					iterator it(this->_root);
					return ft::make_pair<iterator,bool>(it, true);
				}
				this->_pathInsert.clear();
				iterator it1(root);
				while (root != NULL) {
					if (/**(root->data) > val*/(*this->_comp)(val, *(root->data))) {
						if (root->left == NULL) {
							root->left = newNode(val);
							root->left->parent = root;
							this->_pathInsert.push_back('L');
							this->_size++;
							iterator it(root->left);
							return ft::make_pair<iterator,bool>(it, true);
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
							iterator it(root->right);
							return ft::make_pair<iterator,bool>(it, true);
						}
						this->_pathInsert.push_back('R');
						root = root->right;
						continue ;
					}
					//cas of key already in
					this->_pathInsert.clear();
					return ft::make_pair<iterator,bool>(it1, false);
				}
				return ft::make_pair<iterator, bool>(it1, false);
			}
			void l_rotation(Node<value_type> *node) {
				Node<value_type> *a = node;
				Node<value_type> *p = a->parent;
				Node<value_type> *b = a->left;	
				// // Node<value_type> *d = b->right;
				std::cout <<"node = "<<node->data->first << "\n";
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
				a->left = b->right;
				a->parent = b;
				if (b->right)
					b->right->parent = a;
				b->right = a;
				// return b;
			}
			void r_rotation(Node<value_type> *node) {
				Node<value_type> *a = node;
				Node<value_type> *p = a->parent;
				Node<value_type> *b = a->right;
				// Node<value_type> *d = b->left;
				std::cout <<"node = "<<node->data->first << "\n";
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
				a->right = b->left;
				a->parent = b;
				if (b->left)
					b->left->parent = a;
				b->left = a;
				// return b;
			}
			Node<value_type> *getRoot(void) {
				return this->_root;
			}
			int max(int a, int b)
			{
				return (a >= b) ? a : b;
			}
			int height(Node<value_type> * node)
			{
				if (node == NULL)
					return 0;
				return 1 + max(height(node->left),
							height(node->right));
			}
			bool is_balanced(Node<value_type> *root) {
				int lh;
				int rh;
			
				if (root == NULL)
					return 1;
				lh = height(root->left);
				rh = height(root->right);
				if (abs(lh - rh) <= 1 && is_balanced(root->left) && is_balanced(root->right))
					return 1;
				return 0;
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
				std::cout << "calcule balance of node "<<root->data->first<< " | his i = "<<j;
				if (is_balanced(root) == false) {
					std::cout <<" ==> we need to balance it ||";
					balance(root, j);
				}
			}
			
			void balance(Node<value_type> *root, int index) {
				if (this->_pathInsert[index] == 'L' && this->_pathInsert[index+1] =='R') {
					std::cout <<"LR \n";
					r_rotation(root->left);
					l_rotation(root);
				}
				else if (this->_pathInsert[index] == 'R' && this->_pathInsert[index+1] =='L') {
					std::cout <<"LR \n";
					l_rotation(root->right);
					r_rotation(root);
				}
				else if (this->_pathInsert[index] == 'L' && this->_pathInsert[index+1] =='L') {
					std::cout <<"LL\n";
					l_rotation(root);
				}
				else if (this->_pathInsert[index] == 'R' && this->_pathInsert[index+1] =='R') {
					std::cout <<"RR\n";
					r_rotation(root);
				}
			}
			void calcule_FactB(Node<value_type> *root) {
				int j = 0;
				///root balance here if no balance
				for (size_t i = this->_pathInsert.size() - 1; i > 0; --i) {//from pathSize to parent'ssss
					accedeTo(root, i);//!!!!!!ONe Timee
					// j = i;
				}
				std::cout << std::endl;
				std::cout << "calcule balance of node "<<root->data->first<< " | his i = "<<j;
				if (is_balanced(root) == false) {
					std::cout <<" ==> we need to balance it ||";
					balance(root, j);
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
			//Constructor
			explicit map (const key_compare& comp = key_compare(),
			  	const allocator_type& alloc = allocator_type()) : _alloc(alloc), _keyComp(comp) {
					this->_comp =  new value_compare(comp);////////////
					this->_size = 0;
					this->_root = NULL;//init Node
					//init the Null Node for the end of the map(allocate in the stack )
					this->_nullEnd.data = this->_alloc.allocate(1);////
					this->_nullEnd.right = nullptr;
					this->_nullEnd.left = nullptr;
					this->_nullEnd.parent = nullptr;
					this->_nullRend.data = this->_alloc.allocate(1);////
					this->_nullRend.right = nullptr;
					this->_nullRend.left = nullptr;
					this->_nullRend.parent = nullptr;
			}
			template <class InputIterator>
			map (InputIterator first, InputIterator last,
							const key_compare& comp = key_compare(),
							const allocator_type& alloc = allocator_type());	
			map (const map& x);
			//Destructor
			~map() {
				delete this->_comp;
				this->_alloc.deallocate(this->_nullEnd.data, 1);
				this->_alloc.deallocate(this->_nullRend.data, 1);
				this->clear();
			}//heyed new delete 
			//operator =
			map& operator= (const map& x);/////////
			//Iterator
			iterator begin() {
				if (this->_root == NULL)
					return iterator();/////////////
				return iterator(this->_root->minimum(), &this->_nullEnd,&this->_nullRend, this->_root);
			}
			const_iterator begin() const {
				if (this->_root == NULL)
					return const_iterator();/////////////
				return const_iterator(this->_root->minimum(), &this->_nullEnd,&this->_nullRend, this->_root);
			}
			iterator end() {
				if (this->_root == NULL)
					return iterator();
				return iterator(&this->_nullEnd, &this->_nullEnd,&this->_nullRend, this->_root);//pass &this->_nullRend
			}
			const_iterator end() const {
				if (this->_root == NULL)
					return const_iterator();
				return const_iterator(&this->_nullEnd, &this->_nullEnd,&this->_nullRend, this->_root);
			}
			reverse_iterator rbegin() {
				if (!this->_root)
					return reverse_iterator();
				return reverse_iterator(this->_root->maximum(),&this->_nullEnd,&this->_nullRend, this->_root);
			}
			const_reverse_iterator rbegin() const {
				if (!this->_root)
					return const_reverse_iterator();
				return const_reverse_iterator(this->_root->maximum(),&this->_nullEnd,&this->_nullRend, this->_root);
			}
			reverse_iterator rend() {
				if (!this->_root)
					return reverse_iterator();
				return reverse_iterator(&_nullRend,&this->_nullEnd,&this->_nullRend, this->_root);
			}
			const_reverse_iterator rend() const {
				if (!this->_root)
					return reverse_iterator();
				return reverse_iterator(&_nullRend,&this->_nullEnd,&this->_nullRend, this->_root);
			}
			//capacity 
			bool empty() const {return this->_size == 0;}
			size_type size() const {return this->_size;}
			size_type max_size() const;//////////////
			//Element access
			mapped_type& operator[] (const key_type& k) {
				iterator e = find(k);
				if (e != end()) {
					return e->second;
				}
				value_type val = ft::make_pair(k, mapped_type());
				ft::pair<iterator, bool> ret = this->insert(val);
				return (ret.first)->second;
			}
			//Modifiers
				//Insert
			ft::pair<iterator,bool> insert (const value_type& val) {
				//cherck if ele is already in=>return pair<iterator to this element, false>  
				ft::pair<iterator, bool> ret = insert_(this->_root, val);//make paire here to return it
				if (this->_size >= 3 && this->_pathInsert.size() > 1) {//propapiliter de prob when path>=2
					//balancin
					calcule_FactB(this->_root);
				}
				return ret;
			}
			iterator insert(iterator position, const value_type& val) {
				Node<value_compare> *node;
				if (!this->_root) {
					std::cout <<"adgshgads\n";
					ft::pair<iterator, bool> ret = this->insert(val);
					return ret.first;
				}
				if (!(*this->_comp)(val, *position) && !(*this->_comp)(*position, val))
					{
						std::cout <<"cas de position == val";
						return position;}
				ft::pair<iterator, bool> ret = this->insert(val);
				return ret.first;
			}
			template <class InputIterator>
			void insert (InputIterator first, InputIterator last) {
				while (first != last) {
					this->insert(*first);
					first++;
				}
			}
			// 	//Erase
			Node<value_type> *tallerChild(Node<value_type> *x) {
				if (height(x->left) > height(x->right))
					return x->left;
				else
					return x->right;
			}
			Node<value_type> *tri_node_restructure(Node<value_type> *x,Node<value_type> *y,Node<value_type> *z) {
				Node<value_type> *a;
				Node<value_type> *b;
				Node<value_type> *c;
				Node<value_type> *T0;
				Node<value_type> *T1;
				Node<value_type> *T2;
				Node<value_type> *T3;
				bool zIsLeftChild = (z == y->left);
				bool yIsLeftChild = (y == x->left);

				if (zIsLeftChild && yIsLeftChild){
					a = z;
					b = y;
					c = x;
					T0 = a->left;
					T1 = a->right;
					T2 = b->right;
					T3 = c->right;
				}
				else if (!zIsLeftChild && yIsLeftChild){
					a = y;
					b = z; 
					c = x;
					T0 = a->left;
					T1 = b->left;
					T2 = b->right;
					T3 = c->right;
				}
				else if (zIsLeftChild && !yIsLeftChild){
					a = x;                     
					b = z;                     
					c = y;                     
					T0 = a->left;               
					T1 = b->left;               
					T2 = b->right;              
					T3 = c->right;
				}
				else{
					a = x;
					b = y;
					c = z;
					T0 = a->left;
					T1 = b->left;
					T2 = c->left;
					T3 = c->right;
				}
				if ( x == this->_root )
				{
					this->_root = b;
					b->parent = NULL;
				}
				else
				{
					Node<value_type> * xParent;

					xParent = x->parent;
					if ( x == xParent->left ){
						b->parent = xParent;
						xParent->left = b;
					}
					else{
						b->parent = xParent;
						xParent->right = b;
					}
				}
				b->left = a;
				a->parent = b;
				b->right = c;
				c->parent = b;

				a->left = T0;
				if ( T0 != NULL ) T0->parent = a;
				a->right = T1;
				if ( T1 != NULL ) T1->parent = a;

				c->left = T2;
				if ( T2 != NULL ) T2->parent= c;
				c->right= T3;
				if ( T3 != NULL ) T3->parent= c;

				return b;
			}
			Node<value_type> *balance_tl(Node<value_type> *root) {
				Node<value_type> *x = root;
				Node<value_type> *y = tallerChild(x);
				Node<value_type> *z = tallerChild(y);

				return tri_node_restructure(x, y, z);
 			}
			void erase (iterator position) {
				if (!this->_root)
					return ;
				Node<value_type> *root = this->_root;
				this->_pathInsert.clear();
				while (root != NULL) {
					if ((*this->_comp)(*position, *(root->data))) {
						if (root->left == NULL) {
							this->_pathInsert.clear();
							return ;
						}
						this->_pathInsert.push_back('L');
						root = root->left;
						continue ;
					}
					else if ((*this->_comp)(*(root->data), *position)) {
						if (root->right == NULL) {
							this->_pathInsert.clear();
							return ;
						}
						this->_pathInsert.push_back('R');
						root = root->right;
						continue ;
					}
					else {
						//cas of key already in
						//delite node
						std::cout <<"deleting node "<<root->data->first<< std::endl;
						if (this->_pathInsert.size() == 0) {
							//deleting root node;
							std::cout <<"root\n";
							if (!this->_root->right && !this->_root->left) {
								this->deleteOneNode(this->_root);
								this->_root = NULL;
							}
							else if (!this->_root->right && this->_root->left) {
								Node<value_type> *l = this->_root->left;
								l->parent = NULL;
								this->deleteOneNode(this->_root);
								this->_root = l;
							}
							else if (this->_root->right && !this->_root->left) {
								Node<value_type> *r = this->_root->right;
								r->parent = NULL;
								this->deleteOneNode(this->_root);
								this->_root = r;
							}
							else {
								Node<value_type> *succ = this->_root->successor();
								if (this->_root->right == succ) {
									succ->left = this->_root->left;
									this->_root->left->parent = succ;
									this->deleteOneNode(this->_root);
									this->_root = succ;
									succ->parent = NULL;
									//calculle balancing of new root
									if (!is_balanced(this->_root)) {
										//ballande
										this->_root = balance_tl(this->_root);
									}
								}
								else {
									Node<value_type> *psucc = succ->parent;
									Node<value_type> *csucc = succ->right;
									
									succ->parent = NULL;
									succ->right  = NULL;
									psucc->left = csucc;
									if (csucc)
										csucc->parent = psucc;
									succ->right = this->_root->right;
									succ->right->parent = succ;
									succ->left = this->_root->left;
									succ->left->parent = succ;
									this->deleteOneNode(this->_root);
									this->_root = succ;
									//start balncing
									while (psucc) {
										if (!is_balanced(psucc)) {
											psucc = balance_tl(psucc);
										}
										psucc = psucc->parent;
									}
								}
							}
						}
						else {
							//not ROOT
							std::cout <<"NOT root\n";
							Node<value_type> *parent;
							Node<value_type> *succ;
							if (!root->left && !root->right) {
								parent = root->parent;
								if (parent->left == root)
									parent->left = NULL;
								else
									parent->right = NULL;
								this->deleteOneNode(root);
								while (parent) {
									if (!is_balanced(parent))
										parent = balance_tl(parent);
									parent = parent->parent;
								}
								return ;
							}
							if (!root->left) {
								parent = root->parent;
								if (parent->left == root)
									parent->left = root->right;
								else
									parent->right = root->right;
								root->right->parent = parent;
								this->deleteOneNode(root);
								while (parent) {
									if (!is_balanced(parent)) {
										parent = balance_tl(parent);
									}
									parent = parent->parent;
								}
								return ;
							}
							if (!root->right) {
								parent = root->parent;
								if (parent->left == root)
									parent->left = root->left;
								else
									parent->right = root->left;
								root->left->parent = parent;
								this->deleteOneNode(root);
								while (parent) {
									if (!is_balanced(parent))
										parent = balance_tl(parent);
									parent = parent->parent;
								}
								return ;
							}
							succ = root->successor();
							if (root->right == succ) {
								succ->left = root->left;
								root->left->parent = succ;
								parent = root->parent;
								if (parent->right == root)
									parent->right = succ;
								else
									parent->left = succ;
								succ->parent = parent;//
								this->deleteOneNode(root);
								while (parent) {
									if (!is_balanced(parent))
										parent = balance_tl(parent);
									parent = parent->parent;
								}
								return ;
							}
							else {
								Node<value_type> *psucc = succ->parent;
								Node<value_type> *csucc = succ->right;

								parent = root->parent;
								psucc->left = csucc;
								if (csucc)
									csucc->parent = psucc;
								succ->left = root->left;
								succ->right = root->right;
								succ->parent = parent;
								if (parent->right == root)
									parent->right = succ;
								else
									parent->left = succ;
								succ->left->parent = succ;
								succ->right->parent = succ;
								this->deleteOneNode(root);
								while (psucc) {
									if (!is_balanced(psucc))
										psucc = balance_tl(psucc);
									psucc = psucc->parent;
								}
								return ;
							}
						}
						return ;
					}
				}
			}
			size_type erase (const key_type & k) {
				iterator position = this->find(k);
				if (position != this->end()) {////
					this->erase(position);
					return 1;
				}
				return 0;
			}
			void erase (iterator first, iterator last) {
				while (first != last) {
					this->erase(first);
					++first;
				}
			}
			// 	//Swap
			void swap (map& x) {
				Node<value_type>	*tmp = this->_root;
				this->_root = x._root;
				x._root = tmp;
			}
			// 	//clear
			void clear() {
				if (this->_size == 0 || this->_root == NULL)
					return ;
				this->deleteNode(this->_root);//root = NULL;
			}
			// //Observers
			key_compare key_comp() const {
				return key_compare();
			}
			value_compare value_comp() const {
				return value_compare(key_compare());
			}
			// //Operation
			// 	//find
			iterator find (const key_type& k) {
				iterator it = this->begin();

				while (it != this->end()) {
					if (it->first == k)
						return it;
					it++;
				}
				return this->end();
			}
			const_iterator find (const key_type& k) const {
				const_iterator it = this->begin();

				while (it != this->end()) {
					if (it->first == k)
						return it;
					it++;
				}
				return this->end();
			}
			// 	//count
			size_type count (const key_type& k) const {
				iterator e = find(k);
				if (e != this->end())
					return 1;
				return 0;
			}
			// 	//lower_bound
			iterator lower_bound (const key_type& k) {
				iterator it = this->begin();

				while (it != this->end()) {
					if (!this->_comp(it->first, k))
						return it;
					it++;
				}

				return this->end();
			}
			// const_iterator lower_bound (const key_type& k) const;
			// 	//upper_bound
			iterator upper_bound (const key_type& k) {//if root ==NULL
				
			}
			// const_iterator upper_bound (const key_type& k) const;
			// 	//equal_range
			// pair<const_iterator,const_iterator> equal_range (const key_type& k) const;
			// pair<iterator,iterator>             equal_range (const key_type& k);
			//get_allocator
			// allocator_type get_allocator() const { return this->_alloc;}//or nAlloc??
		private:
			Alloc       		_alloc;//for allocating value_type's
			Compare     		_keyComp;//use functor to compare two key of pair's
			size_type			_size;
			node_allocator		_nAlloc;//call def const of allocator<Node<value_type> >()
			Node<value_type>	*_root;
			std::vector<char>	_pathInsert;
			value_compare		*_comp;///////////
			Node<value_type>	_nullEnd;
			Node<value_type>	_nullRend;
			// Node<value_type>	*NillBegin;
	};
}

#endif