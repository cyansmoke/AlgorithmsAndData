#pragma once

#include<iostream>

using namespace std;

template<class T>
class List {
private:
    class Node {
    public:
        Node(T data = T(), Node *Next = NULL) {
            this->data = data;
            this->next = Next;
        }

        Node *next;
        T data;
    };

    Node *head;
    Node *tail;
    int size;

public:
    List(Node *head = NULL, Node *tail = NULL, int size = 0) : head(head), tail(tail), size(size) {}

    ~List() {
        if (head != NULL) {
            this->clear();
        }
    };

    void pushBack(T elem) {
        if (head != NULL) {
            this->tail->next = new Node(elem);
            tail = tail->next;
        } else {
            this->head = new Node(elem);
            this->tail = this->head;
        }
        size++;
    }

    void pushFront(T elem) {
        if (head != NULL) {
            Node *current = new Node;
            current->data = elem;
            current->next = this->head;
            this->head = current;
        } else {
            this->head = new Node(elem);
            tail = head;
        }
        this->size++;
    }

    void popBack() {
        if (head != NULL) {
            Node *current = head;
            while (current->next != tail)
                current = current->next;
            delete tail;
            tail = current;
            tail->next = NULL;
            size--;
        } else throw "Out of range";
    }

    void popFront() {
        if (head != NULL) {
            Node *current = head;
            head = head->next;
            delete current;
            size--;
        } else throw "Out of range";
    }

    T at(int k) {
        if (this->head != NULL && k >= 0 && k <= this->size - 1) {
            if (k == 0)
                return this->head->data;
            else if (k == this->size - 1)
                return this->tail->data;
            else {
                Node *current = head;
                for (int i = 0; i < k; i++) {
                    current = current->next;
                }
                return current->data;
            }
        } else {
            throw "Out of range";
        }
    }

    void remove(int k) {
        if (head != NULL && k >= 0 && k <= size - 1) {
            if (k == 0) this->popFront();
            else if (k == this->size - 1) this->popBack();
            else {
                Node *current = head;
                for (int i = 0; i < k - 1; i++) {
                    current = current->next;
                }

                Node *current1 = current->next;
                current->next = current->next->next;
                delete current1;
                size--;
            }
        } else {
            throw "Out of range";
        }
    }

    int getSize() {
        return size;
    }

    void clear() {
        if (head != NULL) {
            Node *current = head;
            while (head != NULL) {
                current = current->next;
                delete head;
                head = current;
            }
            size = 0;
        }
    }
};
