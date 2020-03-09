#include "item.h"

Item::Item(string name, int weight, int value, int count) {
    if (name == "" || weight <= 0 || value <= 0 || count <= 0) {
        throw "Wrong item data";
    }
    this->name = name;
    this->weight = weight;
    this->value = value;
    this->count = count;
}

int Item::get_weight() {
    return this->weight;
}

int Item::get_count() {
    return this->count;
}

string Item::get_name() {
    return this->name;
}

int Item::get_value() {
    return this->value;
}

Item Item::create_empty() {
    return Item("", 0, 0, 0);
}