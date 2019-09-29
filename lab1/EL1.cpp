#include "EL1.h"

EL1::EL1(int data) : data(data) {
    this->set_data(data);
}

EL1::~EL1() {
    this->data = -1;
    this->set_next(nullptr);
    delete(this);
}

int EL1::get_data(){
    return this->data;
}

void EL1::set_data(int data) {
    this->data = data;
}

EL1* EL1::get_next() {
    return this->next;
}

void EL1::set_next(EL1* next) {
    this->next = next;
}

