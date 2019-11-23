#include <stdexcept>
#include "TreeDftIterator.h"

TreeDftIterator::TreeDftIterator(Node *root) {
    queue = new Queue<Node*>();
    dft(root);
}

TreeDftIterator::~TreeDftIterator() {
    delete queue;
}

void TreeDftIterator::dft(Node *start) {
    if (start) {
        queue->enqueue(start);
        dft(start->get_left());
        dft(start->get_right());
    }
}

bool TreeDftIterator::has_next() {
    return queue->get_size() != 0;
}

Node* TreeDftIterator::next() {
    if (!has_next()) {
        throw "Hasn't next element";
    }

    return queue->dequeue();
}

