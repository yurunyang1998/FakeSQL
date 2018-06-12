#include <iostream>
#include "vector"

#include "B-tree.cpp"

using namespace utlis;
int main() {
    leaf_node<int,int> a;
    a.insert(2,10);
    a.insert(1,2);
    a.insert(56,3);
    a.insert(32,4);
    a._sort();
    a.delete_pair(3);
    std::cout<<a.key_value_pairs[3].getkey();
    //std::cout << "Hello, World!" << std::endl;
    return 0;

    //vector<vector<int>> a;



}