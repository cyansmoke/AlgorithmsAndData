#include <gtest/gtest.h>
#include "../src/queue/QueueNode.cpp"

TEST(QueueNode_test, alltest){
    QueueNode* queueNode = new QueueNode(10);
    EXPECT_EQ(10, queueNode->get_data());
    QueueNode* queueNodePrev = new QueueNode(3);
    queueNode->set_prev(queueNodePrev);
    EXPECT_EQ(3, queueNode->get_prev()->get_data());
}
