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
    int size = 0;

    List();

    void insert(T value);

    void clear();

    void remove_last();

    bool compare(List *list1, List *list2);

    T at(int i);
};

#endif //ALGORITHMS_LIST_H
