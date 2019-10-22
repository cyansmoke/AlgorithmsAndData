#include "Node.h"
template<typename T>

Node<T>::Node(T data) : data(data) {
    this->set_data(data);
}

template<typename T>
Node<T>::~Node() {
    this->set_next(nullptr);
}

template<typename T>
T Node<T>::get_data() {
    return this->data;
}

template<typename T>
void Node<T>::set_data(T data) {
    this->data = data;
}

template<typename T>
Node<T> *Node<T>::get_next() {
    return this->next;
}

template<typename T>
void Node<T>::set_next(Node<T> *next) {
    this->next = next;
}
