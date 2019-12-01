#include "backpack.h"
#include <iostream>

Backpack *Backpack::collect_backpack(Item *list_of_items, int max_weight) {
    auto *back = new Backpack();
    int i, j, k, valuable, mm[(ITEM_COUNT + 1) * (max_weight + 1)], *m[(ITEM_COUNT + 1)];
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
            back->items_result_map[i - 1]++;
            j -= list_of_items[i - 1].get_weight();
        }
    }

    return back;
}

using namespace std;

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