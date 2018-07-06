#include <iostream>
#include "vector"

#include "B-tree_nodes.hpp"
#include "B-tree-initial.hpp"
using namespace utlis;
int main() {


    Manager<int,int> manager(50);

    for (int i=0;i<10;i++)
        manager.insert_data(i,i);

    for(int i=10;i<20;i++)
        manager.insert_data(i,i);

    //manager.data_search(11);
    int i;
    for(int i =0;i<30;i++)
        manager.data_search(i);
    int a;

    return 0;

}



