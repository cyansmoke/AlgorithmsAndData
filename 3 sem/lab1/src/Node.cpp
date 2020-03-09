#include "Node.h"

Node::Node(int data) : data(data) {
    this->set_data(data);
}

Node::~Node() {
    this->data = -1;
    this->set_next(nullptr);
}

int Node::get_data(){
    return this->data;
}

void Node::set_data(int data) {
    this->data = data;
}

Node* Node::get_next() {
    return this->next;
}

void Node::set_next(Node* next) {
    this->next = next;
}

