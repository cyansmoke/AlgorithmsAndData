#ifndef LAB3_QUEUENODE_H
#define LAB3_QUEUENODE_H

class QueueNode {
private:
    QueueNode *next;
    QueueNode *prev;
    int data;
public:
    QueueNode(int data);

    void set_next(QueueNode *node);

    QueueNode *get_prev();

    void set_prev(QueueNode *node);

    int get_data();
};


#endif //LAB3_QUEUENODE_H
