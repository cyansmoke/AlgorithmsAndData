#include "List.h"

template<class K>
List<K>::List() {
    head = nullptr;
    last = nullptr;
}

template<class K>
void List<K>::insert(K value) {
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

template<class K>
bool List<K>::compare(List *list1, List *list2) {
    bool flag = true;
    Node *tmpL1 = list1->head;
    Node *tmpL2 = list2->head;
    while (tmpL1 != nullptr && tmpL2 != nullptr) {
        if (tmpL1->data != tmpL2->data) {
            flag = false;
        }
        tmpL1 = tmpL1->next;
        tmpL2 = tmpL2->next;
    }
    return flag;
}


template<class K>
void List<K>::clear() {
    if (head != nullptr) {
        while (head != nullptr) {
            remove_last();
        }
    }
}

template<class K>
void List<K>::remove_last() {
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

