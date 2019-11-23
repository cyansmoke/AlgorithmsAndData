#ifndef LAB3_TREE_H
#define LAB3_TREE_H

#include "iterators/TreeDftIterator.h"
#include "iterators/TreeBftIterator.h"
#include "Node.h"
#include <iostream>

using namespace std;

class Tree {

private:
    Node *root = nullptr;
public:

    Tree(int root_data);

    ~Tree();

    /**
     * check contains element with data
     * @return true if contains else false
     */
    bool contains(int);

    /**
    * add element with data into tree
    */
    void insert_node(int);

    /**
    * remove element with data
    */
    void remove_node(int);

    /**
    * check contains element with data
    */
    TreeDftIterator create_dft_iterator();

    /**
    * check contains element with data
    * @return true if contains else false
    */
    TreeBftIterator create_bft_iterator();

    /**
    * check contains element with data
    * @return true if contains else false
    */
    void print();
};


#endif //LAB3_TREE_H
