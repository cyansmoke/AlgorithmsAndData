#include "gtest/gtest.h"
#include "../src/Flow.h"
#include "../src/Flow.cpp"

TEST(FlowTest, algorythmTest) {
    ASSERT_EQ(Flow("../data/algorythm_test.txt").maximalFlow(), 19);
}

TEST(FlowTest2, missingSymbolTest) {
    try {
        Flow("../data/missing_symbol_test.txt");
    } catch (const char *msg) {
        ASSERT_EQ(msg, "Missing node symbol error");
    }
}

TEST(FlowTest3, wrongDataTest) {
    try {
        Flow("../data/wrong_data_test.txt");
    } catch (const char *msg) {
        ASSERT_EQ(msg, "Entering data symbol error");
    }
}

TEST(FlowTest4, missingStringTest) {
    try {
        Flow("../data/missing_string_test.txt");
    } catch (const char *msg) {
        ASSERT_EQ(msg, "Missing node symbol error");
    }
}

TEST(FlowTest5, loopTest) {
    try {
        Flow("../data/loop_test.txt");
    } catch (const char *msg) {
        ASSERT_EQ(msg, "Data error");
    }
}

TEST(FlowTest6, missingSinkTest) {
    try {
        Flow("../data/missing_sink_test.txt");
    } catch (const char *msg) {
        ASSERT_EQ(msg, "Sink is missing");
    }
}

TEST(FlowTest7, missingSourceTest) {
    try {
        Flow("../data/missing_source_test.txt");
    } catch (const char *msg) {
        ASSERT_EQ(msg, "Source is missing");
    }
}