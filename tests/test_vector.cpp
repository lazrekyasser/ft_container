/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_vector.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iounejja <iounejja@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/03 12:25:39 by iounejja          #+#    #+#             */
/*   Updated: 2021/12/10 17:01:37 by iounejja         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <vector>
#include <iterator>
#include "../vector/ft_vector.hpp"

int		main(void) {
	{
		std::cout << "=========================== TEST vector ===========================" << std::endl;

		NAME_SPACE::vector<std::string>	v1;
		NAME_SPACE::vector<std::string>	v2(5, "000");
		NAME_SPACE::vector<std::string>	v3(v2);
		NAME_SPACE::vector<std::string>	v4;
		NAME_SPACE::vector<std::string>	v5;

		v1.push_back("001");
		// std::vector<int>::iterator it;

		v1 = v2;
		v2 = v3;
		v2 = v4;
		v1 = v4;
		v1.push_back("002");
		v1.push_back("003");
		v1.push_back("004");
		v1.push_back("005");
		v1.pop_back();
		v1.pop_back();

		v4 = v1;


		std::cout << "size\t: " << v2.size() << std::endl;
		std::cout << "capacity: " << v2.capacity() << std::endl;
		std::cout << "empty\t: " << (v2.empty() ? "true" : "false") << std::endl;
		std::cout << "at\t: " << v4.at(1) << std::endl;
		std::cout << "front\t: " << v4.front() << std::endl;
		std::cout << "back\t: " << v4.back() << std::endl;
		std::cout << "maxsize\t: " << v4.max_size() << std::endl;

		NAME_SPACE::vector<std::string>	v6(v1.begin(), v1.end());

		NAME_SPACE::vector<std::string>::iterator 		it = v6.begin();
		NAME_SPACE::vector<std::string>::const_iterator cit = v6.begin();

		std::cout << (it != cit) << std::endl;

		for (it = v6.begin(); it != v6.end(); it++)
			std::cout << *it << std::endl;

		v4 = v1;

		std::cout << std::endl;

		for (it = v4.begin(); it != v4.end(); it++)
			std::cout << *it << std::endl;

		std::cout << std::endl;

		std::cout << "size\t: " << v4.size() << std::endl;
		std::cout << "capacity: " << v4.capacity() << std::endl;

		std::cout << std::endl;

		for (int i = 0; i < v4.size(); i++)
			std::cout << v4[i] << std::endl;

		std::cout << std::endl;

		NAME_SPACE::vector<std::string>::reverse_iterator rit;

		for (rit = v4.rbegin(); rit != v4.rend(); rit++)
			std::cout << *rit << std::endl;

		std::cout << std::endl;

		v4.resize(1);
		std::cout << "size\t: " << v4.size() << std::endl;
		std::cout << "capacity: " << v4.capacity() << std::endl;

		std::cout << std::endl;

		for (int i = 0; i < v4.size(); i++)
			std::cout << v4[i] << std::endl;

		std::cout << std::endl;

		v5.reserve(3);
		std::cout << "size\t: " << v5.size() << std::endl;
		std::cout << "capacity: " << v5.capacity() << std::endl;

		std::cout << std::endl;

		// v4.assign(v2.begin(), v2.end());
		v4.assign(2, "111");

		std::cout << "size\t: " << v4.size() << std::endl;
		std::cout << "capacity: " << v4.capacity() << std::endl;

		std::cout << std::endl;

		for (int i = 0; i < v4.size(); i++)
			std::cout << v4[i] << std::endl;

		std::cout << std::endl;

		v1.pop_back();
		v1.pop_back();

		std::cout << "size\t: " << v1.size() << std::endl;
		std::cout << "capacity: " << v1.capacity() << std::endl;

		std::cout << std::endl;

		for (int i = 0; i < v1.size(); i++)
			std::cout << v1[i] << std::endl;

		std::cout << std::endl;

		// v4.insert(v4.begin(), "010");
		// // v4.insert(v4.begin(), 6, "010");
		v4.insert(v4.begin(), v1.begin(), v1.end());

		std::cout << "size\t: " << v4.size() << std::endl;
		std::cout << "capacity: " << v4.capacity() << std::endl;

		std::cout << std::endl;

		for (int i = 0; i < v4.size(); i++)
			std::cout << v4[i] << std::endl;

		std::cout << std::endl;

		std::cout << "erased : " << *(v4.erase(v4.begin() + 1)) << std::endl;
		// std::cout << "erased : " << *(v4.erase(v4.begin() + 1, v4.end() - 2)) << std::endl;
		std::cout << "size\t: " << v4.size() << std::endl;
		std::cout << "capacity: " << v4.capacity() << std::endl;

		std::cout << std::endl;

		for (int i = 0; i < v4.size(); i++)
			std::cout << v4[i] << std::endl;

		std::cout << std::endl;

		std::cout << "1size\t: " << v1.size() << std::endl;
		std::cout << "1capacity: " << v1.capacity() << std::endl;
		std::cout << "4size\t: " << v4.size() << std::endl;
		std::cout << "4capacity: " << v4.capacity() << std::endl;

		std::cout << std::endl;

		v4.swap(v1);
		std::cout << "1size\t: " << v1.size() << std::endl;
		std::cout << "1capacity: " << v1.capacity() << std::endl;
		std::cout << "4size\t: " << v4.size() << std::endl;
		std::cout << "4capacity: " << v4.capacity() << std::endl;
		// std::cout << "size\t: " << v4.size() << std::endl;
		// std::cout << "capacity: " << v4.capacity() << std::endl;

		// std::cout << std::endl;

		for (int i = 0; i < v4.size(); i++)
			std::cout << v4[i] << std::endl;

		std::cout << std::endl;
		for (int i = 0; i < v1.size(); i++)
			std::cout << v1[i] << std::endl;

		std::cout << std::endl;

		std::cout << "================================= END =================================" << std::endl;
	}
	return 0;
}