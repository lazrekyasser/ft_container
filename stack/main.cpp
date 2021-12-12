#include "ft_stack.hpp"
#include <vector>
#include <stack>

int main() {
    NAME_SPACE::stack<int> stack;
    stack.push(21);
    stack.push(22);
    stack.push(24);
    stack.push(25);
     
    stack.pop();
    stack.pop();
 
    while (!stack.empty()) {
        std::cout << ' ' << stack.top();
        stack.pop();
    }
    return 0;
}