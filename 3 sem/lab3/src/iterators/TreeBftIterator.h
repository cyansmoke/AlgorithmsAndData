#ifndef LAB3_TREEBFTITERATOR_H
#define LAB3_TREEBFTITERATOR_H
#include "../Iterator.h"
#include "../Node.h"
#include "../queue/Queue.h"

class TreeBftIterator: public Iterator {
public:
    TreeBftIterator(Node *root);

    ~TreeBftIterator();

    Node* next() override;

    bool has_next() override;

    void dft(Node *node);
private:
    Queue<Node*>* queue;
};


#endif //LAB3_TREEBFTITERATOR_H
