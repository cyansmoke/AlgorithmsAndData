#include "List.h"

template<class T>
List<T>::List() {
    head = nullptr;
    last = nullptr;
}

template<class T>
void List<T>::insert(T value) {
    Node *elem = new Node;
    elem->data = value;
    if (head == nullptr) {
        head = elem;
        last = elem;
        elem->next = nullptr;
    } else {
        last->next = elem;
        last = elem;
    }
}

template<class T>
void List<T>::clear() {
    if (head != nullptr) {
        while (head != nullptr) {
            delete_last();
        }
    }
}

template<class T>
void List<T>::delete_last() {
    if (head == nullptr) {
        throw "Error, the List is empty";
    }
    Node *tmp_ptr = head;
    if (tmp_ptr->next == nullptr) {
        delete tmp_ptr;
        head = nullptr;
        last = nullptr;
    } else {
        while (tmp_ptr->next != last) {
            tmp_ptr = tmp_ptr->next;
        }
        tmp_ptr->next = nullptr;
        delete last;
        last = tmp_ptr;
    }
}

