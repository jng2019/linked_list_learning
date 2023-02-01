//
// Created by jonat on 01/02/2023.
//
#ifndef LINKED_LIST_LEARNING_LINKEDLIST_CPP
#define LINKED_LIST_LEARNING_LINKEDLIST_CPP
#include "LinkedList.h"

template<typename S>
std::ostream &operator<<(std::ostream &out, const LinkedList<S> &list) {
    return <#initializer#>;
}

template<typename T>
bool LinkedList<T>::remove(const T &givenItem) {
    return false;
}

template<typename T>
void LinkedList<T>::insertAfrer(const T &givenTtem, const T &targetItem) {

}

template<typename T>
void LinkedList<T>::insertBefore(const T &givenItem, const T &targetItem) {

}

template<typename T>
bool LinkedList<T>::empty() const {
    return false;
}

template<typename T>
int LinkedList<T>::size() const {
    return 0;
}

template<typename T>
bool LinkedList<T>::empty() {
    return false;
}

template<typename T>
int LinkedList<T>::size() {
    return 0;
}

template<typename T>
T &LinkedList<T>::front() {
    return <#initializer#>;
}

template<typename T>
T &LinkedList<T>::back() {
    return <#initializer#>;
}

template<typename T>
void LinkedList<T>::pop_front() {

}

template<typename T>
void LinkedList<T>::pop_back() {

}

template<typename T>
void LinkedList<T>::push_back(const T &item) {

}

template<typename T>
void LinkedList<T>::push_front(const T &item) {

}

template<typename T>
LinkedList<T>& LinkedList<T>::operator=(const LinkedList<T> &copy) {
    return LinkedList<T>();
}

template<typename T>
LinkedList<T>::~LinkedList() {

}

template<typename T>
LinkedList<T>::LinkedList(const LinkedList<T> &copy) {

}

template<typename T>
LinkedList<T>::LinkedList() {

}

template<typename T>
void LinkedList<T>::addFirstNode(T data) {
    Node<T>* newNode = new Node<T>*;
    head=newNode;
    tail=newNode;
    newNode->data = data;
}

template<typename T>
void LinkedList<T>::insertAfter(Node<T> *insertThis, Node<T> *target) {

    insertBefore(insertThis, target->next);
}

template<typename T>
void LinkedList<T>::insertBefore(Node<T> *insertThis, Node<T> *target) {

    insertThis->next=target;
    insertThis->prev = target->prev;

    target->prev->next = insertThis;
    target->prev = insertThis;
}

template<typename T>
bool LinkedList<T>::remove(Node<T> *target) {

    // check edge cases


    // remove something in the middle with stuff on both sides
    target->next->prev = target->prev;
    target->prev->next = target->next;

    delete [] target;
}

template<typename T>
Node<T> *LinkedList<T>::createNode(T data, Node<T> *next, Node<T> *prev) {
    Node<T>* newNode = new Node<T>*;
    newNode->data = data;
    newNode->next=next;
    newNode->prev = prev;
    return nullptr;
}

template<typename T>
Node<T> *&LinkedList<T>::find(T item) {
    Node<T>* current = head;
    while(current != nullptr)
    {
        if (current->data==item)
        {
            return current;
        }
        current=current->next;
    }
    return nullptr;
}



#endif