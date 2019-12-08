#include <iostream>
#include "backpack.h"

int main() {
    Item items_list[] = {
            {"map",        9,  150, 1},
            {"compass",    13, 35,  1},
            {"water",      15, 20,  20},
            {"sandwich",   50, 60,  2},
            {"glucose",    15, 60,  2},
            {"note-case",  22, 80,  1},
            {"sunglasses", 7,  20,  1},
            {"towel",      18, 12,  2},
            {"socks",      4,  50,  1},
            {"book",       30, 10,  2},
    };

    Backpack back = Backpack(items_list, 100);
    back.print_result(items_list);

    return 0;
}
