#ifndef FT_STACK
#define FT_STACK

#include "../vector/ft_vector.hpp"

namespace ft {
	template<class T, class Container = ft::vector<T> >
	class stack {
		public:
			typedef				Container					container_type;//vector<T>
			typedef typename	Container::value_type		value_type;//T
			typedef typename 	Container::size_type		size_type;

		//constructor
		explicit stack (const container_type& ctnr = container_type()) {
			this->_c = ctnr;//opreator= of 2 vectors
		}

		//function
		bool		empty() const {
			return this->_c.empty();
		}
		size_type	size() const {
			return this->_c.size();
		}

		value_type&			top() {
			return this->_c.back();
		}
		const value_type&	top() const {
			return this->_c.back();
		}

		void push (const value_type& val) {
			this->_c.push_back(val);
		}

		void pop() {
			this->_c.pop_back();
		}
		//firand function's

		protected:
			Container _c;

			template<class TT, class CContainer>
			friend bool operator== (const stack<TT,CContainer>& lhs, const stack<TT,CContainer>& rhs);
			template<class TT, class CContainer>
			friend bool operator!= (const stack<TT,CContainer>&, const stack<TT,CContainer>&);
			template<class TT, class CContainer>
			friend bool operator<  (const stack<TT,CContainer>&, const stack<TT,CContainer>&);
			template<class TT, class CContainer>
			friend bool operator<= (const stack<TT,CContainer>&, const stack<TT,CContainer>&);
			template<class TT, class CContainer>
			friend bool operator>  (const stack<TT,CContainer>&, const stack<TT,CContainer>&);
			template<class TT, class CContainer>
			friend bool operator>= (const stack<TT,CContainer>&, const stack<TT,CContainer>&);
	};

	template <class T, class Container>
	bool operator== (const stack<T,Container>& lhs, const stack<T,Container>& rhs) {
		return lhs._c == rhs._c;
	}
	template <class T, class Container>
  	bool operator!= (const stack<T,Container>& lhs, const stack<T,Container>& rhs) {
		  return lhs._c != rhs._c;
	}
	template <class T, class Container>
  	bool operator<  (const stack<T,Container>& lhs, const stack<T,Container>& rhs) {
		  return lhs._c < rhs._c;
	  }
	template <class T, class Container>
  	bool operator<= (const stack<T,Container>& lhs, const stack<T,Container>& rhs) {
		  return lhs._c <= rhs._c;
	  }
	template <class T, class Container>
  	bool operator>  (const stack<T,Container>& lhs, const stack<T,Container>& rhs) {
		  return lhs._c > rhs._c;
	  }
	template <class T, class Container>
  	bool operator>= (const stack<T,Container>& lhs, const stack<T,Container>& rhs) {
		  return lhs._c >= rhs._c;
	  }
}

#endif