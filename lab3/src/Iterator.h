#ifndef LAB3_ITERATOR_H
#define LAB3_ITERATOR_H

#include "Node.h"

class Iterator {
public:
    virtual Node* next() = 0;

    virtual bool has_next() = 0;
};


#endif //LAB3_ITERATOR_H
