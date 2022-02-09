/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_pair.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iounejja <iounejja@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/03 11:10:57 by iounejja          #+#    #+#             */
/*   Updated: 2021/11/03 11:18:38 by iounejja         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "../map/ft_pair.hpp"

int		main(void) {
	
	{
		std::pair<int, int>	p1;
		std::pair<int, int>	p2(10, 1);
		std::pair<int, int>	p3(p2);
		std::pair<int, int>	p4;
		std::pair<int, int>	p5(10, 1);

		p4 = p3;

		std::cout << "======================= TEST std::pair =======================" << std::endl;
		std::cout << "first : " << p4.first << std::endl;
		std::cout << "second : " << p4.second << std::endl;
		std::cout << " - ==\t: " << (p4 == p5 ? "true" : "false") << std::endl;
		std::cout << " - !=\t: " << (p4 != p5 ? "true" : "false") << std::endl;
		std::cout << " - <\t: " << (p4 < p5 ? "true" : "false") << std::endl;
		std::cout << " - >\t: " << (p4 > p5 ? "true" : "false") << std::endl;
		std::cout << " - <=\t: " << (p4 <= p5 ? "true" : "false") << std::endl;
		std::cout << " - >=\t: " << (p4 >= p5 ? "true" : "false") << std::endl;
		std::cout << "==============================================================" << std::endl;
	}
	

	return 0;
}