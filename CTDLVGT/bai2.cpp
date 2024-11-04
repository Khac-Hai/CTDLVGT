#include <iostream>
#include <queue>
#include <stack>

int SearchStack(std::stack<int> &stack, std::queue<int> &queue, const int n) {
    std::stack<int> tempstack = stack; 
    int pos = -1;
    int count = 0;

    
    while (!tempstack.empty()) {
        if (tempstack.top() == n) {
            pos = count; 
            break; 
        }
        tempstack.pop(); 
        count++; 
    }

    
    while (!tempstack.empty()) {
        queue.push(tempstack.top()); 
        tempstack.pop();
    }
    while (!queue.empty()) {
        stack.push(queue.front()); 
        queue.pop();
    }
    return pos; 
}

int main() {
    std::stack<int> stack;
    std::queue<int> queue;

    
    stack.push(10);
    stack.push(20);
    stack.push(30);
    stack.push(40);
    stack.push(50);
    stack.push(60);
    stack.push(70);
    stack.push(80);
    stack.push(90);

    int searchValue = 50;

    int pos = SearchStack(stack, queue, searchValue);

    if (pos != -1) {
        std::cout << "Phan tu " << searchValue << " duoc tim thay tai vi tri " << pos << " tren ngan xep.\n";
    } else {
        std::cout << "Khong tim thay phan tu " << searchValue << " tren ngan xep.\n";
    }

    return 0;
}
