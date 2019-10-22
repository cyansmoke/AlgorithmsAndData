#ifndef LAB2_STACK_H
#define LAB2_STACK_H

#include "Node.h"

template<typename T>
class Stack {
private:
    int size = 0;
    Node<T> *top = nullptr;

public:
    /**
     * constructor
     */
    Stack<T>();

    /**
     * destructor
     */
    ~Stack<T>();

    /**
     * add element with @param data to stack
     */
    void push(T data);

    /**
     * remove top element
     * @return this element
     */
    Node<T>* pop();

    /**
     * return top element
     */
    Node<T>* peek();

    /**
     * return size of stack
     */
    int get_size();
};

#endif //LAB2_STACK_H
