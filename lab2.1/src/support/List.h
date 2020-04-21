#pragma once
using namespace std;

template<typename T>
class List {
private:
    class Node {
    public:
        T data;
        Node *next, *prev;
    public:
        Node() : next(NULL), prev(NULL) {};

        ~Node() {
            next = NULL;
            prev = NULL;
        }

        void setData(T data) {
            this->data = data;
        }

        T getData() {
            return data;
        }

        Node *getNext() {
            return next;
        }

        Node *getPrev() {
            return prev;
        }

        void setNext(Node *pointer) {
            next = pointer;
        }

        void setPrev(Node *pointer) {
            prev = pointer;
        }
    };

    Node *head, *tail;

    Node *getPointerOfIndex(size_t index) {
        if (isEmpty() || (index > getSize() - 1)) {
            throw "Invalid argument";
        } else if (index == getSize() - 1)
            return tail;
        else if (index == 0)
            return head;
        else {
            Node *temp = head;
            while ((temp) && (index--)) {
                temp = temp->getNext();
            }
            return temp;
        }
    }

public:
    List() : head(NULL), tail(NULL) {}

    List(int size, int value) {
        while (size--) {
            insertLast(value);
        }
    }

    List(const List<T> &list) {
        head = NULL;
        tail = NULL;
        Node *temp = list.head;
        while (temp) {
            insertLast(temp->getData());
            temp = temp->getNext();
        }
    }

    ~List() {
        while (head) {
            tail = head->getNext();
            delete head;
            head = tail;
        }
        head = NULL;
    }

    void insertLast(T data) {
        Node *temp = new Node;
        temp->setData(data);
        if (head) {
            temp->setPrev(tail);
            tail->setNext(temp);
            tail = temp;
        } else {
            head = temp;
            tail = head;
        }
    }

    void insertFirst(T data) {
        Node *temp = new Node;
        temp->setData(data);
        if (head) {
            temp->setNext(head);
            head->setPrev(temp);
            head = temp;
        } else {
            head = temp;
            tail = head;
        }
    }

    bool compare(List<T> ls) {
        if (getSize() != ls.getSize())
            return false;
        for (int i = 0; i < getSize(); i++) {
            if (getDataAt(i) != ls.getDataAt(i))
                return false;
        }
        return true;
    }

    void deleteLast() {
        if (head != tail) {
            Node *temp = tail;
            tail = tail->getPrev();
            tail->setNext(NULL);
            delete temp;
        } else if (!isEmpty()) {
            Node *temp = tail;
            tail = head = NULL;
            delete temp;
        } else
            throw "The List is empty";
    }

    void pop_front() {
        if (head != tail) {
            Node *temp = head;
            head = head->getNext();
            head->setPrev(NULL);
            delete temp;
        } else if (!isEmpty()) {
            Node *temp = head;
            head = tail = NULL;
            delete temp;
        } else
            throw "The List is empty";
    }

    void insertAt(size_t index, T data) {
        Node *temp;
        temp = getPointerOfIndex(index);
        if (temp == head)
            insertFirst(data);
        else {
            Node *newElem = new Node;
            newElem->setData(data);
            temp->getPrev()->setNext(newElem);
            newElem->setPrev(temp->getPrev());
            newElem->setNext(temp);
            temp->setPrev(newElem);
        }
    }

    T getDataAt(size_t index) {
        Node *temp;
        temp = getPointerOfIndex(index);
        return temp->getData();
    }

    void removeAt(size_t index) {
        Node *temp;
        temp = getPointerOfIndex(index);
        if (temp == head)
            pop_front();
        else if (temp == tail)
            deleteLast();
        else {
            temp->getPrev()->setNext(temp->getNext());
            temp->getNext()->set_prev(temp->getPrev());
            delete temp;
        }
    }

    void remove(T data) {
        Node *temp = head;
        while (temp && temp->getData() != data)
            temp = temp->getNext();
        if (!temp)
            throw out_of_range("Invalid argument");
        if (temp == head)
            pop_front();
        else if (temp == tail)
            deleteLast();
        else {
            temp->getPrev()->setNext(temp->getNext());
            temp->getNext()->set_prev(temp->getPrev());
            delete temp;
        }
    }

    size_t getSize() {
        Node *temp = head;
        size_t length = 0;
        while (temp) {
            length++;
            temp = temp->getNext();
        }
        return length;
    }

    void print() {
        Node *temp = head;
        while (temp) {
            cout << temp->getData();
            temp = temp->getNext();
        }
    }

    void clear() {
        while (head) {
            tail = head->getNext();
            delete head;
            head = tail;
        }
    }

    void set(size_t index, T data) {
        Node *temp;
        temp = getPointerOfIndex(index);
        temp->setData(data);
    }

    bool isEmpty() {
        return head == NULL;
    }

    void insertListInBack(List<bool> ls2) {
        Node *temp = ls2.head;
        size_t n = ls2.getSize();
        while ((temp) && (n--)) {
            insertLast(temp->getData());
            temp = temp->getNext();
        }
    }

    void insertAndSort(char data1, float data2) {
        if (!head || head->data.second < data2) {
            insertFirst(pair<char, float>(data1, data2));
            return;
        }
        Node *newElem = new Node;
        newElem->data = pair<char, float>(data1, data2);
        int i = 0;
        Node *temp = head;
        while (temp) {
            if (temp->data.second < data2) {
                temp->getPrev()->setNext(newElem);
                newElem->setPrev(temp->getPrev());
                temp->setPrev(newElem);
                newElem->setNext(temp);
                return;
            }
            if (temp->data.first == data1 && temp->data.second == data2) {
                delete newElem;
                return;
            }
            i++;
            temp = temp->getNext();
        }
        delete newElem;
        insertLast(pair<char, float>(data1, data2));
    }
};