#include <stdexcept>
#include "TreeBftIterator.h"

TreeBftIterator::TreeBftIterator(Node *start) {
    queue = new Queue<Node*>();
    queue->enqueue(start);
}

bool TreeBftIterator::has_next() {
    return queue->get_size() != 0;
}

Node* TreeBftIterator::next() {
    if (!has_next()) {
        throw "Hasn't next element";
    }

    Node *next_node = queue->dequeue();
    if (next_node->get_right()) {
        queue->enqueue(next_node->get_right());
    }
    if (next_node->get_left()) {
        queue->enqueue(next_node->get_left());
    }

    return next_node;
}

TreeBftIterator::~TreeBftIterator() {
    delete queue;
}
