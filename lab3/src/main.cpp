#include <string>
#include <iostream>
#include "Floyd.h"
#include <fstream>

using namespace std;

int main() {
    ifstream input("../data/input_data.txt");
    auto *flightList = new List<string>();
    string city_Start;
    string city_End;

    while (!input.eof()) {
        string s1;
        getline(input, s1);
        flightList->insert(s1);
    }

    cout << "Flight schedule: " << endl;

    for (int i = 0; i < flightList->size; i++) {
        cout << flightList->at(i) << endl;
    }

    cout << endl << "Enter the departure city" << endl;

    getline(cin, city_Start);

    cout << "Enter your arrival city" << endl;

    getline(cin, city_End);

    auto *floyd = new Floyd(flightList);
    cout << floyd->calculate(city_Start, city_End) << endl;
}
