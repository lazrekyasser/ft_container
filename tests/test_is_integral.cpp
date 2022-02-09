/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_is_integral.cpp                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iounejja <iounejja@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/03 11:59:04 by iounejja          #+#    #+#             */
/*   Updated: 2021/11/03 12:18:11 by iounejja         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <vector>
#include "../vector/ft_enable_if.hpp"

int		main(void) {
	
	{
		std::cout << "======================= TEST std::equal =======================" << std::endl;
		std::cout << (std::is_integral<bool>::value ? "true" : "false") << std::endl;
		std::cout << (std::is_integral<char>::value ? "true" : "false") << std::endl;
		std::cout << (std::is_integral<char16_t>::value ? "true" : "false") << std::endl;
		std::cout << (std::is_integral<char32_t>::value ? "true" : "false") << std::endl;
		std::cout << (std::is_integral<wchar_t>::value ? "true" : "false") << std::endl;
		std::cout << (std::is_integral<signed char>::value ? "true" : "false") << std::endl;
		std::cout << (std::is_integral<short int>::value ? "true" : "false") << std::endl;
		std::cout << (std::is_integral<int>::value ? "true" : "false") << std::endl;
		std::cout << (std::is_integral<long int>::value ? "true" : "false") << std::endl;
		std::cout << (std::is_integral<long long int>::value ? "true" : "false") << std::endl;
		std::cout << (std::is_integral<unsigned char>::value ? "true" : "false") << std::endl;
		std::cout << (std::is_integral<unsigned short int>::value ? "true" : "false") << std::endl;
		std::cout << (std::is_integral<unsigned int>::value ? "true" : "false") << std::endl;
		std::cout << (std::is_integral<unsigned long int>::value ? "true" : "false") << std::endl;
		std::cout << (std::is_integral<unsigned long long int>::value ? "true" : "false") << std::endl;
		std::cout << (std::is_integral<std::string>::value ? "true" : "false") << std::endl;
		std::cout << "==============================================================" << std::endl;
	}
	{
		std::cout << "======================= TEST ft::equal =======================" << std::endl;
		std::cout << (ft::is_integral<bool>::value ? "true" : "false") << std::endl;
		std::cout << (ft::is_integral<char>::value ? "true" : "false") << std::endl;
		std::cout << (ft::is_integral<char16_t>::value ? "true" : "false") << std::endl;
		std::cout << (ft::is_integral<char32_t>::value ? "true" : "false") << std::endl;
		std::cout << (ft::is_integral<wchar_t>::value ? "true" : "false") << std::endl;
		std::cout << (ft::is_integral<signed char>::value ? "true" : "false") << std::endl;
		std::cout << (ft::is_integral<short int>::value ? "true" : "false") << std::endl;
		std::cout << (ft::is_integral<int>::value ? "true" : "false") << std::endl;
		std::cout << (ft::is_integral<long int>::value ? "true" : "false") << std::endl;
		std::cout << (ft::is_integral<long long int>::value ? "true" : "false") << std::endl;
		std::cout << (ft::is_integral<unsigned char>::value ? "true" : "false") << std::endl;
		std::cout << (ft::is_integral<unsigned short int>::value ? "true" : "false") << std::endl;
		std::cout << (ft::is_integral<unsigned int>::value ? "true" : "false") << std::endl;
		std::cout << (ft::is_integral<unsigned long int>::value ? "true" : "false") << std::endl;
		std::cout << (ft::is_integral<unsigned long long int>::value ? "true" : "false") << std::endl;
		std::cout << (ft::is_integral<std::string>::value ? "true" : "false") << std::endl;
		std::cout << "==============================================================" << std::endl;
	}

	return 0;
}