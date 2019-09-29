#include "List.h"

List::List() {
    head = nullptr;
    tail = nullptr;
    size = 0;
}

List::~List() {
    head = nullptr;
    tail = nullptr;
}

/**
* insert first element with @param int data
*/
void List::add_first(int data) {
    EL1 *el1 = new EL1(data);
    head = el1;
    tail = el1;
};

/**
 * insert element with @param data into back of list
 */
void List::push_back(int data) {
    EL1 *el = new EL1(data);
    tail->set_next(el);
    tail = el;
}

/**
 * insert element with @param data into front of list
 */
void List::push_front(int data) {
    EL1 *el = new EL1(data);
    el->set_next(head);
    head = el;
}

/**
 * delete last element of list
 */
void List::pop_back() {
    EL1 *current = head;
    while (current->get_next() != tail) {
        current = current->get_next();
    }
    current->get_next()->~EL1();
    tail = current;
    tail->set_next(nullptr);
}

/**
 * delete first element of list
 */
void List::pop_front() {
    EL1 *current = head->get_next();
    head->~EL1();
    head = current;
}

/**
 * insert element at @param position with @param data
 */
void List::insert(int data, size_t position) {
    if (position == 0) {
        push_front(data);
    } else if (position == size - 1) {
        push_back(data);
    } else if (position >= size || position < 0) {
        //TODO(throw except)
    } else {
        EL1 *current = head;
        for (; position > 1; position--) {
            current = current->get_next();
        }
        EL1 *el = new EL1(data);
        el->set_next(current->get_next());
        current->set_next(el);
    }
}

/**
 * get element at @param position
 */
int List::at(size_t position) {
    if (position >= size ||  position < 0) {
        //TODO(throw except)
    }
    EL1 *current = head;
    for (; position > 0; position--) {
        current = current->get_next();
    }
    return current->get_data();
}

/**
 * delete element at @param position
 */
void List::remove(size_t position) {
    if (position >= size ||  position < 0) {
        //TODO(throw except)
    } else if (position == 0) {
        pop_front();
    } else if (position == size - 1) {
        pop_back();
    } else {
        EL1 *current = head;
        for(;position > 1; position--){
            current = current->get_next();
        }

        EL1 *prev = current;
        current = current->get_next();
        prev->set_next(current->get_next());
        current->~EL1();
    }
}

/**
 * get size of list
 * @return size_t
 */
size_t List::get_size() {
    return size;
}

/**
 * print list in console with divider
 */
void List::print_to_console() {

}

/**
 * delete all list data
 */
void List::clear() {

}

/**
 * set data of element at @param position to @param data
 */
void List::set(size_t position, int data) {

}

/**
 * check is list empty
 * @return bool
 */
bool List::isEmpty() {
    return this->size == 0;
}