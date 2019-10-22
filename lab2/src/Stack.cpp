#include "Stack.h"

template<typename T>
Stack<T>::Stack() = default;

template<typename T>
Stack<T>::~Stack() {
    while (top != nullptr) {
        pop();
    }
    size = 0;
}

template<typename T>
void Stack<T>::push(T data) {
    Node<T> *node = new Node(data);
    node->set_next(top);
    top = node;
    size++;
}

template<typename T>
Node<T> *Stack<T>::pop() {
    Node<T> *temp = top;
    top = top->get_next();
    size--;
    return temp;
}

template<typename T>
Node<T> *Stack<T>::peek() {
    return top;
}

template<typename T>
int Stack<T>::get_size() {
    return size;
}