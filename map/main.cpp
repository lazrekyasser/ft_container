#include <iostream>
#include <map>
#include <vector>
#include "ft_pair.hpp"
// #include "../vector/ft_vector.hpp"
#include "ft_map.hpp"


int main() {
//     NS::pair <std::string,int> product1;                     // default constructor
//   std::pair <std::string,int> product2 ("tomatoes",1);   // value init
//   std::pair <std::string,int> product3 (product2);          // copy constructor
// std::vector<int> v;
//   product1 = NS::make_pair(std::string("tomatoes"),1);   // using make_pair (move)

//   product2.first = "shoes";                  // the type of first is string
//   product2.second = 23;                   // the type of second is double

//   std::cout <<"compaire "<<(product2 == product3)<< std::endl;
//   std::cout << "The price of " << product1.first << " is $" << product1.second << '\n';
//   std::cout << "The price of " << product2.first << " is $" << product2.second << '\n';
//   std::cout << "The price of " << product3.first << " is $" << product3.second << '\n';
//   NS::pair<int, int> p1(1, 20);
//   NS::pair<int, int> p2(1, 10);
//   std::cout <<"compaire "<<(p2 > p1)<< std::endl;
//   NS::pair<std::string, int> p;
//   std::cout <<"first |"<<p.first<<"| second |"<<p.second<<"|"<< std::endl;
	//#####test Rebind <> 
		// srand(time(NULL));
		// NS::map<int, int> mymap;
		// for (int i = 0; i < 3; i++)
		// {
		// 	mymap.insert(NS::make_pair<int,int>(rand() * 10,i));
		// }
		
		// std::cout <<"m size = "<<m.size()<<" mymap size = "<<mymap.size()<<std::endl;
	ft::pair<const int, int> p1(3, 1);
	ft::pair<const int, int> p2(1, 1);
	ft::pair<const int, int> p3(2, 1);
	ft::pair<const int, int> p4(5, 1);
	ft::pair<const int, int> p5(0, 1);
	ft::pair<const int, int> p6(7, 1);
	ft::pair<const int, int> p7(71, 1);
	ft::pair<const int, int> p8(77, 1);
	ft::pair<const int, int> p9(-7, 1);
	ft::pair<const int, int> p10(19, 1);
	ft::map<int, int> mymap;

	mymap.insert(p1);
	mymap.insert(p2);
	mymap.insert(p3);
	mymap.insert(p4);
	mymap.insert(p5);
	mymap.insert(p6);
	mymap.insert(p7);
	mymap.insert(p8);
	mymap.insert(p9);
	mymap.insert(p10);
		mymap.print(mymap.getRootT());
		mymap.affichPath();
}
