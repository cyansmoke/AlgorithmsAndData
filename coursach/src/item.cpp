#include "item.h"

Item::Item(string name, int weight, int value, int count) {
    this->name = name;
    this->value = value;
    this->weight = weight;
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