#include <iostream>
#include "Node.cpp"
#include "List.cpp"

using namespace std;

int main() {
    List list1;
    list1.push_back(4);
    list1.push_back(5);
    list1.push_back(6);

    List list2;
    list2.push_front(3);
    list2.push_front(2);
    list2.push_front(1);

    list1.push_front(list2);

    for (int i = list1.get_size(); i > 0; i--) {
        cout << list1.at(i - 1);
    }
}