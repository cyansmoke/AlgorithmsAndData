#pragma once

#include "Flow.h"

Flow::~Flow() {
    delete[] flowArray;
    delete[] height;
    for (int i = 0; i < nodeCount; ++i) {
        delete[] capacity[i];
    }
}

int Flow::findMaxFlow() {
    if (nodeCount > 2) {
        for (int i = 0; i < nodeCount; i++) {
            if (i == sourceNode) {
                continue;
            }
            flowArray[i] = capacity[sourceNode][i];
            capacity[i][sourceNode] += capacity[sourceNode][i];
        }

        height[sourceNode] = nodeCount;
        List<int> supportList;
        int current;
        int currentIndex = 0;
        int oldHeight;

        for (int i = 0; i < nodeCount; i++) {
            if (i != sourceNode && i != sinkNode) {
                supportList.pushFront(i);
            }
        }

        current = supportList.at(0);

        while (currentIndex < supportList.getSize()) {
            oldHeight = height[current];
            dump(current);
            if (height[current] != oldHeight) {
                supportList.pushFront(current);
                supportList.remove(++currentIndex);
                current = supportList.at(0);
                currentIndex = 0;
            }
            currentIndex++;
            if (currentIndex < supportList.getSize()) {
                current = supportList.at(currentIndex);
            }

        }
        return flowArray[sinkNode];
    } else {
        return capacity[0][1];
    }
}

void Flow::readFromFile(ifstream &inputFile) {
    auto *cardCharNumber = new Map<char, int>();
    nodeCount = 0;
    while (!inputFile.eof()) {
        string data;
        getline(inputFile, data);
        if (data.size() >= 5) {
            if (!((data[0] >= 'A' && data[0] <= 'Z') && (data[1] == ' ')) ||
                !((data[2] >= 'A' && data[2] <= 'Z') && (data[3] == ' '))) {
                throw "Missing node symbol error";
            }
            string cur;
            for (int i = 4; i < data.size(); ++i) {
                if (data[i] >= '0' && data[i] <= '9')
                    cur += data[i];
                else {
                    throw "Entering data symbol error";
                }
            }

            try {
                cardCharNumber->find(data[0]);
            } catch (const char *msg) {
                cardCharNumber->insert(data[0], nodeCount);
                nodeCount++;
            }

            try {
                cardCharNumber->find(data[2]);
            } catch (const char *msg) {
                cardCharNumber->insert(data[2], nodeCount);
                nodeCount++;
            }

        } else {
            throw "Data error";
        }
    }
    try {
        sourceNode = cardCharNumber->find('S')->value;
    } catch (const char *msg) {
        throw "Source is missing";
    }

    try {
        sinkNode = cardCharNumber->find('T')->value;
    } catch (const char *msg) {
        throw "Sink is missing";

    }
    inputFile.clear();

    flowArray = new int[nodeCount];
    height = new int[nodeCount];
    capacity = new int *[nodeCount];

    for (int i = 0; i < nodeCount; i++) {
        flowArray[i] = 0;
        height[i] = 0;
    }

    for (int i = 0; i < nodeCount; i++) {
        capacity[i] = new int[nodeCount];
        for (int j = 0; j < nodeCount; j++)
            capacity[i][j] = 0;
    }

    inputFile.seekg(ios::beg);
    while (!inputFile.eof()) {
        string data;
        int firstNode, secondNode;
        getline(inputFile, data);
        firstNode = cardCharNumber->find(data[0])->value;
        secondNode = cardCharNumber->find(data[2])->value;
        if (firstNode == secondNode) {
            throw "The path in loop";
        }

        capacity[firstNode][secondNode] = stoi(data.substr(4));
    }
}

void Flow::push(int edge, int node) {
    int pushVar = flowArray[edge] > capacity[edge][node] ? capacity[edge][node] : flowArray[edge];
    flowArray[edge] -= pushVar;
    flowArray[node] += pushVar;
    capacity[edge][node] -= pushVar;
    capacity[node][edge] += pushVar;
}

void Flow::bringUp(int edge) {
    int min = 2 * nodeCount + 1;
    for (int i = 0; i < nodeCount; i++) {
        if (capacity[edge][i] && (height[i] < min)) {
            min = height[i];
        }
    }
    height[edge] = min + 1;
}

void Flow::dump(int edge) {
    int node = 0;
    while (flowArray[edge] > 0) {
        if (capacity[edge][node] && height[edge] == height[node] + 1) {
            push(edge, node);
            node = 0;
            continue;
        }
        node++;
        if (node == nodeCount) {
            bringUp(edge);
            node = 0;
        }
    }
}

