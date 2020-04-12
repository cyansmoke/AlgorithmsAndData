#ifndef ALGORITHMS_LIST_H
#define ALGORITHMS_LIST_H

template<class T>
class List {
    int size;
public:
    struct Node {
        T data;
        Node *next;
    };

    Node *last;
    Node *head;

    List();

    void insert(T value);

    void clear();

    void remove_last();

    bool compare(List *list1, List *list2);

    int get_size();

    Node *get_head() {
        return head;
    }

    Node *get_last() {
        return last;
    }
};

#endif //ALGORITHMS_LIST_H
