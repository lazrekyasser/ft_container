/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_equal.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iounejja <iounejja@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/03 11:21:46 by iounejja          #+#    #+#             */
/*   Updated: 2021/11/03 11:43:26 by iounejja         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <vector>
#include "../vector/equal.hpp"

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
		std::cout << (std::equal(v1.begin(), v1.end(), v2.begin()) ? "true" : "false") << std::endl;
		std::cout << "==============================================================" << std::endl;
	}
	

	return 0;
}