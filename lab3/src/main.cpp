#include <iostream>
#include "Tree.h"

int main() {
    Tree tree(10);
    tree.insert_node(16);
    tree.insert_node(9);
    tree.insert_node(8);
    tree.print();
    cout << tree.contains(10) << endl;
    tree.remove_node(10);
    cout << tree.contains(10) << endl;
    tree.print();
    tree.insert_node(20);
    tree.insert_node(18);
    tree.insert_node(21);
    tree.print();
    TreeDftIterator iterator = tree.create_dft_iterator();
    TreeBftIterator it2 = tree.create_bft_iterator();
    while (iterator.has_next()) {
        cout << iterator.next()->get_key() << " ";
    }

    cout << endl;

    while (it2.has_next()) {
        cout << it2.next()->get_key() << " ";
    }

    return 0;
}