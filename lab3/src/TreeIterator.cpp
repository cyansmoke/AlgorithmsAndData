//
// Created by cyansmoke on 03.11.2019.
//

#include "TreeIterator.h"


bool TreeIterator::has_next() {
    return current != nullptr;
}

int TreeIterator::next() {
    if (!has_next()) {
        throw "End of tree";
    }


}