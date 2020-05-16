#include "gtest/gtest.h"
#include "../src/Floyd.h"

TEST(Floyd_test, has_route_test) {
    ifstream input("../data/input_data.txt");
    List<string>* flightList = new List<string>();
    string city_Start = "Barselona";
    string city_End = "Saint-Petersburg";
    InputDataFromFile(flightList, input);
    Floyd* floyd = new Floyd(flightList);
    string result = "The best route for the price:\n29\nBarselona - Saint-Petersburg";
    ASSERT_EQ(floyd->calculate(city_Start, city_End), result);
}

TEST(Floyd_test, has_not_route) {
    ifstream input("../data/input_data.txt");
    List<string>* flightList = new List<string>();
    string city_Start = "Rome";
    string city_End = "Nalchik";
    InputDataFromFile(flightList, input);
    Floyd* floyd = new Floyd(flightList);
    string result = "The departure city is absent, try again";
    ASSERT_EQ(floyd->calculate(city_Start, city_End), result);
}