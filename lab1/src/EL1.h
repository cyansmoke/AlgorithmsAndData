#pragma once

class EL1 {

public:
    EL1(int data);

    ~EL1();

    /**
     * @return int data of element
     */
    int get_data();

    /**
     * set element data to @param int
     */
    void set_data(int data);

    /**
     * @return next element
     */
    EL1* get_next();

    /**
     * set next element
     */
    void set_next(EL1* next);

private:
    int data;
    EL1* next = nullptr;
};