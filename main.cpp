#include <iostream>
#include "vector"

#include "B-tree_nodes.hpp"
#include "B-tree-initial.hpp"
using namespace utlis;
int main() {


    Manager<int,int> manager(10);
    for(int i=90;i<1000;i+=100)
        manager.insert_data(i,i);
    for(int i=100;i<1000;i+=110)
        manager.insert_data(i,i);
    //manager.insert_data(123,523);
    manager.data_search(760);
    int a;


}



