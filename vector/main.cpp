#include <iostream>
#include <memory>
#include <vector>
#include "ft_vector.hpp"

class A {
    public:
        int a;
        char b;
        A() : a(0), b('0') {}
        A(int a, char b) : a(a), b(b) {}
};

std::ostream&   operator<<(std::ostream & o, A const & a) {
    o << a.a << " " << a.b;
    return o;
}
// // template<typename T>
// bool fun(int & a) {
//   return false;
// }
// int main() {
//     //#####TEST VECTOR CONST ALLOC
//     // std::allocator<int> alloc;
//     // int *arr = alloc.allocate(1);
//     // arr[0] = 8;
//     // alloc.construct(arr, 8);
//     // int *arr = alloc.allocate(2);
//     // arr[1] = 9;
//     // for (int i = 0; i < 2; i++)
//     //     std::cout <<arr[i]<< std::endl;
//     // alloc.deallocate(arr, 0);

//     // alloc.destroy(arr);
//     ///#####TEST RESERVE
// //     std::vector<int> bar;
// //   std::vector<int>::size_type sz = bar.capacity();
// //   bar.reserve(100);   // this is the only difference with foo above
// //   std::cout << "making bar grow:\n";
// //   for (int i=0; i<100; ++i) {
// //     bar.push_back(i);
// //     if (sz!=bar.capacity()) {
// //       sz = bar.capacity();
// //       std::cout << "capacity changed: " << sz << '\n';
// //     }
// //   }
// //       std::cout << "capacity changed: " << bar.capacity() << '\n';
//     // std::vector<int> vec;
//     // vec.push_back(1);
//     // vec.push_back(1);
//     // vec.push_back(1);
//     // vec.push_back(1);
//     // vec.push_back(1);
//     // vec.reserve(10);
//     // std::cout <<"size       = "<<vec.size()<< std::endl;
//     // std::cout <<"capacity   = "<<vec.capacity()<< std::endl;
//     // for (int i = 0; i < vec.size(); i++)
//     //     std::cout <<vec[i]<< std::endl;
//     //#################
//     // std::allocator<int> alloc;
//     // int *ptr = alloc.allocate(5);
//     // // *(ptr + 3) = 7;
//     // for (size_t i = 0; i < 5; i++) {
//     //     alloc.construct(ptr + i, i);//construre un object dans cette address
//     //     std::cout <<ptr[i]<< std::endl;
//     // }
    
//     // alloc.deallocate(ptr, 5);
//     // std::cout <<(ptr[5])<< std::endl;
//     // // std::cout <<*(--ptr)<< std::endl;

//     ///#######TEST ITERATORS#######////////
//     // std::vector<int> vec1(5,3);
//     // std::vector<int> vec2(5,2);

//     // std::vector<int>::iterator it1 = vec1.begin() + 3;
//     // std::vector<int>::iterator it2 = vec1.begin() - 3;
//     // std::ptrdiff_t it3 = it2 - it1;
//     // std::cout << it3 << std::endl;
//     // it2 += 9;
//     // // printf("address of vec1 = %p", it1);
//     // int *ptr1 = &vec1[0];
//     // int *ptr2 = &vec1[9];
//     // std::cout << "address of vec1 = " << ptr1 <<std::endl;
//     // std::cout << "address of vec1 - 3 = " << ptr2 <<std::endl;
//     // std::cout << (it1 > it2) << std::endl;
//     // std::cout << *it2 << std::endl;
//     // A a(1, 'a');
//     // A b(2, 'b');
//     // NAME_SPACE::vector<A> vec;
//     // // vec.reserve(10);
//     // vec.push_back(a);
//     // vec.push_back(b);
//     // vec.push_back(b);
//     // vec.push_back(b);
//     // vec.push_back(b);
//     // for (size_t i = 0; i < vec.capacity(); i++) {//untile size
//     //     std::cout <<vec[i]<< std::endl;
//     // }
//     // vec.pop_back();
//     // for (size_t i = 0; i < vec.capacity(); i++) {//untile size
//     //     std::cout <<vec[i]<< std::endl;
//     // }
//     // A c(3, 'c');
//     // std::cout <<"size       = "<<vec.size()<< std::endl;
//     // std::cout <<"capacity   = "<<vec.capacity()<< std::endl;
//     // std::cout <<"---resizingg---------"<< std::endl;
//     // vec.resize(11, c);
//     // std::cout <<"size       = "<<vec.size()<< std::endl;
//     // std::cout <<"capacity   = "<<vec.capacity()<< std::endl;
//     // for (size_t i = 0; i < vec.capacity(); i++) {//untile size
//     //     std::cout <<vec[i]<< std::endl;
//     // }

