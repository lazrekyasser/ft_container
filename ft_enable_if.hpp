#ifndef FT_ENABLE_IF
#define FT_ENABLE_IF

#include <type_traits>

namespace ft {
    //Enable_IF
    template<bool B, class T = void>
    struct enable_if {};
 
    template<class T>
    struct enable_if<true, T> {
        typedef T type;
    };
    //Integral_const
    template <class T, T v>
    struct integral_constant {
        static constexpr T value = v;
        typedef T value_type;
        typedef integral_constant<T,v> type;
        constexpr operator T() { return v; }
    };
    typedef integral_constant<bool, true> true_type;
    typedef integral_constant<bool,false> false_type;
    // true_type::type();
    // IS_INTEGRAL
    template<class T>
    struct is_integral : public integral_constant<T, >;
}

#endif