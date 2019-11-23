#include <stdexcept>
#include "TreeDftIterator.h"

TreeDftIterator::TreeDftIterator(Node *root) {
    queue = new Queue;
    dft(root);
}

void TreeDftIterator::dft(Node *start) {
    if (start) {
        queue->enqueue(start->get_key());
        dft(start->get_left());
        dft(start->get_right());
    }
}

bool TreeDftIterator::has_next() {
    return queue->get_size() != 0;
}

int TreeDftIterator::next() {
    if (!has_next()) {
        throw std::out_of_range("Hasn't next element");
    }

    return queue->dequeue();
}

TreeDftIterator::~TreeDftIterator() {
    delete queue;
}

