//
// Created by cyansmoke on 30.11.2019.
//

#ifndef COURSACH_ITEM_H
#define COURSACH_ITEM_H

#include <string>

using namespace std;

class Item {
private:
    string name;
    int weight = 0;
    int value = 0;
    int count = 0;
public:
    /**
     * constructor
     */
    Item(string, int, int, int);

    /**
     * @return value of item
     */
    int get_value();

    /**
     * @return weight of item
     */
    int get_weight();

    /**
     * @return count of item
     */
    int get_count();

    /**
     * @return name of item
     */
    string get_name();

    static Item create_empty();
};


#endif //COURSACH_ITEM_H
