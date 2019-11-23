#include "gtest/gtest.h"
#include "../src/Tree.cpp"
#include "../src/iterators/TreeBftIterator.cpp"
#include "../src/iterators/TreeDftIterator.cpp"
#include "../src/iterators/TreeBftIterator.h"
#include "../src/iterators/TreeDftIterator.h"

TEST(Tree_test, creation_insert_remove_contains_test) {
    Tree tree(10);
    tree.insert_node(9);
    tree.insert_node(11);
    EXPECT_EQ(tree.contains(9), 1);
    EXPECT_EQ(tree.contains(10), 1);
    EXPECT_EQ(tree.contains(11), 1);
    tree.remove_node(10);
    EXPECT_EQ(tree.contains(10), 0);
}

TEST(Tree_test, bft) {
    Tree tree(10);
    tree.insert_node(9);
    tree.insert_node(11);
    tree.insert_node(13);
    TreeBftIterator iterator = tree.create_bft_iterator();
    EXPECT_EQ(iterator.next()->get_key(), 10);
    EXPECT_EQ(iterator.next()->get_key(), 11);
    EXPECT_EQ(iterator.next()->get_key(), 9);
    EXPECT_EQ(iterator.next()->get_key(), 13);

    try {
        iterator.next();
    } catch (const char* msg){
        EXPECT_EQ(msg, "Hasn't next element");
    }

}

TEST(Tree_test, dft) {
    Tree tree(10);
    tree.insert_node(9);
    tree.insert_node(11);
    tree.insert_node(13);

    TreeDftIterator iterator = tree.create_dft_iterator();
    EXPECT_EQ(iterator.next()->get_key(), 10);
    EXPECT_EQ(iterator.next()->get_key(), 9);
    EXPECT_EQ(iterator.next()->get_key(), 11);
    EXPECT_EQ(iterator.next()->get_key(), 13);

    try {
        iterator.next();
    } catch (const char* msg){
        EXPECT_EQ(msg, "Hasn't next element");
    }
}