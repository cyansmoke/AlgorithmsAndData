#include <string>
#include "map.h"
#include "map.cpp"

using namespace std;

int main() {
    Map<int, string> map = Map<int, string>();
    map.insert(2, "aa");
    map.insert(10, "sss");
    map.insert(228, "ooo");
    map.insert(-1, "kkkkk");
    map.insert(1, "kkkkkqq");
}
