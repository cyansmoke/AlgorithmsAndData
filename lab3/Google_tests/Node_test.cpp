#include "gtest/gtest.h"
#include "../src/Node.cpp"

TEST(Node_test, creation_test) {
    Node* node1 = new Node(10);
    EXPECT_EQ(node1->get_key(), 10);
    node1->set_key(13);
    EXPECT_EQ(node1->get_key(), 13);
    Node* node2 = new Node(11);
    Node* node3 = new Node(12);

    node1->set_right(node3);
    node1->set_left(node2);

    EXPECT_EQ(node1->get_right()->get_key(), 12);
    EXPECT_EQ(node1->get_left()->get_key(), 11);
}