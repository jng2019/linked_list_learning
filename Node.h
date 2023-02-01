//
// Created by jonat on 01/02/2023.
//

#ifndef LINKED_LIST_LEARNING_NODE_H
#define LINKED_LIST_LEARNING_NODE_H

template<typename T>
struct Node{
    T data;
    Node<T>* next= nullptr, *prev= nullptr;
};

#endif //LINKED_LIST_LEARNING_NODE_H
