#include "gtest/gtest.h"
#include "../src/item.cpp"

TEST(ItemTest, Item_Test) {
    Item item("key", 100, 1, 1);
    EXPECT_EQ("key", item.get_name());
    EXPECT_EQ(100, item.get_weight());
    EXPECT_EQ(1, item.get_value());
    EXPECT_EQ(1, item.get_count());
    try {
        Item item1("", 100, 1, 1);
    } catch (const char *msg) {
        EXPECT_EQ(msg, "Wrong item data");
    }
    try {
        Item item1("a", 0, 1, 1);
    } catch (const char *msg) {
        EXPECT_EQ(msg, "Wrong item data");
    }
    try {
        Item item1("a", 100, -1, 1);
    } catch (const char *msg) {
        EXPECT_EQ(msg, "Wrong item data");
    }
    try {
        Item item1("a", 100, 1, -1);
    } catch (const char *msg) {
        EXPECT_EQ(msg, "Wrong item data");
    }
}
