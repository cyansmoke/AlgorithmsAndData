#include <iostream>
#include "backpack.h"

int main() {
    std::cout << "Hello, World!" << std::endl;
    Item items_list[] = {
            {"map",                    9,   150, 1},
            {"compass",                13,  35,  1},
            {"water",                  153, 200, 2},
            {"sandwich",               50,  60,  2},
            {"glucose",                15,  60,  2},
            {"tin",                    68,  45,  3},
            {"banana",                 27,  60,  3},
            {"apple",                  39,  40,  3},
            {"cheese",                 23,  30,  1},
            {"beer",                   52,  10,  3},
            {"suntan cream",           11,  70,  1},
            {"camera",                 32,  30,  1},
            {"T-shirt",                24,  15,  2},
            {"trousers",               48,  10,  2},
            {"umbrella",               73,  40,  1},
            {"waterproof trousers",    42,  70,  1},
            {"waterproof overclothes", 43,  75,  1},
            {"note-case",              22,  80,  1},
            {"sunglasses",             7,   20,  1},
            {"towel",                  18,  12,  2},
            {"socks",                  4,   50,  1},
            {"book",                   30,  10,  2},
    };

    Backpack *back = Backpack::collect_backpack(items_list, 400);
    back->print_result(items_list);
    return 0;
}
