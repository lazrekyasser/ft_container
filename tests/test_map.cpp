/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_map.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iounejja <iounejja@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/05 10:42:24 by iounejja          #+#    #+#             */
/*   Updated: 2021/11/12 14:01:22 by iounejja         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <map>
#include "../map/ft_map.hpp"


int main() {
	{
		std::cout << "#====================================== map ======================================#" << std::endl;

		NAME_SPACE::map<int, int>	m1;
		NAME_SPACE::map<int, int>	m2(m1);
		NAME_SPACE::map<int, int>	m4;

		m1.insert(NAME_SPACE::make_pair<int, int>(100, 10));
		m1.insert(NAME_SPACE::make_pair<int, int>(101, 11));
		m1.insert(NAME_SPACE::make_pair<int, int>(102, 12));
		m1.insert(NAME_SPACE::make_pair<int, int>(103, 13));
		m1.insert(NAME_SPACE::make_pair<int, int>(104, 14));
		m1.insert(NAME_SPACE::make_pair<int, int>(105, 15));
		m1.insert(NAME_SPACE::make_pair<int, int>(106, 16));
		m1.insert(NAME_SPACE::make_pair<int, int>(107, 17));
		m1.insert(NAME_SPACE::make_pair<int, int>(108, 18));
		m1.insert(NAME_SPACE::make_pair<int, int>(109, 19));
		m1.insert(NAME_SPACE::make_pair<int, int>(110, 20));
		m1.insert(NAME_SPACE::make_pair<int, int>(111, 21));
		m1.insert(NAME_SPACE::make_pair<int, int>(112, 22));
		m1.insert(NAME_SPACE::make_pair<int, int>(113, 23));
		m1.insert(NAME_SPACE::make_pair<int, int>(114, 24));
		m1.insert(NAME_SPACE::make_pair<int, int>(115, 25));
		m1.insert(NAME_SPACE::make_pair<int, int>(116, 26));
		m1.insert(NAME_SPACE::make_pair<int, int>(117, 27));
		m1.insert(NAME_SPACE::make_pair<int, int>(118, 28));
		m1.insert(NAME_SPACE::make_pair<int, int>(119, 29));
		m1.insert(NAME_SPACE::make_pair<int, int>(120, 30));
		m1.insert(NAME_SPACE::make_pair<int, int>(121, 31));
		m1.insert(NAME_SPACE::make_pair<int, int>(122, 32));
		m1.insert(NAME_SPACE::make_pair<int, int>(123, 33));
		m1.insert(NAME_SPACE::make_pair<int, int>(124, 34));

		NAME_SPACE::map<int, int>	m3(m1.begin(), m1.end());

		m4 = m3;

		std::cout << "size\t\t\t: " << m4.size() << std::endl;
		std::cout << "empty\t\t\t: " << (m4.empty() ? "true" : "false") << std::endl;
		std::cout << "find\t\t\t: " << (m4.find(101) != m4.end() ? m4.find(101)->first : 0) << std::endl;
		std::cout << "count\t\t\t: " << (m4.count(101) ? "true" : "false") << std::endl;
		std::cout << "lower_bound\t\t: " << (m4.lower_bound(117) != m4.end() ? m4.lower_bound(102)->first : 0) << std::endl;
		std::cout << "upper_bound\t\t: " << (m4.upper_bound(117) != m4.end() ? m4.upper_bound(117)->first : 0) << std::endl;
		std::cout << "equal_range lower\t: " << m4.equal_range(117).first->first << std::endl;
		std::cout << "equal_range upper\t: " << m4.equal_range(117).second->first << std::endl;

		std::cout << std::endl;

		NAME_SPACE::map<int, int>::iterator it = m4.begin();
		NAME_SPACE::map<int, int>::const_iterator cit = m4.begin();

		std::cout << (it == cit) << std::endl;

		for (it = m4.begin(); it != m4.end(); it++)
			std::cout << it->first << "\t == \t" << it->second << std::endl;

		std::cout << std::endl;

		for (NAME_SPACE::map<int, int>::reverse_iterator it = m4.rbegin(); it != m4.rend(); it++)
			std::cout << it->first << "\t == \t" << it->second << std::endl;

		std::cout << std::endl;

		std::cout << m4[2] << std::endl;
		std::cout << m4[3] << std::endl;

		std::cout << std::endl;

		for (it = m4.begin(); it != m4.end(); it++)
			std::cout << it->first << "\t == \t" << it->second << std::endl;

		m4.insert(NAME_SPACE::make_pair<int, int>(100, 1000));
		m4.insert(NAME_SPACE::make_pair<int, int>(101, 1001));
		m4.insert(NAME_SPACE::make_pair<int, int>(102, 1002));

		m4.insert(m4.begin(), NAME_SPACE::make_pair<int, int>(20, 500));

		m4.clear();

		m4.insert(m1.begin(), m1.end());

		m4.erase(100);

		std::cout << std::endl;

		for (it = m4.begin(); it != m4.end(); it++)
			std::cout << it->first << "\t == \t" << it->second << std::endl;

		std::cout << std::endl;

		m4.swap(m1);

		for (it = m4.begin(); it != m4.end(); it++)
			std::cout << it->first << "\t == \t" << it->second << std::endl;

		std::cout << "#===================================== END ======================================#" << std::endl;
	}

	{
		std::cout << "#====================================== map ======================================#" << std::endl;

		NAME_SPACE::map<std::string, int>	m1;
		NAME_SPACE::map<std::string, int>	m2(m1);
		NAME_SPACE::map<std::string, int>	m4;

		m1.insert(NAME_SPACE::make_pair<std::string, int>("100", 10));
		m1.insert(NAME_SPACE::make_pair<std::string, int>("101", 11));
		m1.insert(NAME_SPACE::make_pair<std::string, int>("102", 12));
		m1.insert(NAME_SPACE::make_pair<std::string, int>("103", 13));
		m1.insert(NAME_SPACE::make_pair<std::string, int>("104", 14));
		m1.insert(NAME_SPACE::make_pair<std::string, int>("105", 15));
		m1.insert(NAME_SPACE::make_pair<std::string, int>("106", 16));
		m1.insert(NAME_SPACE::make_pair<std::string, int>("107", 17));
		m1.insert(NAME_SPACE::make_pair<std::string, int>("108", 18));
		m1.insert(NAME_SPACE::make_pair<std::string, int>("109", 19));
		m1.insert(NAME_SPACE::make_pair<std::string, int>("110", 20));
		m1.insert(NAME_SPACE::make_pair<std::string, int>("111", 21));
		m1.insert(NAME_SPACE::make_pair<std::string, int>("112", 22));
		m1.insert(NAME_SPACE::make_pair<std::string, int>("113", 23));
		m1.insert(NAME_SPACE::make_pair<std::string, int>("114", 24));
		m1.insert(NAME_SPACE::make_pair<std::string, int>("115", 25));
		m1.insert(NAME_SPACE::make_pair<std::string, int>("116", 26));
		m1.insert(NAME_SPACE::make_pair<std::string, int>("117", 27));
		m1.insert(NAME_SPACE::make_pair<std::string, int>("118", 28));
		m1.insert(NAME_SPACE::make_pair<std::string, int>("119", 29));
		m1.insert(NAME_SPACE::make_pair<std::string, int>("120", 30));
		m1.insert(NAME_SPACE::make_pair<std::string, int>("121", 31));
		m1.insert(NAME_SPACE::make_pair<std::string, int>("122", 32));
		m1.insert(NAME_SPACE::make_pair<std::string, int>("123", 33));
		m1.insert(NAME_SPACE::make_pair<std::string, int>("124", 34));

		NAME_SPACE::map<std::string, int>	m3(m1.begin(), m1.end());

		m4 = m3;

		std::cout << "size\t\t\t: " << m4.size() << std::endl;
		std::cout << "empty\t\t\t: " << (m4.empty() ? "true" : "false") << std::endl;
		std::cout << "find\t\t\t: " << (m4.find("101") != m4.end() ? m4.find("101")->first : 0) << std::endl;
		std::cout << "count\t\t\t: " << (m4.count("101") ? "true" : "false") << std::endl;
		std::cout << "lower_bound\t\t: " << (m4.lower_bound("117") != m4.end() ? m4.lower_bound("102")->first : 0) << std::endl;
		std::cout << "upper_bound\t\t: " << (m4.upper_bound("117") != m4.end() ? m4.upper_bound("117")->first : 0) << std::endl;
		std::cout << "equal_range lower\t: " << m4.equal_range("117").first->first << std::endl;
		std::cout << "equal_range upper\t: " << m4.equal_range("117").second->first << std::endl;

		std::cout << std::endl;

		NAME_SPACE::map<std::string, int>::iterator it = m4.begin();
		NAME_SPACE::map<std::string, int>::const_iterator cit = m4.begin();

		std::cout << (it == cit) << std::endl;

		for (it = m4.begin(); it != m4.end(); it++)
			std::cout << it->first << "\t == \t" << it->second << std::endl;

		std::cout << std::endl;

		for (NAME_SPACE::map<std::string, int>::reverse_iterator it = m4.rbegin(); it != m4.rend(); it++)
			std::cout << it->first << "\t == \t" << it->second << std::endl;

		std::cout << std::endl;
		std::cout << m4["2"] << std::endl;
		std::cout << m4["3"] << std::endl;

		std::cout << std::endl;

		for (it = m4.begin(); it != m4.end(); it++)
			std::cout << it->first << "\t == \t" << it->second << std::endl;

		m4.insert(NAME_SPACE::make_pair<std::string, int>("100", 1000));
		m4.insert(NAME_SPACE::make_pair<std::string, int>("101", 1001));
		m4.insert(NAME_SPACE::make_pair<std::string, int>("102", 1002));

		m4.insert(m4.begin(), NAME_SPACE::make_pair<std::string, int>("20", 500));

		m4.clear();

		m4.insert(m1.begin(), m1.end());

		m4.erase("100");

		std::cout << std::endl;

		for (it = m4.begin(); it != m4.end(); it++)
			std::cout << it->first << "\t == \t" << it->second << std::endl;

		std::cout << std::endl;

		m4.swap(m1);

		for (it = m4.begin(); it != m4.end(); it++)
			std::cout << it->first << "\t == \t" << it->second << std::endl;

		std::cout << "#===================================== END ======================================#" << std::endl;
	}
	return 0;
}