#include <iostream>
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
    cout << stack.peek()->get_data() << endl;
    stack.pop();
    cout << stack.pop()->get_data()<< endl;
    cout << stack.get_size() << endl;

    return 0;
}