#ifndef ALGORITHMS_LIST_H
#define ALGORITHMS_LIST_H

template<class T>
class List {
    struct Node {
        T data;
        Node *next;
    };
    Node *last;
    Node *head;
public:
    List();

    void insert(T value);

    void clear();

    void delete_last();
};

#endif //ALGORITHMS_LIST_H
