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
            typedef Key         key_type;
            typedef 
        private:
    };
}

#endif