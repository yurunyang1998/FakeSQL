#include <iostream>
#include "vector"

#include "B-tree_nodes.hpp"
#include "B-tree-initial.hpp"
using namespace utlis;
int main() {


    Manager<int,int> manager(10);

    manager.insert_data(140,523);
    manager.insert_data(139,23);
    manager.data_search(140);
    int a;


}



