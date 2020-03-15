#include "map.h"
#include "List.h"
#include "List.cpp"
#include <iostream>

template<class K, class V>
Map<K, V>::Map() {
    NIL = new Node;
    NIL->parent = nullptr;
    NIL->color = 0;
    NIL->left = nullptr;
    NIL->right = nullptr;
    root = NIL;
    root->parent = NIL;
}

template<class K, class V>
void Map<K, V>::insert(K key, V value) {
    Node *elem = new Node;
    elem->key = key;
    elem->value = value;
    Node *y = NIL;
    Node *x = root;
    while (x != NIL) {
        y = x;
        if (elem->key < x->key) {
            x = x->left;
        } else {
            x = x->right;
        }
    }
    elem->parent = y;
    if (y == NIL) {
        root = elem;
    } else if (elem->key < y->key) {
        y->left = elem;
    } else {
        y->right = elem;
    }
    elem->left = NIL;
    elem->right = NIL;
    elem->color = 1;
    insertion_fix(elem);
}

template<class K, class V>
void Map<K, V>::left_rotate(Node *elem) {
    Node *y = elem->right;
    elem->right = y->left;
    if (y->left != NIL) {
        y->left->parent = elem;
    }
    y->parent = elem->parent;
    if (elem->parent == NIL) {
        root = y;
    } else if (elem == elem->parent->left) {
        elem->parent->left = y;
    } else {
        elem->parent->right = y;
    }
    y->left = elem;
    elem->parent = y;
}

template<class K, class V>
void Map<K, V>::right_rotate(Node *elem) {
    Node *y = elem->left;
    elem->left = y->right;
    if (y->right != NIL) {
        y->right->parent = elem;
    }
    y->parent = elem->parent;
    if (elem->parent == NIL) {
        root = y;
    } else if (elem == elem->parent->right) {
        elem->parent->right = y;
    } else {
        elem->parent->left = y;
    }
    y->right = elem;
    elem->parent = y;
}

template<class K, class V>
void Map<K, V>::insertion_fix(Node *elem) {
    Node *y = nullptr;
    while (elem->parent->color == 1) {
        if (elem->parent == elem->parent->parent->left) {
            y = elem->parent->parent->right;
            if (y->color == 1) {
                elem->parent->color = 0;
                y->color = 0;
                elem->parent->parent->color = 1;
                elem = elem->parent->parent;
            } else {
                if (elem == elem->parent->right) {
                    elem = elem->parent;
                    left_rotate(elem);
                }
                elem->parent->color = 0;
                elem->parent->parent->color = 1;
                right_rotate(elem->parent->parent);
            }
        } else {
            y = elem->parent->parent->left;
            if (y->color == 1) {
                elem->parent->color = 0;
                y->color = 0;
                elem->parent->parent->color = 1;
                elem = elem->parent->parent;
            } else {
                if (elem == elem->parent->left) {
                    elem = elem->parent;
                    right_rotate(elem);
                }
                elem->parent->color = 0;
                elem->parent->parent->color = 1;
                left_rotate(elem->parent->parent);
            }
        }
    }
    root->color = 0;
}

template<class K, class V>
typename Map<K, V>::Node *Map<K, V>::find(K key) {
    Node *elem = root;
    while (elem != NIL) {
        if (elem->key == key) {
            break;
        }
        if (key < elem->key) {
            elem = elem->left;
        } else {
            elem = elem->right;
        }
    }
    if (elem != NIL) {
        return elem;
    } else {
        throw "Key does not exist in array";
    }
}

template<class K, class T1>
void Map<K, T1>::transplant(Node *elem1, Node *elem2) {
    if (elem1->parent == NIL) {
        root = elem2;
    } else if (elem1 == elem1->parent->left) {
        elem1->parent->left = elem2;
    } else {
        elem1->parent->right = elem2;
    }
    elem2->parent = elem1->parent;
}

template<class T, class T1>
typename Map<T, T1>::Node *Map<T, T1>::find_minimum(Node *elem) {
    while (elem->left != NIL) {
        elem = elem->left;
    }
    return elem;
}

