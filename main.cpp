#include <iostream>

int main() {
    std::cout << "Hello, World!" << std::endl;
    return 0;
}

// How to create a node

template<typename T>
struct Node{
    T data;
    Node<T>* next;
    Node<T>* prev;
};

Node<T>* newNode = new Node<T>; //create a new node, n
