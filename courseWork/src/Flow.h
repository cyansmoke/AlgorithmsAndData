#pragma once

#include <fstream>
#include "List.h"
#include <string>
#include "map.h"

using namespace std;

class Flow {
private:
    int *flowArray;
    int **capacity;
    int *height;
    int nodeCount;
    int sourceNode;
    int sinkNode;
public:
    Flow(string path) {
        ifstream input(path);
        readFromFile(input);
    }

    ~Flow();

    int findMaxFlow();

    void readFromFile(ifstream &inputFile);

    void push(int edge, int node);

    void bringUp(int edge);

    void dump(int edge);
};