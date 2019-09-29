#include "List.h"

List::List() {}

List::~List() {
    head = nullptr;
    tail = nullptr;
    size = 0;
}

void List::add_first(int data) {
    EL1 *el1 = new EL1(data);
    head = el1;
    tail = el1;
    size++;
};

void List::push_back(int data) {
    if (size == 0) {
        add_first(data);
    } else {
        EL1 *el = new EL1(data);
        tail->set_next(el);
        tail = el;
        size++;
    }
}

void List::push_front(int data) {
    if (size == 0) {
        add_first(data);
    } else {
        EL1 *el = new EL1(data);
        el->set_next(head);
        head = el;
        size++;
    }
}

void List::pop_back() {
    EL1 *current = head;
    while (current->get_next() != tail) {
        current = current->get_next();
    }
    current->get_next()->~EL1();
    delete (current->get_next());
    tail = current;
    tail->set_next(nullptr);
    size--;
}

void List::pop_front() {
    EL1 *current = head->get_next();
    head->~EL1();
    delete (head);
    head = current;
    size--;
}

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
        size++;
    }
}

int List::at(size_t position) {
    if (position >= size || position < 0) {
        //TODO(throw except)
    }
    EL1 *current = head;
    for (; position > 0; position--) {
        current = current->get_next();
    }
    return current->get_data();
}

void List::remove(size_t position) {
    if (position >= size || position < 0) {
        //TODO(throw except)
    } else if (position == 0) {
        pop_front();
    } else if (position == size - 1) {
        pop_back();
    } else {
        EL1 *current = head;
        for (; position > 1; position--) {
            current = current->get_next();
        }

        EL1 *prev = current;
        current = current->get_next();
        prev->set_next(current->get_next());
        current->~EL1();
        delete (current);
        size--;
    }
}

size_t List::get_size() {
    return size;
}

void List::print_to_console() {
    EL1 *current = head;
    using namespace std;
    if (!isEmpty()) {
        cout << "[";
        do {
            cout << current->get_data();
            if (current->get_next() != nullptr) cout << ",";
            current = current->get_next();
        } while (current != nullptr);
        cout << "]" << endl;
    } else {
        cout << "list is empty" << endl;
    }
}

void List::clear() {
    if (!isEmpty()) {
        do {
            EL1 *temp = head->get_next();
            head->~EL1();
            delete (head);
            head = temp;
        } while (head != nullptr);
        tail = nullptr;
        size = 0;
    }
}

void List::set(size_t position, int data) {
    if (position >= size || position < 0) {
        //TODO(throw except)
    }
    EL1 *current = head;
    for (; position > 0; position--) {
        current = current->get_next();
    }
    current->set_data(data);
}

bool List::isEmpty() {
    return this->size == 0;
}

void List::push_front(List list) {
    list.tail->set_next(head);
    head = list.head;
    list.tail = tail;
    size = list.size + size;
}