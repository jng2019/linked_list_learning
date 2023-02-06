#include <iostream>
#include "LinkedList.h"

int main() {
    std::cout << "creating empty int linked list\n";
    LinkedList<int> list;


    std::cout << "testing push back and +-\n";
    list.push_back(2); // list = 2

    list.push_back(7);

    list += 3; // list = 2 3

    std::cout << list;
//
    std::cout << "testing push front\n";

    list.push_front(4); // list = 4 2 3
//
    std::cout << list;  // prints 4 2 3

    std::cout << "testing insert 6 before 2\n";
//
    list.insertBefore(6, 2); // list = 4 6 2 3
//
    std::cout << list;  // prints 4 6 2 3

    std::cout << "testing insert 7 after 6\n";
//
    list.insertAfter(7, 6); // list = 4 6 7 2 3
//
    std::cout << list;  // prints 4 6 7 2 3

    std::cout << "testing pop back and pop front\n";

    list.pop_back();

    list.pop_front();

    std::cout << list;

    std::cout << "testing front and back and size\n";

    std::cout << list.front() << " " << list.back() << " " << list.size() << std::endl;

    std::cout << "testing copy assignment operator\n";

    LinkedList<int> l2=list;

    std::cout << "testing pop back and pop front on l2\n";
    l2.pop_back();
    l2.pop_front();
    std::cout << l2;

    std::cout << "reprinting list\n";
    std::cout << list;

    std::cout << "deleting list and testing empty\n";
    std::cout << "printing list: " << list;
    list.~LinkedList<int>();
    if (list.empty())
        std::cout << "list is empty\n";
    else
        std::cout << "not empty\n";

    std::cout << "testing remove on l2\n";

    l2.remove(2);
    std::cout << l2;

    std::cout << "testing copy constructor l3\n";
    LinkedList<int> l3(l2);
    std::cout << "l3: " << l3;
    std::cout << "adding to l3\n";
    l3.insertBefore(3, 7);
    std::cout << "l3: " << l3;

    std::cout << "l2: " << l2;

}

// How to create a node


