#include "Node.h"

Node::Node(int data) {
    this->set_key(data);
    this->set_left(nullptr);
    this->set_right(nullptr);
}

Node::~Node() {
    this->set_left(nullptr);
    this->set_right(nullptr);
}

int Node::get_key() {
    return this->key;
}

void Node::set_key(int key) {
    this->key = key;
}

Node *Node::get_left() {
    return this->left;
}

Node *Node::get_right() {
    return this->right;
}

void Node::set_left(Node *left) {
    this->left = left;
}

void Node::set_right(Node *right) {
    this->right = right;
}