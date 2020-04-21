#include "gtest/gtest.h"
#include "../src/Encoder.h"

TEST(ENCODER_TEST, encodeTest) {
    Encoder encoder;
    String exampleStr = "it is test string";
    encoder.setStringForShannon(exampleStr);
    List<bool> list = example.getEncodedString();
    String encodedString = "111011101111011001001110011101001001011100010000";
    for (int i = 0; i < list.getSize(); i++) {
        outString += list.getDataAt(i) ? "1" : "0";
    }
    ASSERT_EQ(encodedString, outString);
}

TEST(TREE_TEST, decodeTest) {
    String exampleStr = "it is test string";
    Encoder encoder;
    encoder.setStringForShannon(exampleStr);
    List<char> list = example.decode("111011101111011001001110011101001001011100010000");
    for (int i = 0; i < list.getSize(); i++) {
        outString += list.getDataAt(i);
    }
    ASSERT_EQ(exampleStr, outString);
}