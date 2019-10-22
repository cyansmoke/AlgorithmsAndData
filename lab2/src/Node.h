#ifndef LAB2_NODE_H
#define LAB2_NODE_H

template<typename T>

class Node {
private:
    T data;
    Node<T> *next;

public:
    /**
     * return data of element
     */
    T get_data();

     /**
     * set data of element
     */
    void set_next(Node *next);

    /**
     * @return pointer to next element
     */
    Node *get_next();

};


#endif //LAB2_NODE_H
