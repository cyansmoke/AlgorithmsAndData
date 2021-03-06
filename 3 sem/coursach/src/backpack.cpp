#include "backpack.h"
#include <iostream>

Backpack::Backpack(Item *list_of_items, int max_weight) {
    if (max_weight <= 0) {
        throw "Wrong max weight";
    }

    for (int &i : items_result_map) {
        i = 0;
    }

    int i, j, k, valuable, *mm, **m;

    mm = new int[(ITEM_COUNT + 1) * (max_weight + 1)];
    for (i = 0; i < (ITEM_COUNT + 1) * (max_weight + 1); i++) {
        mm[i] = 0;
    }

    m = new int *[ITEM_COUNT + 1];
    m[0] = mm;
    for (i = 1; i <= ITEM_COUNT; i++) {
        m[i] = &mm[i * (max_weight + 1)];
        for (j = 0; j <= max_weight; j++) {
            m[i][j] = m[i - 1][j];
            for (k = 1; k <= list_of_items[i - 1].get_count(); k++) {
                if (k * list_of_items[i - 1].get_weight() > j) {
                    break;
                }
                valuable = m[i - 1][j - k * list_of_items[i - 1].get_weight()] + k * list_of_items[i - 1].get_value();
                if (valuable > m[i][j]) {
                    m[i][j] = valuable;
                }
            }
        }
    }

    for (i = ITEM_COUNT, j = max_weight; i > 0; i--) {
        int val = m[i][j];
        for (k = 0; val != m[i - 1][j] + k * list_of_items[i - 1].get_value(); k++) {
            this->items_result_map[i - 1]++;
            j -= list_of_items[i - 1].get_weight();
        }
    }
}

void Backpack::print_result(Item raw_items[]) {
    int result_weight = 0;
    for (int i = 0; i < ITEM_COUNT; i++) {
        if (items_result_map[i]) {
            cout << raw_items[i].get_name() << " ";
            cout << items_result_map[i] << " ";
            cout << items_result_map[i] * raw_items[i].get_weight() << " ";
            cout << items_result_map[i] * raw_items[i].get_value() << endl;
            result_weight += items_result_map[i] * raw_items[i].get_weight();
        }
    }
    cout << "Result weight: " << result_weight;
}

int *Backpack::get_items_result_map() {
    return items_result_map;
}