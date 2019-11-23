#ifndef LAB3_TRUNK_H
#define LAB3_TRUNK_H

#include <string>
#include "../Node.h"
#include <iostream>

using namespace std;

struct Trunk {
    Trunk *prev;
    string str;

    Trunk(Trunk *prev, string str) {
        this->prev = prev;
        this->str = str;
    }
};

#endif //LAB3_TRUNK_H
