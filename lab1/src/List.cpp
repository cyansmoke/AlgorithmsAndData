#include "List.h"

List::List() = default;

List::~List() {
    clear();
}

void List::add_first(int data) {
    Node *node = new Node(data);
    head = node;
    tail = node;
    size++;
};

void List::push_back(int data) {
    if (size == 0) {
        add_first(data);
    } else {
        Node *node = new Node(data);
        tail->set_next(node);
        tail = node;
        size++;
    }
}

void List::push_front(int data) {
    if (size == 0) {
        add_first(data);
    } else {
        Node *node = new Node(data);
        node->set_next(head);
        head = node;
        size++;
    }
}

void List::pop_back() {
    Node *current = head;
    while (current->get_next() != tail) {
        current = current->get_next();
    }
    current->get_next()->~Node();
    delete (current->get_next());
    tail = current;
    tail->set_next(nullptr);
    size--;
}

void List::pop_front() {
    Node *current = head->get_next();
    head->~Node();
    delete (head);
    head = current;
    size--;
}

void List::insert(int data, int position) {
    if (position > size || position < 0) {
        throw "Out of bounds";
    } else if (position == size) {
        push_back(data);
    } else if (position == 0) {
        push_front(data);
    } else {
        Node *current = head;
        for (; position > 1; position--) {
            current = current->get_next();
        }
        Node *node = new Node(data);
        node->set_next(current->get_next());
        current->set_next(node);
        size++;
    }
}

int List::at(int position) {
    if (position >= size || position < 0) {
        throw "Out of bounds";
    }
    Node *current = head;
    for (; position > 0; position--) {
        current = current->get_next();
    }
    return current->get_data();
}

void List::remove(int position) {
    if (position >= size || position < 0) {
        throw "Out of bounds";
    } else if (position == 0) {
        pop_front();
    } else if (position == size - 1) {
        pop_back();
    } else {
        Node *current = head;
        for (; position > 1; position--) {
            current = current->get_next();
        }

        Node *prev = current;
        current = current->get_next();
        prev->set_next(current->get_next());
        current->~Node();
        delete (current);
        size--;
    }
}

size_t List::get_size() {
    return size;
}

void List::print_to_console() {
    Node *current = head;
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
            Node *temp = head->get_next();
            head->~Node();
            delete (head);
            head = temp;
        } while (head != nullptr);
        tail = nullptr;
        size = 0;
    }
}

void List::set(int position, int data) {
    if (position >= size || position < 0) {
        throw "Out of bounds";
    }
    Node *current = head;
    for (; position > 0; position--) {
        current = current->get_next();
    }
    current->set_data(data);
}

bool List::isEmpty() {
    return this->size == 0;
}

void List::push_front(List list) {
    if (list.isEmpty()) throw "List is empty";
    for (int i = list.size - 1; i >= 0; i--) {
        this->push_front(list.at(i));
    }
}