#ifndef LAB3_QUEUE_H
#define LAB3_QUEUE_H

#include "QueueNode.h"
#include "../Node.h"

template<class T>
class Queue {
private:
    QueueNode<T> *top;
    QueueNode<T> *end;
    int size;
public:
    Queue<T>() {
        top = nullptr;
        end = nullptr;
        size = 0;
    };

    ~Queue<T>() {
        while (get_size() != 0) {
            dequeue();
        }
    };

    int get_size() {
        return this->size;
    };

    void enqueue(T data) {
        QueueNode<T> *node = new QueueNode(data);
        if (top == nullptr && end == nullptr) {
            top = node;
            end = node;
        } else {
            end->set_prev(node);
            node->set_next(node);
            end = node;
        }
        size++;
    };

    T dequeue() {
        if (get_size() == 0) {
            throw "Queue is empty";
        } else if (get_size() == 1) {
            T data = top->get_data();
            delete (top);
            top = nullptr;
            end = nullptr;
            size--;
            return data;
        } else {
            T data = top->get_data();
            QueueNode<T> *thatNode = top;
            top = thatNode->get_prev();
            delete (thatNode);
            size--;
            return data;
        }
    };
};


#endif //LAB3_QUEUE_H
