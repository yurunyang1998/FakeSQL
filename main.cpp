#include <iostream>
#include "vector"
#include "B-tree.cpp"

using namespace std;
int main() {
    leaf_node<int,int> a;
    a.insert(23,10);
    a.delete_pair(23);
    cout<<a.key_value_pairs[1].getkey();
    std::cout << "Hello, World!" << std::endl;
    return 0;
}