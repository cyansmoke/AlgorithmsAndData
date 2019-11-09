#include "Node.h"

Node::Node(int data) {
    this->set_data(data);
}

Node::~Node() {
    this->set_left(nullptr);
    this->set_right(nullptr);
}

int Node::get_data() {
    return this->data;
}

void Node::set_data(int data) {
    this->data = data;
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