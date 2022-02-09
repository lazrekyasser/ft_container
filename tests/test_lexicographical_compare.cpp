/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_lexicographical_compare.cpp                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iounejja <iounejja@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/03 11:50:50 by iounejja          #+#    #+#             */
/*   Updated: 2021/11/03 11:53:08 by iounejja         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <vector>
#include "../vector/lexicographical_compare.hpp"
bool mycomp (int c1, int c2)
{ return c1 <c2; }
int		main(void) {
	
	{
		std::vector<int>	v1;
		std::vector<int>	v2;

		v1.push_back(1);
		v1.push_back(2);
		v1.push_back(3);

		v2.push_back(1);
		v2.push_back(2);
		v2.push_back(3);

		std::cout << "======================= TEST std::equal =======================" << std::endl;
		std::cout << (std::lexicographical_compare(v1.begin(), v1.end(), v2.begin(), v2.end()) ? "true" : "false") << std::endl;
		std::cout << "==============================================================" << std::endl;
		std::cout << "======================= TEST std::equal-COMP =======================" << std::endl;
		std::cout << (std::lexicographical_compare(v1.begin(), v1.end(), v2.begin(), v2.end(), mycomp) ? "true" : "false") << std::endl;
		std::cout << "==============================================================" << std::endl;
	}
	

	return 0;
}