#ifndef LAB3_TREE_H
#define LAB3_TREE_H

#include "Node.h"

class Tree {

private:
    Node *root = NULL;
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
    //Iterator create_dft_iterator();

    /**
    * check contains element with data
    * @return true if contains else false
    */
    //Iterator create_bft_iterator()

    /**
    * check contains element with data
    * @return true if contains else false
    */
    void print();
};


#endif //LAB3_TREE_H
