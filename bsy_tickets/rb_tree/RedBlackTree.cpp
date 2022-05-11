//
//  RedBlackTree.cpp
//  bsy_tickets
//
//  Created by Marco Schöttelkotte on 05.05.22.
//
/*
#include <iostream>
#include "RedBlackTree.hpp"
#include "Node.hpp"

void RedBlackTree::rotateRight(Node node){
    Node *parent = node.parent;
    Node *leftChild = node.left;
    node.left = leftChild->right;
    
    if(leftChild->right != nullptr){
        leftChild->right->parent = &node;
    }
    leftChild->right = &node;
    node.parent = leftChild;
    
    RedBlackTree::replaceParentsChild(*parent, node, *leftChild);
}

void RedBlackTree::rotateLeft(Node node){
    Node *parent = node.parent;
    Node *rightChild = node.left;
    node.left = rightChild->right;
    
    if(rightChild->left != nullptr){
        rightChild->left->parent = &node;
    }
    rightChild->left = &node;
    node.parent = rightChild;
    
    RedBlackTree::replaceParentsChild(*parent, node, *rightChild);
}

void RedBlackTree::replaceParentsChild(Node parent, Node oldChild, Node newChild){
    if(&parent == NULL){
        root = newChild;
    }else if(parent.left == &oldChild){
        parent.left = &newChild;
    }else if(parent.right == &oldChild){
        parent.right == &newChild;
    }else {
        std::cout << "Node is not a child of its parent" << std::endl;
    }
    
    if(&newChild != NULL){
        newChild.parent = &parent;
    }
}

Node RedBlackTree::seachNode(<#int key#>){
    Node node = root;
    while(*node != NULL){
        
    }
}
*/
