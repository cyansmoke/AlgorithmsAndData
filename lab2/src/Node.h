#ifndef LAB2_NODE_H
#define LAB2_NODE_H

template<typename T>

class Node {
private:
    T data;
    Node<T> *next = nullptr;

public:
    /**
     * constructor
     */
    Node<T>(T data);

    /**
     * destructor
     */
    ~Node<T>();

    /**
     * return data of element
     */
    T get_data();

    /**
    * set next element
    */
    void set_next(Node<T> *next);

    /**
    * set data of element
    */
    void set_data(T data);

    /**
     * @return pointer to next element
     */
    Node<T> *get_next();
};


#endif //LAB2_NODE_H
