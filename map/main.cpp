#include <iostream>
#include <map>
#include <vector>
#include "ft_pair.hpp"
// #include "../vector/ft_vector.hpp"
#include "ft_map.hpp"



// int main() {
// //     std::pair <std::string,int> product1;                     // default constructor
// //   std::pair <std::string,int> product2 ("tomatoes",1);   // value init
// //   std::pair <std::string,int> product3 (product2);          // copy constructor
// // std::vector<int> v;
// //   product1 = NS::make_pair(std::string("tomatoes"),1);   // using make_pair (move)

// //   product2.first = "shoes";                  // the type of first is string
// //   product2.second = 23;                   // the type of second is double

// //   std::cout <<"compaire "<<(product2 == product3)<< std::endl;
// //   std::cout << "The price of " << product1.first << " is $" << product1.second << '\n';
// //   std::cout << "The price of " << product2.first << " is $" << product2.second << '\n';
// //   std::cout << "The price of " << product3.first << " is $" << product3.second << '\n';
// //   NS::pair<int, int> p1(1, 20);
// //   NS::pair<int, int> p2(1, 10);
// //   std::cout <<"compaire "<<(p2 > p1)<< std::endl;
// //   NS::pair<std::string, int> p;
// //   std::cout <<"first |"<<p.first<<"| second |"<<p.second<<"|"<< std::endl;
// 	//#####test Rebind <> 
// 		// srand(time(NULL));
// 		// NS::map<int, int> mymap;
// 		// for (int i = 0; i < 3; i++)
// 		// {
// 		// 	mymap.insert(NS::make_pair<int,int>(rand() * 10,i));
// 		// }
		
// 		// std::cout <<"m size = "<<m.size()<<" mymap size = "<<mymap.size()<<std::endl;
// 	// NS::pair<const int, int> p1(50, 1);
// 	// NS::pair<const int, int> p2(10, 1);
// 	// NS::pair<const int, int> p3(2, 1);
// 	// NS::pair<const int, int> p4(5, 1);
// 	// NS::pair<const int, int> p5(0, 1);
// 	// NS::pair<const int, int> p6(7, 1);
// 	// NS::pair<const int, int> p7(71, 1);
// 	// NS::pair<const int, int> p8(77, 1);
// 	// NS::pair<const int, int> p9(-7, 1);
// 	// NS::pair<const int, int> p10(19, 1);
// 	// NS::pair<const int, int> p11(8, 1);
// 	// NS::map<int, int> mymap;

// 	// NS::pair<NS::map<int,int>::iterator, bool> ret =  mymap.insert(p1);
// 	// // NS::pair<NS::map<int,int>::iterator, bool> ret1 =  mymap.insert(p1);
// 	// // // std::cout <<ret.second<<std::endl;
// 	// // // std::cout <<(*ret.first).first<<std::endl;
// 	// // // std::cout <<ret1.second<<std::endl;
// 	// // // std::cout <<(*ret1.first).first<<std::endl;
// 	// NS::pair<NS::map<int,int>::iterator, bool> ret2 = mymap.insert(p2);
// 	// // // std::cout <<ret2.second<<std::endl;
// 	// // // std::cout <<(*ret2.first).first<<std::endl;
// 	// mymap.insert(p3);
// 	// mymap.insert(p5);///////////add it
// 	// mymap.insert(p6);
// 	// mymap.insert(p7);
// 	// mymap.insert(p8);
// 	// mymap.insert(p9);
// 	// mymap.insert(p10);
// 	// mymap.insert(p11);
// 	// #if NS == "std"
// 	// 	std::cout <<"ndjdjk\n";
// 	// 	// #if NS == ft
// 	// 	// #endif
// 	// #endif
// 			// mymap.print(mymap.getRootT());mymap.affichPath();
// 	// NS::map<int, int>::iterator it(mymap.begin());
// 	// std::cout <<"it = "<<(*it).first<<std::endl;
// 	// ++it;
// 	// std::cout <<"it = "<<(*it).first<<std::endl;
// 	// ++it;
// 	// std::cout <<"it = "<<(*it).first<<std::endl;
// 	// ++it;
// 	// std::cout <<"it = "<<(*it).first<<std::endl;
// 	// assert(it == mymap.end());
// 	// ++it;
// 	// // assert(it != mymap.end());
// 	// ++it;
// 	// std::cout <<"it = "<<(*it).first<<std::endl;
// 	// std::cout <<"ok\n";
// 	// std::cout <<"it = "<<(*it).first<<std::endl;
// 	// ++it;++it;++it;
// 	// ++it;
// 	// std::cout <<"it = "<<(*it).first<<std::endl;
// 	// ++it;
// 	// if (it != NULL)
// 	// 	std::cout <<(*it).data->first<< std::endl;
// 	// mymap.r_rotation(mymap.getRoot());
// 	// 	mymap.print(mymap.getRootT());



