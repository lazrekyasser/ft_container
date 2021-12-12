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
        static const T value = v;

        typedef T value_type;
        typedef integral_constant<T,v> type;
         operator T() { return v; }
    };
    //value_type === bool
    //type       === integrale_constant<bool, true or false>
    //value      === true or false
    typedef integral_constant<bool, true> true_type;//true_type::value_type == bool ; ::value === true 
    typedef integral_constant<bool,false> false_type;//true_type::value_type == bool; ::value === fasle
    // IS_INTEGRAL
    template<class T>
    struct is_integral : public false_type {};

    template<>
    struct is_integral<bool>: public true_type {};
    template<>
    struct is_integral<char>: public true_type {};
    template<>
    struct is_integral<char16_t>: public true_type {};
    template<>
    struct is_integral<char32_t>: public true_type {};
    template<>
    struct is_integral<wchar_t>: public true_type {};
    template<>
    struct is_integral<signed char>: public true_type {};
    template<>
    struct is_integral<short int>: public true_type {};
    template<>
    struct is_integral<int>: public true_type {};
    template<>
    struct is_integral<long int>: public true_type {};
    template<>
    struct is_integral<long long int>: public true_type {};
    template<>
    struct is_integral<unsigned char>: public true_type {};
    template<>
    struct is_integral<unsigned short int>: public true_type {};
    template<>
    struct is_integral<unsigned int>: public true_type {};
    template<>
    struct is_integral<unsigned long int>: public true_type {};
    template<>
    struct is_integral<unsigned long long int>: public true_type {};
}

#endif