//
//  RedBlackTree.hpp
//  bsy_tickets
//
//  Created by Marco Schöttelkotte on 05.05.22.
//
/*
#ifndef RedBlackTree_hpp
#define RedBlackTree_hpp

#include <stdio.h>
#include "Node.hpp"
class RedBlackTree {
public:
    Node seachNode(int key);
private:
    void rotateRight(Node node);
    void replaceParentsChild(Node parent, Node oldChild, Node newChild);
    void rotateLeft(Node node);
};

#endif /* RedBlackTree_hpp */