// 	// #########################
// 	//TTTTTEEEESTTTTTEE INSERTTTTTT

// 	NS::pair<const int, int> p1(50, 1);
// 	NS::pair<const int, int> p2(60, 1);
// 	NS::pair<const int, int> p3(2, 1);
// 	NS::pair<const int, int> p31(1, 1);
// 	NS::pair<const int, int> p4(5, 1);
// 	NS::pair<const int, int> p5(3, 1);
// 	NS::pair<const int, int> p6(7, 1);
// 	NS::pair<const int, int> p7(71, 1);

// 	NS::map<int, int> mymap;
// 	// std::cout <<(*it).first<<std::endl;
// 	// NS::map<int, int>::iterator it = mymap.insert(mymap.begin(), p1);
// 	// std::cout <<(*it).first<<std::endl;
// 	// NS::map<int, int>::iterator it1 = mymap.insert(mymap.begin(), p2);
// 	// std::cout <<(*it1).first<<std::endl;
// 	// NS::map<int, int>::iterator it3 = mymap.insert(mymap.begin(), p3);
// 	// std::cout <<(*it3).first<<std::endl;
// 	// NS::map<int, int>::iterator it4 = mymap.insert(mymap.begin(), p1);
// 	// std::cout <<(*it4).first<<std::endl;
// 	///////////////////////
// 	mymap.insert(p1);
// 	mymap.insert(p2);
// 	mymap.insert(p3);
// 	mymap.insert(p31);
// 	mymap.insert(p4);
// 	mymap.insert(p5);
// 	mymap.insert(p6);
// 	mymap.insert(p7);
// 	mymap.print(mymap.getRootT());
// 	NS::map<int, int>::iterator it = mymap.begin();
// 	++it;++it;++it;
// 	std::cout<<"root = "<<(*it).first<<std::endl;
// 	mymap.erase(it);
// 	// mymap.affichPath();
// 	// mymap.print(mymap.getRootT());
// 	mymap.printTreeHelper(mymap.getRootT(), 0);
// }

// int main()
// {
//     ft::map<int,int> map;

//     ft::pair<int,int> p1(10,10);
//     ft::pair<int,int> p2(50,10);
//     ft::pair<int,int> p3(20,10);
//     ft::pair<int,int> p4(25,10);
//     ft::pair<int,int> p5(15,10);
//     ft::pair<int,int> p6(30,10);
//     ft::pair<int,int> p7(22,10);
//     ft::pair<int,int> p8(36,10);///
//     ft::pair<int,int> p9(24,10);
//     ft::pair<int,int> p10(32,10);
//     ft::pair<int,int> p11(37,10);
//     ft::pair<int,int> p12(38,10);
//     ft::pair<int,int> p13(40,10);
//     ft::pair<int,int> p14(35,10);

//     ft::pair<int,int> p15(27,10);
//     ft::pair<int,int> p16(26,10);
//     ft::pair<int,int> p17(21,10);
//     ft::pair<int,int> p18(99,10);
//     ft::pair<int,int> p20(34,10);
//     ft::pair<int,int> p19(39,10);

//     map.insert(p1);
//     map.insert(p2);
//     map.insert(p3);
//     map.insert(p4);
//     map.insert(p5);
//     map.insert(p6);
//     map.insert(p7);
//     map.insert(p8);
//     map.insert(p9);
//     map.insert(p10);
//     map.insert(p11);
//     map.insert(p12);
//     map.insert(p13);
//     map.insert(p14);
//     map.insert(p15);
//     map.insert(p16);
//     map.insert(p17);
//     map.insert(p18);
//     map.insert(p20);
//     map.insert(p19);
	
