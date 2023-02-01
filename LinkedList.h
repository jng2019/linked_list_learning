//
// Created by jonat on 01/02/2023.
//

#ifndef LINKED_LIST_LEARNING_LINKEDLIST_H
#define LINKED_LIST_LEARNING_LINKEDLIST_H

#include "Node.h"
#include <iostream>

template <typename T> // think about why it has to be template when node is already a tmeplate
class LinkedList {
private:
    Node<T> *head= nullptr, *tail = nullptr;
    // creates a node in dynamic memeory and returns its address location

    Node<T>* createNode(T data, Node<T>* next = nullptr, Node<T>* prev = nullptr);

    // returns the address of a node containing item, otherwise return nullptr
    Node<T>*& find(T item);

    // remove the target node passed to it
    bool remove(Node<T>* target);

    // add the given node before the target node
    void insertBefore(Node<T>* insertThis, Node<T>* target);
    // think about why the given node needs to be a node pointer instead of just a node

    // add the given node after the target node
    void insertAfter(Node<T>* insertThis, Node<T>* target);

    // adds the very first node in the list
    void addFirstNode(T data);
public:

    LinkedList();
    LinkedList(const LinkedList<T>& copy);
    ~LinkedList();
    LinkedList<T>& operator=(const LinkedList<T>& copy);

    void push_back(const T& item);

    void push_front(const T& item);

    void pop_back();

    void pop_front();

    // returns the last item in the list (item can be modified)

    T& back();

    T& front();

    int size() const;

    bool empty() const;

    // insert the given item before a node containing the target item
    void insertBefore(const T& givenItem, const T& targetItem);

    void insertAfrer(const T& givenTtem, const T& targetItem);

    bool remove(const T& givenItem);

    template<typename S>
    friend std::ostream&  operator<<(std::ostream& out, const LinkedList<S>& list);
    // friend functions need their own template because they aren't part of the class
};



#include "LinkedList.h"
#endif //LINKED_LIST_LEARNING_LINKEDLIST_H
