#include "gtest/gtest.h"
#include "../src/queue/Queue.h"

TEST(Queue_test, queue_alltest) {
    Queue<int> queue;

    queue.enqueue(10);

    EXPECT_EQ(queue.get_size(), 1);

    EXPECT_EQ(10, queue.dequeue());

    try {
        queue.dequeue();
    } catch (const char *msg) {
        EXPECT_EQ("Queue is empty", msg);
    }

    queue.enqueue(10);
    queue.enqueue(11);
    queue.enqueue(12);
    queue.enqueue(13);

    EXPECT_EQ(queue.get_size(), 4);
    EXPECT_EQ(10, queue.dequeue());
    EXPECT_EQ(11, queue.dequeue());
    EXPECT_EQ(12, queue.dequeue());
    EXPECT_EQ(13, queue.dequeue());
    EXPECT_EQ(queue.get_size(), 0);
}