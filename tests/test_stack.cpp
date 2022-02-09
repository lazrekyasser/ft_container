/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_stack.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iounejja <iounejja@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/12 13:29:08 by iounejja          #+#    #+#             */
/*   Updated: 2021/11/12 13:54:49 by iounejja         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <stack>
#include "../stack/ft_stack.hpp"

int		main(void) {
	{
		std::cout << "=========================== TEST stack ===========================" << std::endl;

		NAME_SPACE::stack<int> s1;
		NAME_SPACE::stack<int> s2(s1);
		NAME_SPACE::stack<int> s3;

		s1.push(10);
		s1.push(11);
		s1.push(12);
		s1.push(13);
		s1.push(14);

		s3 = s1;

		std::cout << "size\t: " << s3.size() << std::endl;
		std::cout << "empty\t: " << (s3.empty() ? "true" : "false") << std::endl;
		std::cout << "top\t: " << s3.top() << std::endl;

		s3.pop();

		std::cout << "top\t: " << s3.top() << std::endl;

		std::cout << std::endl;

		std::cout << "================================= END =================================" << std::endl;
	}
	return 0;
}