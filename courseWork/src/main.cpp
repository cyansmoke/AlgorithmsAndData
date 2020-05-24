#include <iostream>
#include <fstream>
#include "Flow.h"

int main() {
    Flow graph("../data/input_data.txt");
    std::cout << "Max flow: " << graph.findMaxFlow();
}