#pragma once

#include "map.cpp"
#include <string>
#include <iostream>

using namespace std;

class Floyd {

public:
    Floyd(List<string> *data) {
        mapNameIndex = new Map<string, int>();
        mapIndexName = new Map<int, string>();

        int N = data->size;
        int cityIndex = 0;

        for (int i = 0; i < N; i++) {
            string str_cur = data->at(i);

            int cur = str_cur.find(';');
            int cur1 = str_cur.find(';', cur + 1);

            string firstCityName = str_cur.substr(0, cur);
            string secondCityName = str_cur.substr(cur + 1, cur1 - cur - 1); //get second city

            secondCityName.erase(0, 1);

            try {
                mapNameIndex->find(firstCityName);
            } catch (const char *msg) {
                mapNameIndex->insert(firstCityName, cityIndex);
                mapIndexName->insert(cityIndex, firstCityName);
                cityIndex++;
            }

            try {
                mapNameIndex->find(secondCityName);
            } catch (const char *msg) {
                mapNameIndex->insert(secondCityName, cityIndex);
                mapIndexName->insert(cityIndex, secondCityName);
                cityIndex++;
            }
        }
        matrixSize = cityIndex;

        matrix = new double *[matrixSize];

        for (int i = 0; i < matrixSize; i++) {
            matrix[i] = new double[matrixSize];
        }

        for (int i = 0; i < matrixSize; i++) {
            for (int j = 0; j < matrixSize; j++) {
                matrix[i][j] = INF;
            }
        }

        for (int i = 0; i < N; i++) {
            int priceTo = INF;
            int priceBack = INF;

            string str_cur = data->at(i);

            int cur = str_cur.find(';');
            int cur1 = str_cur.find(';', cur + 1);
            int cur2 = str_cur.find(';', cur1 + 1);
            int cur3 = str_cur.find(';', cur2 + 1);

            string str_name_city1 = str_cur.substr(0, cur);
            string str_name_city2 = str_cur.substr(cur + 1, cur1 - cur - 1);

            str_name_city2.erase(0, 1);

            if (str_cur.substr(cur1 + 2, cur2 - 2 - cur1) != "N/A") {
                priceTo = stof(str_cur.substr(cur1 + 2, cur2 - 2 - cur1));
            }

            if (str_cur.substr(cur2 + 2, cur3 - 1) != "N/A") {
                priceBack = stof(str_cur.substr(cur2 + 2, cur3 - 2 - cur2));
            }

            matrix[mapNameIndex->find(str_name_city1)->value][mapNameIndex->find(
                    str_name_city2)->value] = priceTo;

            matrix[mapNameIndex->find(str_name_city2)->value][mapNameIndex->find(
                    str_name_city1)->value] = priceBack;

        }

    }

    string calculate(string departureCity, string arrivalCity) {
        string cur;

        while (true) {
            try {
                mapNameIndex->find(departureCity);
                break;
            } catch (const char *err) {
                cout << "The departure city is absent, try again" << endl;
                cin >> departureCity;
            }
        }

        while (true) {
            try {
                mapNameIndex->find(arrivalCity);
                break;
            } catch (const char *msg) {
                cout << "The arrival city is missing, enter it again" << endl;
                cin >> arrivalCity;
            }
        }

        int startIndex = mapNameIndex->find(departureCity)->value;
        int endIndex = mapNameIndex->find(arrivalCity)->value;

        int **temp = new int *[matrixSize];

        for (int i = 0; i < matrixSize; i++) {
            temp[i] = new int[matrixSize];
            for (int j = 0; j < matrixSize; j++) {
                temp[i][j] = i;
            }
        }

        for (int k = 0; k < matrixSize; ++k) {
            for (int i = 0; i < matrixSize; ++i) {
                for (int j = 0; j < matrixSize; ++j) {
                    if (matrix[i][k] + matrix[k][j] < matrix[i][j]) {
                        matrix[i][j] = matrix[i][k] + matrix[k][j];
                        temp[i][j] = temp[k][j];
                    }
                }
            }
        }

        if (matrix[mapNameIndex->find(departureCity)->value][mapNameIndex->find(arrivalCity)->value] != INF) {

            cur = "the most effective price for that route: " +
                  to_string(matrix[mapNameIndex->find(departureCity)->value][mapNameIndex->find(
                          arrivalCity)->value]) +
                  '\n' + "Route: ";

            printPath(startIndex, endIndex, temp, mapIndexName, cur);

            cur.erase(cur.size() - 3);

        } else {
            cur = "this route is absent in scheduele";
        }

        return cur;

    }

private:
    void printPath(int i, int j, int **p, Map<int, string> *map_index_to_name_City, string &current) {
        if (i != j) {
            printPath(i, p[i][j], p, map_index_to_name_City, current);
        }
        current = current + map_index_to_name_City->find(j)->value + " -> ";
    }

    double **matrix;

    int matrixSize;
    Map<string, int> *mapNameIndex;

    Map<int, string> *mapIndexName;

    const int INF = 99999999;
};