// 	ft::map<int, int>::iterator it = map.begin();
// 	++it;++it;
//     map.printTreeHelper(map.getRoot(), 0);
//     map.erase(it);
//     std::cout <<"-------------------\n";
//     map.printTreeHelper(map.getRoot(), 0);
//     map.print(map.getRoot());
//     it = map.begin();
//     ++it;
//     map.erase(it);
//     std::cout <<"-------------------\n";
//     map.printTreeHelper(map.getRoot(), 0);
//     map.print(map.getRoot());
//     it = map.begin();
//     ++it;++it;++it;
//     ++it;++it;++it;++it;
//     map.erase(it);
//     std::cout <<"-------------------\n";
//     map.printTreeHelper(map.getRoot(), 0);
//     map.print(map.getRoot());
//     it = map.begin();
//     ++it;++it;++it;
//     ++it;++it;++it;++it;
//     map.erase(it);
//     std::cout <<"-------------------\n";
//     map.printTreeHelper(map.getRoot(), 0);
//     map.print(map.getRoot());
//     it = map.begin();
//     ++it;++it;++it;
//     ++it;++it;++it;++it;
//     ++it;++it;++it;++it;
//     map.erase(it);
//     std::cout <<"-------------------\n";
//     map.printTreeHelper(map.getRoot(), 0);
//     map.print(map.getRoot());
//     it = map.begin();
    
//     map.erase(it);
//     std::cout <<"-------------------\n";
//     map.printTreeHelper(map.getRoot(), 0);
//     map.print(map.getRoot());
//     it = map.begin();
//     ++it;++it;++it;
//     ++it;++it;
//     map.erase(it);
//     std::cout <<"-------------------\n";
//     map.printTreeHelper(map.getRoot(), 0);
//     map.print(map.getRoot());
//     it = map.begin();
//     ++it;++it;
//     map.erase(it);
//     std::cout <<"-------------------\n";
//     map.printTreeHelper(map.getRoot(), 0);
//     map.print(map.getRoot());
//     it = map.begin();
//     ++it;++it;++it;
//     map.erase(it);
//     std::cout <<"-------------------\n";
//     map.printTreeHelper(map.getRoot(), 0);
//     map.print(map.getRoot());
//     it = map.begin();
//     map.erase(it);
//     std::cout <<"-------------------\n";
//     map.printTreeHelper(map.getRoot(), 0);
//     map.print(map.getRoot());
//     it = map.begin();
//     map.erase(it);
//     std::cout <<"-------------------\n";
//     map.printTreeHelper(map.getRoot(), 0);
//     map.print(map.getRoot());
    
//     it = map.begin();
//     ++it;
//     map.erase(it);
//     std::cout <<"-------------------\n";
//     map.printTreeHelper(map.getRoot(), 0);
//     map.print(map.getRoot());
    
// }
int main() {
    ft::map<int,int> map;

    ft::pair<int,int> p1(10,10);
    ft::pair<int,int> p2(50,10);
    ft::pair<int,int> p3(20,10);
    ft::pair<int,int> p4(25,10);
    ft::pair<int,int> p5(15,10);
    ft::pair<int,int> p6(30,10);
    ft::pair<int,int> p7(22,10);
    ft::pair<int,int> p8(36,10);///
    ft::pair<int,int> p9(24,10);
    ft::pair<int,int> p10(32,10);
    map.insert(p1);
    map.insert(p2);
    map.insert(p3);
    map.insert(p4);
    map.insert(p5);
    map.insert(p6);
    map.insert(p7);
    map.insert(p8);
    map.insert(p9);
    map.insert(p10);
    // ft::map<int, int>::reverse_iterator bg = map.rend();
    // ft::map<int, int>::reverse_iterator en = map.rbegin();
    int i = 10;
    // --en;
    // --en;
    std::cout<<"node = "<<(*en).first<<"\n";
    map.printTreeHelper(map.getRoot(), 0);
    while (bg != en) {
        std::cout <<"i = "<<i<<" | node = "<<(*en).first<<"\n";
        i--;
        --en;
    }
    
    return 0;
}