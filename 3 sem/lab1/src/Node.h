#pragma once

class Node {

public:
    Node(int data);

    ~Node();

    /**
     * @return int data of element
     */
    int get_data();

    /**
     * set element data to @param int
     */
    void set_data(int data);

    /**
     * @return next element
     */
    Node* get_next();

    /**
     * set next element
     */
    void set_next(Node* next);

private:
    int data;
    Node* next = nullptr;
};