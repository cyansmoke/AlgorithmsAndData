#include "QueueNode.h"

QueueNode::QueueNode(int data) {
    this->data = data;
    this->next = nullptr;
    this->prev = nullptr;
}

int QueueNode::get_data() {
    return this->data;
}

void QueueNode::set_next(QueueNode *node) {
    this->next = node;
}

QueueNode* QueueNode::get_prev() {
    return this->prev;
}

void QueueNode::set_prev(QueueNode *node) {
    this->prev = node;
}