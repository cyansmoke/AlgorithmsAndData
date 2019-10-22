#include <iostream>
#include "Stack.h"
#include "Node.cpp"
#include "Stack.cpp"

using namespace std;

int main() {
    Stack<char> stack;

    cout << stack.get_size() << endl;
    stack.push('3');
    stack.push('2');
    stack.push('1');

    cout << stack.pop()->get_data() << endl;
    cout << stack.pop()->get_data() << endl;
    cout << stack.pop()->get_data() << endl;

    return 0;
}