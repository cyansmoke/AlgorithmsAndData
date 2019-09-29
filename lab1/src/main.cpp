#include <iostream>
#include "EL1.cpp"
#include "List.cpp"

using namespace std;

int main() {
    List list1;
    list1.push_front(1);
    list1.print_to_console();
    cout << endl << list1.at(0);
    list1.set(0, 2);
    cout << endl << list1.at(0);
    list1.push_back(3);
    list1.print_to_console();
    cout << endl;
    list1.push_front(4);
    list1.print_to_console();
    list1.pop_front();
    list1.print_to_console();
    List list2;

    list2.push_front(2);
    list2.push_front(3);
    list2.push_back(6);
    list2.print_to_console();

    list2.push_front(list1);
    list2.print_to_console();
    list1.print_to_console();
}