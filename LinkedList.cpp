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
void LinkedList<T>::insertAfter(const T &givenItem, const T &targetItem) {

    insertAfter(createNode(givenItem), find(targetItem));
}

template<typename T>
void LinkedList<T>::insertBefore(const T &givenItem, const T &targetItem) {
    insertBefore(createNode(givenItem), find(targetItem));

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
    remove(head);
}

template<typename T>
void LinkedList<T>::pop_back() {
    remove(tail);
}

template<typename T>
void LinkedList<T>::push_back(const T &item) {
    if (head== nullptr) {
        createNode(item);
    }
    else
        insertAfter(createNode(item), tail);
}

template<typename T>
void LinkedList<T>::push_front(const T &item) {
    if (head== nullptr)
        createNode(item);
    else
        insertBefore(createNode(item), head);
}

template<typename T>
LinkedList<T>& LinkedList<T>::operator=(const LinkedList<T> &copy) {
    if (this==&copy)
        return *this;

    while(!empty())
    {
        pop_back();
    }

    Node<T>* current;
    current = copy.head;
    while(current!= nullptr)
    {
        push_back(current->data);
        current=current->next;
    }
    delete [] current;
    return *this;
}

template<typename T>
LinkedList<T>::~LinkedList() {
    while(!empty())
    {
        pop_back();
    }
}

template<typename T>
LinkedList<T>::LinkedList(const LinkedList<T> &copy) {
    *this=copy;
}

template<typename T>
LinkedList<T>::LinkedList() {

}

template<typename T>
void LinkedList<T>::addFirstNode(T data) {
    createNode(data);
}

template<typename T>
void LinkedList<T>::insertAfter(Node<T> *insertThis, Node<T> *target) {
    if(target==tail)
    {

        Node<T>* newNode = new Node<T>();
        newNode->data = insertThis->data;
        newNode->next= nullptr;
        newNode->prev = tail;
        tail->next=newNode;
        tail = newNode;
    }
    else
        insertBefore(insertThis, target->next);
}

template<typename T>
void LinkedList<T>::insertBefore(Node<T> *insertThis, Node<T> *target) {

    if (target==head)
    {
        Node<T> *n = new Node<T>();
        n->data = insertThis->data;
        n->next = head;
        n->prev = nullptr;
        head->prev = n;
        head = n;
    }
    // check adding to the very front and the very back of the list
    else
    {
        insertThis->next = target;
        insertThis->prev = target->prev;

        target->prev->next = insertThis;
        target->prev = insertThis;
    }
}

template<typename T>
bool LinkedList<T>::remove(Node<T> *target) {


    if (head==tail && head!= nullptr) // only one thing in list
    {
        head= nullptr;
        tail= nullptr;
        delete [] target;
        return true;
    }
    // check edge cases
    else if(target==head) // deleting first element
    {
        head=target->next;
        head->prev= nullptr;
        delete [] target;
        return true;
    }
    else if (target==tail) // deleting last element
    {
        tail=target->prev;
        tail->next= nullptr;
        delete [] target;
        return true;
    }

    else if (target!= nullptr)// remove something in the middle with stuff on both sides
    {
        target->next->prev = target->prev;
        target->prev->next = target->next;
        delete [] target;
        return true;
    }

    return false;
}

template<typename T>
Node<T>* LinkedList<T>::createNode(T data, Node<T> *next, Node<T> *prev) {
    Node<T> *newNode = new Node<T>();
    newNode->data = data;
    newNode->next=next;
    newNode->prev = prev;
    if(head== nullptr)
    {
        head=newNode;
        tail=newNode;
    }
    return newNode;
}

template<typename T>
Node<T> *LinkedList<T>::find(T item) {
    Node<T> *current;
    current=head;
    while(current != nullptr)
    {
        if (current->data==item)
        {
            return current;
        }
        current=current->next;
    }
    current=nullptr;
    return current;
}

template<typename T>
LinkedList<T> &LinkedList<T>::operator+=(const T &item) {
    push_back(item);
    return *this;
}


#endif