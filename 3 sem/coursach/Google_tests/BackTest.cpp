#include "gtest/gtest.h"
#include "../src/backpack.cpp"

TEST(BackTest, collect_test) {
    Item items_list[] = {
            {"map", 9, 150, 1},
    };

    Backpack back1 = Backpack(items_list, 9);
    EXPECT_EQ(back1.get_items_result_map()[0], 1);
}

TEST(BackTest, throwable_test) {
    Item items_list[] = {
            {"map",        9,   150, 1},
            {"compass",    13,  35,  1},
            {"water",      153, 200, 2},
            {"sandwich",   50,  60,  2},
            {"glucose",    15,  60,  2},
            {"note-case",  22,  80,  1},
            {"sunglasses", 7,   20,  1},
            {"towel",      18,  12,  2},
            {"socks",      4,   50,  1},
            {"book",       30,  10,  2},
    };

    try {
        Backpack back = Backpack(items_list, -1);
    } catch (const char *msg) {
        EXPECT_EQ(msg, "Wrong max weight");
    }
}

TEST(BackTest, collect_test_2) {
    Item items_list[] = {
            {"map",        9,   150, 1},
            {"compass",    13,  35,  1},
            {"water",      153, 200, 2},
            {"sandwich",   50,  60,  2},
            {"glucose",    15,  60,  2},
            {"note-case",  22,  80,  1},
            {"sunglasses", 7,   20,  1},
            {"towel",      18,  12,  2},
            {"socks",      4,   50,  1},
            {"book",       30,  10,  2},
    };

    Backpack back2 = Backpack(items_list, 10);

    EXPECT_EQ(back2.get_items_result_map()[0], 1);
}

TEST(BackTest, collect_big_back) {
    Item items_list[] = {
            {"map",                 9,   150, 1},
            {"compass",             13,  35,  1},
            {"water",               15, 20, 20},
            {"sandwich",            50,  60,  2},
            {"glucose",             15,  60,  2},
            {"tin",                 68,  45,  3},
            {"banana",              27,  60,  3},
            {"apple",               39,  40,  3},
            {"cheese",              23,  30,  1},
            {"beer",                52,  10,  3},
            {"suntan cream",        11,  70,  1},
            {"camera",              32,  30,  1},
            {"T-shirt",             24,  15,  2},
            {"trousers",            48,  10,  2},
            {"umbrella",            73,  40,  1},
            {"waterproof trousers", 42,  70,  1},
            {"overclothes",         43,  75,  1},
            {"notebook",            22,  80,  1},
            {"sunglasses",          7,   20,  1},
            {"towel",               18,  12,  2},
            {"socks",               4,   50,  1},
            {"book",                30,  10,  2},
    };
    Backpack back = Backpack(items_list, 400);

    int result_weight = 0;

    for (int i = 0; i < ITEM_COUNT; i++) {
        result_weight += back.get_items_result_map()[i] * items_list[i].get_weight();
    }

    EXPECT_EQ(397, result_weight);
}
