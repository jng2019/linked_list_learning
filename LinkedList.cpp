//
// Created by jonat on 01/02/2023.
//
#ifndef LINKED_LIST_LEARNING_LINKEDLIST_CPP
#define LINKED_LIST_LEARNING_LINKEDLIST_CPP
#include "LinkedList.h"

template<typename S>
std::ostream &operator<<(std::ostream &out, const LinkedList<S> &list) {
    Node<S>* current;
    current = list.head;
    while (current!= nullptr) {
        std::cout << current->data << " ";
        current=current->next;
    }
    std::cout << std::endl;
    return out;
}

template<typename T>
bool LinkedList<T>::remove(const T &givenItem) {
    Node<T>* target = find(givenItem);
    return remove(target);
}

template<typename T>
void LinkedList<T>::insertAfrer(const T &givenTtem, const T &targetItem) {

    insertBefore(createNode(givenTtem), find(targetItem));
}

template<typename T>
void LinkedList<T>::insertBefore(const T &givenItem, const T &targetItem) {
    insertAfter(createNode(givenItem), find(targetItem));
}

template<typename T>
bool LinkedList<T>::empty() const {
    return head==nullptr;
}

template<typename T>
int LinkedList<T>::size() const {
    int size =0;
    Node<T>* current = head;
    while (current!= nullptr)
    {
        size++;
        current=current->next;
    }
    return size;
}


template<typename T>
T &LinkedList<T>::front() {
    return head->data;
}

template<typename T>
T &LinkedList<T>::back() {
    return tail->data;
}

template<typename T>
void LinkedList<T>::pop_front() {

}

template<typename T>
void LinkedList<T>::pop_back() {

}

template<typename T>
void LinkedList<T>::push_back(const T &item) {
    if (head== nullptr)
        createNode(item);

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

    // check adding to the very front and the very back
    insertThis->next=target;
    insertThis->prev = target->prev;

    target->prev->next = insertThis;
    target->prev = insertThis;
}

template<typename T>
bool LinkedList<T>::remove(Node<T> *target) {


    // check edge cases
    if(target==head)
    {
        head=target->next;

    }


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