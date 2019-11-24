#include "gtest/gtest.h"
#include "../Algorithms.cpp"

TEST(SortTest, binary_search) {
    int arr[] = {1, 3, 7, 15, 18, 20, 25, 33, 36, 40};
    int n = sizeof(arr) / sizeof(arr[0]);
    int b = binarySearch(arr, 0, n - 1, 33);
    EXPECT_EQ(b, 7);
}

TEST(SortTest, quickSort) {
    int arr[] = {3, 29, 28, 11, 1, 2, 257, 335, 3666, 4};
    int sortedArr[] = {1, 2, 3, 4, 11, 28, 29, 257, 335, 3666};
    int n = sizeof(arr) / sizeof(arr[0]);
    quickSort(arr, 0, n);
    for (int i = 0; i < n; i++) {
        EXPECT_EQ(arr[i], sortedArr[i]);
    }
}

TEST(SortTest, insertionSort) {
    int arr[] = {3, 29, 28, 11, 1, 2, 257, 335, 3666, 4};
    int sortedArr[] = {1, 2, 3, 4, 11, 28, 29, 257, 335, 3666};
    int n = sizeof(arr) / sizeof(arr[0]);
    insertionSort(arr, n);
    for (int i = 0; i < n; i++) {
        EXPECT_EQ(arr[i], sortedArr[i]);
    }
}

TEST(SortTest, bogosort) {
    int arr[] = {3, 29, 28};
    int sortedArr[] = {3, 28, 29};
    int n = sizeof(arr) / sizeof(arr[0]);
    bogosort(arr, n);
    for (int i = 0; i < n; i++) {
        EXPECT_EQ(arr[i], sortedArr[i]);
    }
}

TEST(SortTest, countSort) {
    char arr[] = {'e', 'a', 'b', 'y', 'a'};
    char sortedArr[] = {'a', 'a', 'b', 'e', 'y'};
    int n = sizeof(arr) / sizeof(arr[0]);
    countSort(arr);
    for (int i = 0; i < n; i++) {
        EXPECT_EQ(arr[i], sortedArr[i]);
    }
}

int main(int argc, char **argv) {
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}