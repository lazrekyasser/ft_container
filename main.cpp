#include <iostream>
#include <memory>
#include <vector>

int main() {
    std::allocator<int> alloc;
    int *ptr = alloc.allocate(5);
    // *(ptr + 3) = 7;
    for (size_t i = 0; i < 5; i++) {
        alloc.construct(ptr + i, i);//construre un object dans cette address
        std::cout <<ptr[i]<< std::endl;
    }
    
    alloc.deallocate(ptr, 5);
    std::cout <<(ptr[5])<< std::endl;
    // std::cout <<*(--ptr)<< std::endl;
    return 0;
}