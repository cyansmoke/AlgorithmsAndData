#ifndef LAB3_QUEUE_H
#define LAB3_QUEUE_H

#include "QueueNode.h"

class Queue {
private:
    QueueNode *top;
    QueueNode *end;
    int size;
public:
    Queue();

    ~Queue();

    int get_size();

    void enqueue(int data);

    int dequeue();
};


#endif //LAB3_QUEUE_H
