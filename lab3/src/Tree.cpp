//
// Created by cyansmoke on 02.11.2019.
//

#include "Tree.h"

Tree::Tree(int root_data) {
    Node *root = new Node(root_data);
    this->root = root;
}

Node *find(Node *node, int key) {
    if (node == nullptr) {
        return nullptr;
    } else if (node->get_data() == key) {
        return node;
    } else if (key < node->get_data()) {
        find(node->get_left(), key);
    } else if (key > node->get_data()) {
        find(node->get_right(), key);
    }
}

void add(Node* node, int key){
    if(node->get_data() < key){

    }
}

bool Tree::contains(int key) {
    return find(root, key) != nullptr;
}

void Tree::insert(int key) {
    Node *newNode = new Node(key);

    if (root == nullptr) {
        root = newNode;
    } else {

    }
}
