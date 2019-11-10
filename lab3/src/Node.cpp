#include "Node.h"

Node::Node(int data) {
    this->set_key(data);
    this->set_left(NULL);
    this->set_right(NULL);
    this->set_height(1);
}

Node::~Node() {
    this->set_left(NULL);
    this->set_right(NULL);
}

int Node::get_height(){
    return this->height;
}

void Node::set_height(int height){
    this->height = height;
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