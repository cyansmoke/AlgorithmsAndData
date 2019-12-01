#ifndef COURSACH_BACKPACK_H
#define COURSACH_BACKPACK_H

#include "item.h"
#include "Constants.h"

class Backpack {
private:
    int items_result_map[ITEM_COUNT];
public:
    static Backpack* collect_backpack(Item[], int);

    void print_result(Item[]);
};


#endif //COURSACH_BACKPACK_H
