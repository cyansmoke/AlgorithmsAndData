#include "gtest/gtest.h"
#include "../src/Node.cpp"

TEST(Node_test, creation_test) {
    Node<int> *node = new Node(1);

    EXPECT_EQ(1, node->get_data());
    EXPECT_EQ(nullptr, node->get_next());
}

TEST(Node_test, set_get_test) {
    Node<int> *node1 = new Node(1);
    Node<int> *node2 = new Node(2);
    node1->set_data(2);
    node1->set_next(node2);

    EXPECT_EQ(node1->get_next()->get_data(), node2->get_data());
}