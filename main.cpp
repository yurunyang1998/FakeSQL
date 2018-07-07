#include <iostream>
#include "vector"

#include "B-tree_nodes.hpp"
#include "B-tree-initial.hpp"
using namespace utlis;
int main() {


    Manager<int,int> manager(50);

    //double a[25]={12,32,43,13,54,23,23,43,53,54,67,6,75,23,78,14,54,32,23,47,27,36,27,26,16};
    for (int i=0;i<15;i++)
        manager.insert_data(i,i);

    for(int i=10;i<15;i++)
        manager.insert_data(i+0.1,i+0.1);

    //manager.data_search(11);
    int i;
    for(int i =0;i<15;i++)
        manager.data_search(i+0.1);
    //int a;

    return 0;

}



