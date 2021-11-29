#include <iostream>
#include <memory>
#include <vector>

class A {
    public:
        int a;
        char b;
        A(int a, char b) : a(a), b(b) {}
};

int main() {
    //#####TEST VECTOR CONST ALLOC
    std::allocator<int> alloc;
    int *arr = alloc.allocate(1);
    arr[0] = 8;
    arr = alloc.allocate(2);
    arr[1] = 9;
    for (int i = 0; i < 2; i++)
        std::cout <<arr[i]<< std::endl;
    // std::vector<int> vec(alloc);
    // vec.push_back(1);
    // // vec.push_back(1);
    // // vec.push_back(1);
    // // vec.push_back(1);
    // // vec.push_back(1);
    // std::cout <<"size       = "<<vec.size()<< std::endl;
    // std::cout <<"capacity   = "<<vec.capacity()<< std::endl;

    //#################
    // std::allocator<int> alloc;
    // int *ptr = alloc.allocate(5);
    // // *(ptr + 3) = 7;
    // for (size_t i = 0; i < 5; i++) {
    //     alloc.construct(ptr + i, i);//construre un object dans cette address
    //     std::cout <<ptr[i]<< std::endl;
    // }
    
    // alloc.deallocate(ptr, 5);
    // std::cout <<(ptr[5])<< std::endl;
    // // std::cout <<*(--ptr)<< std::endl;

    ///#######TEST ITERATORS#######////////
    // std::vector<int> vec1(5,3);
    // std::vector<int> vec2(5,2);

    // std::vector<int>::iterator it1 = vec1.begin() + 3;
    // std::vector<int>::iterator it2 = vec1.begin() - 3;
    // std::ptrdiff_t it3 = it2 - it1;
    // std::cout << it3 << std::endl;
    // it2 += 9;
    // // printf("address of vec1 = %p", it1);
    // int *ptr1 = &vec1[0];
    // int *ptr2 = &vec1[9];
    // std::cout << "address of vec1 = " << ptr1 <<std::endl;
    // std::cout << "address of vec1 - 3 = " << ptr2 <<std::endl;
    // std::cout << (it1 > it2) << std::endl;
    // std::cout << *it2 << std::endl;
    // A a(1, 'c');
    // A b(2, '2');
    // std::vector<A> vec;
    // vec.push_back(a);
    // vec.push_back(b);

    // std::vector<A>::iterator it1 = vec.begin();
    // // std::vector<A>::iterator it1 = vec.begin();
    // std::cout <<it1->b<< std::endl;

    return 0;
}