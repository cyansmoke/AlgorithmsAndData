//
// Created by cyansmoke on 03.11.2019.
//

#include "Iterator.cpp"

#ifndef LAB3_TREEITERATOR_H
#define LAB3_TREEITERATOR_H


class TreeIterator : public Iterator {

public:
    TreeIterator(Node *root) {
        current = root;
        right = current->get_right();
        left = current->get_left();
    }

    int next() override;

    bool has_next() override;

private:
    Node *current;
    Node *left;
    Node *right;
};


#endif //LAB3_TREEITERATOR_H
