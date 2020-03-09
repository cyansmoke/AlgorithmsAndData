#ifndef LAB3_TREEITERATOR_H
#define LAB3_TREEITERATOR_H

#include "../Iterator.h"
#include "../queue/Queue.h"
#include "../Node.h"

class TreeDftIterator : public Iterator {

public:
    TreeDftIterator(Node *root);

    ~TreeDftIterator();

    Node* next() override;

    bool has_next() override;

    void dft(Node *node);
private:
    Queue<Node*>* queue;
};


#endif //LAB3_TREEITERATOR_H
