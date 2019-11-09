#include "gtest/gtest.h"
#include "../src/Stack.cpp"

TEST(Stack_test, peek_pop_test) {
    Stack<int> stack;
    stack.push(2);
    EXPECT_EQ(stack.peek()->get_data(), 2);

    EXPECT_EQ(stack.pop()->get_data(), 2);

    EXPECT_EQ(stack.get_size(), 0);

    try {
        stack.pop();
    } catch (const char *msg) {
        EXPECT_EQ(msg, "Stack is empty");
    }

    try {
        stack.peek();
    } catch (const char *msg) {
        EXPECT_EQ(msg, "Stack is empty");
    }
}