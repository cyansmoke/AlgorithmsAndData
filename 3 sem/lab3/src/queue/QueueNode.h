#ifndef LAB3_QUEUENODE_H
#define LAB3_QUEUENODE_H

#include "../Node.h"

template<class T>
class QueueNode {
private:
    QueueNode<T> *next;
    QueueNode<T> *prev;
    T data;
public:
    QueueNode<T>(T data){
        this->data = data;
        this->next = nullptr;
        this->prev = nullptr;
    };

    void set_next(QueueNode<T> *node){
        this->next = node;
    };

    QueueNode<T> *get_prev(){
        return this->prev;
    };

    void set_prev(QueueNode<T> *node){
        this->prev = node;
    };

    T get_data(){
        return this->data;
    };
};


#endif //LAB3_QUEUENODE_H
