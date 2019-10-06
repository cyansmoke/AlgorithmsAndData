#pragma once

#include "Node.h"

class List {
public:
    List();

    ~List();

    /**
     * insert element with @param data into back of list
     */
    void push_back(int data);

    /**
     * insert element with @param data into front of list
     */
    void push_front(int data);

    /**
     * delete last element of list
     */
    void pop_back();

    /**
     * delete first element of list
     */
    void pop_front();

    /**
     * insert element at @param position with @param data
     */
    void insert(int data, size_t position);

    /**
     * get element at @param position
     */
    int at(size_t position);

    /**
     * delete element at @param position
     */
    void remove(size_t position);

    /**
     * get size of list
     * @return size_t
     */
    size_t get_size();

    /**
     * print list in console with divider
     */
    void print_to_console();

    /**
     * delete all list data
     */
    void clear();

    /**
     * set data of element at @param position to @param data
     */
    void set(size_t position, int data);

    /**
     * check is list empty
     * @return bool
     */
    bool isEmpty();

    /**
     * insert list in another list;
     * @return bool
     */
    void push_front(List list);

private:
    int size = 0;
    Node *head = nullptr;
    Node *tail = nullptr;

    /**
     * insert first element with @param data
     */
    void add_first(int data);
};