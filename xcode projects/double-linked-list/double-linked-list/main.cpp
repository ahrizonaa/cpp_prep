//
//  main.cpp
//  double-linked-list
//
//  Created by Mark Garcia on 2/3/23.
//

#include <iostream>
#include "Classes.hpp"
int main(int argc, const char * argv[]) {
    
    DoubleLinkedList* dll = new DoubleLinkedList(1);
    dll->append(5);
    dll->prepend(3);
    dll->print();
    
    return 0;
}
