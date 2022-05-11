//
//  Node.hpp
//  bsy_tickets
//
//  Created by Marco Schöttelkotte on 05.05.22.
//

#ifndef Node_hpp
#define Node_hpp

#include <stdio.h>


class Node {
public:
    int data;
    bool color;
    Node *left;
    Node *right;
    Node *parent;
    
    Node(int data);
    int getData();
};

#endif /* Node_hpp */