template<class T, class T1>
void Map<T, T1>::remove(T key) {
    Node *elem = find(key);
    Node *x = nullptr;
    Node *y = elem;
    int org_color = y->color;
    if (elem->left == NIL) {
        x = elem->right;
        transplant(elem, elem->right);
    } else if (elem->right == NIL) {
        x = elem->left;
        transplant(elem, elem->left);
    } else {
        y = find_minimum(elem->right);
        org_color = y->color;
        x = y->right;
        if (y->parent == elem) {
            x->parent = y;
        } else {
            transplant(y, y->right);
            y->right = elem->right;
            y->right->parent = y;
        }
        transplant(elem, y);
        y->left = elem->left;
        y->left->parent = y;
        y->color = elem->color;
        if (org_color == 0) {
            deletion_fix(x);
        }
    }
}

template<class K, class V>
void Map<K, V>::deletion_fix(Map::Node *elem) {
    Node *w = nullptr;
    while (elem != NIL && elem->color == 0) {
        if (elem == elem->parent->left) {
            w = elem->parent->right;
            if (w->color == 1) {
                w->color = 0;
                elem->parent->color = 1;
                left_rotate(elem->parent);
                w = elem->parent->right;
            }
            if (w->left->color == 0 && w->right->color == 0) {
                w->color = 1;
                elem = elem->parent;
            } else if (w->right->color == 0) {
                w->left->color = 0;
                w->color = 1;
                right_rotate(w);
                w = elem->parent->right;

            }
            w->color = elem->parent->color;
            elem->parent->color = 0;
            w->right->color = 0;
            left_rotate(elem->parent);
            elem = root;
        } else {
            w = elem->parent->left;
            if (w->color == 1) {
                w->color = 0;
                elem->parent->color = 1;
                right_rotate(elem->parent);
                w = elem->parent->left;
            }
            if (w->right->color == 0 && w->left->color == 0) {
                w->color = 1;
                elem = elem->parent;
            } else if (w->left->color == 0) {
                w->right->color = 0;
                w->color = 1;
                left_rotate(w);
                w = elem->parent->left;

            }
            w->color = elem->parent->color;
            elem->parent->color = 0;
            w->left->color = 0;
            right_rotate(elem->parent);
            elem = root;
        }
    }
}

template<class K, class V>
void Map<K, V>::clear() {
    while (root != NIL) {
        remove(root->key);
    }
    delete NIL;
}

template<class K, class V>
Map<K, V>::~Map() {
    while (root != NIL) {
        remove(root->key);
    }
    delete NIL;
}

template<class K, class V>
void Map<K, V>::add_all_keys_to_list(List<K> *list, Node *elem) {
    if (elem != NIL) {
        add_all_keys_to_list(list, elem->left);
        list->insert(elem->key);
        add_all_keys_to_list(list, elem->right);
    }

}

template<class K, class V>
void Map<K, V>::add_all_values_to_list(List<V> *list, Node *elem) {
    if (elem != NIL) {
        add_all_values_to_list(list, elem->left);
        list->insert(elem->value);
        add_all_values_to_list(list, elem->right);
    }

}

template<class K, class V>
List<K> *Map<K, V>::get_keys() {
    auto *list = new List<K>;
    add_all_keys_to_list(list, root);
    return list;
}

template<class K, class V>
List<V> *Map<K, V>::get_values() {
    auto *list = new List<V>;
    add_all_values_to_list(list, root);
    return list;
}

template<class T, class T1>
void Map<T, T1>::printElem(Node *elem, std::string str, std::string mod) {
    if (elem == root) {
        std::cout << +"+-" << elem->key << "(" << elem->value << ")" << std::endl;
    } else {
        std::cout << str + mod << elem->key << "(" << elem->value << ")" << std::endl;
    }
    str += "|  ";
    if (elem->left != NIL) printElem(elem->left, str, "L-");
    if (elem->right != NIL) printElem(elem->right, str, "R-");;
}

template<class K, class V>
void Map<K, V>::print() {
    printElem(root);
}