#ifndef MAP_H
#define MAP_H

#include "List.h"
#include <string>

template<class K, class V>
class Map {
private:
    struct Node {
        K key;
        V value;
        Node *parent;
        Node *left;
        Node *right;
        int color;
    };
    Node *root;
    Node *temp;
public:
    void left_rotate(Node *elem);

    void right_rotate(Node *elem);

    void insertion_fix(Node *elem);

    Map();

    ~Map();

    void clear();

    void insert(K key, V value);

    Node *find(K key);

    void transplant(Node *elem1, Node *elem2);

    Node *find_minimum(Node *elem);

    void remove(K key);

    void add_all_keys_to_list(List<K> *list, Node *elem);

    void add_all_values_to_list(List<V> *list, Node *elem);

    void deletion_fix(Node *elem);

    List<K> *get_keys();

    List<V> *get_values();

    void printElem(Node *elem, std::string str = "", std::string mod = " ");

    void print();
};

#endif //MAP_H
