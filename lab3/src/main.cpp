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
    TreeDftIterator iterator = tree.create_dft_iterator();
    while (iterator.has_next()){
        cout << iterator.next()<< " ";
    }
    return 0;
}