//     // NAME_SPACE::vector<int> vec;
//     // vec.push_back(1);
//     // vec.push_back(2);
//     // vec.push_back(1);
//     // vec.push_back(2);
//     // vec.push_back(1);
//     // vec.push_back(2);
//     // std::cout << vec[-10] << std::endl;
//     // NAME_SPACE::vector<int>::iterator b = vec.begin() + 2;
//     // NAME_SPACE::vector<int>::iterator e = vec.end();
//     // int i = 2;
//     // while (i < vec.size()) {
//     //     std::cout <<*b<< std::endl;
//     //     b++;
//     //     i++;
//     // }
//     // ft::vector<int> vec;
//     // vec.push_back(1);
//     // vec.push_back(1);
//     // vec.push_back(1);
//     // vec.push_back(1);
//     // vec.push_back(1);
//     // // for (size_t i = 0; i < vec.capacity(); i++) {//untile size
//     // //     std::cout <<vec.at(i)<< std::endl;
//     // // }
//     // int a = vec.front() += 10;
//     // std::cout <<a << std::endl;
//     ft::vector<int> vec;

//   vec.push_back(10);
//   vec.push_back(10);
//   vec.push_back(10);
//   vec.push_back(10);
//   vec.push_back(10);
//   ft::vector<int> v(5, 3);
//   v.push_back(1);
//   v.push_back(2);
//   v.push_back(3);
//   // v.push_back(7);
//   // v.push_back(7);
//   // v.push_back(7);
//   // v.push_back(7);
//   // v.push_back(7);
//   // v.push_back(7);
//   for (size_t i = 0; i < vec.capacity(); i++) {//untile size
//         std::cout <<vec[i]<< std::endl;
//   }
//   std::cout <<"size       = "<<vec.size()<< std::endl;
//     std::cout <<"capacity   = "<<vec.capacity()<< std::endl;
//   std::cout << "assigning----\n";
//   vec.assign(v.begin(), v.end());
//   std::cout <<"size       = "<<vec.size()<< std::endl;
//     std::cout <<"capacity   = "<<vec.capacity()<< std::endl;
//   for (size_t i = 0; i < vec.capacity(); i++) {//untile size
//         std::cout <<vec[i]<< std::endl;
//   }
//     return 0;
// }
// bool is_n(std::vector<int> & v, int val)
// {
//   for (int i = 0; i < v.size(); i++) {
//     if (v[i] == val)
//       return true;
//   }
//   return false;
// }
// int main() {
//   std::vector<int> v;
//   v.push_back(7);
//   for (int x = 0; x < v.size(); x++) {
//     for (int i = 1; i < v[x]; i++) {
//       if (v[x] % i == 1 && !is_n(v, v[x]-i)) {
//         v.push_back(v[x] - i);
//         std::cout <<"pushed = "<<v[x]-i << "size = "<<v.size()<< std::endl;
//         // break ;
//       }
//     }
//   }
//   for (int i = 0; i < v.size(); i++)
//     std::cout <<v[i]<< std::endl;
//   std::cout <<"size = "<<v.size()<< std::endl;
//   return 0;
// }
int main( ) {
  // A* arr = new A[5];
  // arr[0] =  A(1, '1');
  // arr[1] =  A(2, '2');
  // arr[2] =  A(3, '3');
  // // std::cout <<"arr[-1] = "<<arr[-1]<< std::endl;
  // // for (int i = 0; i < 5; i++) {
  // //   std::cout <<arr[i]<< std::endl;
  // // }
  // // int *arr = new int[5];
  // // arr[0] =  1;
  // // arr[1] =  2;
  // // arr[2] =  3;
  // std::cout <<"arr[-1] = "<<arr[-1]<<std::endl;
  // for (int i = 0; i < 5; i++) {
  //   std::cout <<arr[i]<< "| ";
  // }
  // std::cout << "\n";
  // memmove(arr + 1, arr, 4 * sizeof(A));
  // for (int i = 0; i < 5; i++) {
  //   std::cout <<arr[i] << "| ";
  // }
  // std::cout << "\n";
  // std::vector<int> v;
  // v.push_back(20);
  // v.push_back(21);
  // v.push_back(22);
  // v.push_back(23);
  // v.push_back(24);
  // NAME_SPACE::vector<int> myvector;
  // myvector.push_back(1);
  // myvector.push_back(2);
  // myvector.push_back(3);
  // myvector.push_back(4);
  // myvector.push_back(5);
  // myvector.push_back(6);
  // // myvector.push_back(7);
  // // myvector.push_back(8);
  // // myvector.push_back(9);
  // // // myvector.push_back(10);
  // NAME_SPACE::vector<int> v(9, 100);
  // // NAME_SPACE::vector<int> v(myvector);
  // // v = b;
  //   myvector.swap(v);
  // std::cout << "capacity " << myvector.capacity() << std::endl;
  // std::cout << "size " << myvector.size() << std::endl;

  //   std::cout << "myvector contains:";
  //   for (int i=0;i<myvector.size();i++) {
  //       std::cout << ' ' << myvector[i];
  //   }
  //   std::cout << '\n';
  //   // NAME_SPACE::vector<int>::iterator i= 
  //   // myvector.insert(myvector.begin()+7 , 2, 10);
  //   std::cout << "capacity " << v.capacity() << std::endl;
  //   std::cout << "size " << v.size() << std::endl;
  //   std::cout << "v contains:";
  //   for (NAME_SPACE::vector<int>::iterator it = v.begin()\
  //   ; it != v.end(); ++it) {
  //     std::cout << ' ' << *it;
  //   }
  //   std::cout << '\n';
  // NAME_SPACE::vector<int> vec(5, 100);
  // NAME_SPACE::vector<int> v(5, 200);
  // std::cout << "befor insert\n";
  // std::cout << "capacity " << vec.capacity() << std::endl;
  // std::cout << "size " << vec.size() << std::endl;

  //   std::cout << "vec contains:";
  //   for (int i=0;i<vec.size();i++) {
  //       std::cout << ' ' << vec[i];
  //   }
  //   std::cout << '\n';
  // // vec.insert(vec.begin()+1, v.begin(), v.begin()+7);
  // vec.insert(vec.begin()+1, 7, 20);
  // std::cout << "after insert\n";
  // std::cout << "capacity " << vec.capacity() << std::endl;
  // std::cout << "size " << vec.size() << std::endl;

  //   std::cout << "vec contains:";
  //   for (int i=0;i<vec.size();i++) {
  //       std::cout << ' ' << vec[i];
  //   }
  //   std::cout << '\n';
    // std::cout << ft::is_integral<std::string>::value << std::endl;
    // std::cout << *i<<std::endl;

    ///test operators between vectors
  //   ft::vector<int> foo (3,50);   // three ints with a value of 100
  //   ft::vector<int> bar (3,100);   // two ints with a value of 200

  // if (foo < bar) std::cout << "foo and bar are equal\n";
  // ft::vector<int> v1(5, 100);
  // ft::vector<int> v2(5, 200);
  // // v1.swap(v2);
  // for (int i = 0; i < v1.size();i++)
  //   std::cout <<v1[i] <<" ";
  //   std::cout << std::endl;
  // for (int i = 0; i < v2.size();i++)
  //   std::cout <<v2[i] <<" ";
  // std::cout << std::endl;


  //##########test const Iterator
  // NAME_SPACE::vector<int> myvector;
  // for (int i=0; i<10; i++) myvector.push_back(i);	// myvector: 0 1 2 3 4 5 6 7 8 9

  // NAME_SPACE::vector<int> v(11, 100);
  // for (int i = 0; i < myvector.size(); i++)
  //   std::cout <<myvector[i]<<" ";
  // std::cout << "\n";
  // myvector.assign(myvector.begin(), myvector.begin() + 3);
  // for (int i = 0; i < myvector.size(); i++)
  //   std::cout <<myvector[i]<<" ";
  // std::cout << "\n";
  NAMESPACE::vector<int> vec;
        NAMESPACE::vector<int> vec1(10,7);
        NAMESPACE::vector<int>::iterator it;
        NAMESPACE::vector<int>::iterator it1;
        NAMESPACE::vector<int>::iterator it2;
        NAMESPACE::vector<int>::iterator vit = vec1.begin();
        NAMESPACE::vector<int>::iterator vit1 = vec1.end();
        for (int i = 5; i >= 0; i--) {
            vec.push_back(i);
        }
        std::cout << "ft::capacity : " << vec1.capacity() << std::endl;
        std::cout << "ft::size : " << vec1.size() << std::endl;
        it = vec.begin();
        it1 = vec.end();
        vec1.insert(vit, 500, -100);
        // it = vec.begin();
        // vec.insert(it + 2, 100);
        // it = vec.begin();
        // vec.insert(it + 2, 100);
        // it = vec.begin();
        // vec.insert(it + 2, 100);
        // std::cout << "it2 = " << *(it2) << std::endl;
        it = vec1.begin();
        it1 = vec1.end();
        while (it != it1) {
            std::cout << "element = " << *it << std::endl;
            it++;
        }
        std::cout << "ft::capacity : " << vec1.capacity() << std::endl;
        std::cout << "ft::size : " << vec1.size() << std::endl;


  //################
  return 0;

}
//factor overload operator() in the class
//predicate are something to return Boolean
//when function ///return bool and take 1 argument/// we CALL it UNARY PREDUCATE
//when function ///return bool and take 2 argument/// we CALL it BINARY PREDICATE
