#include <iostream>
using namespace std;

struct Node {
    int data;
    Node* next;
};

Node* Enqueue(const int val, Node* start) {
    Node* newnode = new Node;
    newnode->data = val;

if (start == NULL) {
    newnode->next = newnode;
    return newnode;
}

Node* last = start->next;
while (last->next != start){
    last = last->next;
}
newnode->next = start;
last->next = newnode;
return start;
}

Node* Dequeue(Node* start){
    if (start == NULL){
        return NULL;
}
if (start->next == start){
    delete start;
    return NULL;
}

Node* second = start->next;
Node* last = start;
while (last->next != start){
    last = last->next;
}
last->next = second;
delete start;
return second;
}

int Front(Node* start) {
    if (start == NULL){
        cout << "Queue is empty:" << endl;
        return -1;
    }
    return start->data;
}

int Size(Node* start){
    if (start == NULL){
        return 0;
    }
int count = 1;
Node* curr = start->next;
while (curr != start){
    count++;
    curr = curr->next;
    }
    return count;
}

void Print(Node* start){
    if (start == NULL){
        cout << "Queue is empty:" << endl;
        return;
    }
Node* curr = start;
do{
    cout << curr->data << " ";
    curr = curr->next;
    } while (curr != start);
        std::cout << std::endl;
}

int main() {
Node* start = NULL;
start = Enqueue(1, start);
start = Enqueue(2, start);
start = Enqueue(3, start);
start = Enqueue(23, start);
start = Enqueue(12, start);
start = Enqueue(2004, start);
std::cout << "Queue size: " << Size(start) << std::endl;
std::cout << "Front element: " << Front(start) << std::endl;
Print(start);
start = Dequeue(start);
std::cout << "Queue size after dequeue: " << Size(start) << std::endl;
std::cout << "Front element after dequeue: " << Front(start) << std::endl;
Print(start);
return 0;
}

