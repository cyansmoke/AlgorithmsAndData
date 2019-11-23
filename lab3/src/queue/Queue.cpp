#include "Queue.h"

Queue::Queue() {
    top = nullptr;
    end = nullptr;
    size = 0;
}

int Queue::get_size() {
    return this->size;
}

void Queue::enqueue(int data) {
    QueueNode *node = new QueueNode(data);
    if (top == nullptr && end == nullptr) {
        top = node;
        end = node;
    } else {
        end->set_prev(node);
        node->set_next(end);
        end = node;
    }
    size++;
}

int Queue::dequeue() {
    if (get_size() == 0) {
        throw "Queue is empty";
    } else if (get_size() == 1) {
        int data = top->get_data();
        delete (top);
        top = nullptr;
        end = nullptr;
        size--;
        return data;
    } else {
        int data = top->get_data();
        QueueNode *thatNode = top;
        top = thatNode->get_prev();
        delete (thatNode);
        size--;
        return data;
    }
}

Queue::~Queue() {
    while (get_size() != 0) {
        dequeue();
    }
}