#include <iostream>
#include "vector"

//#include "B-tree_nodes.hpp"
#include "B-tree-initial.hpp"
using namespace utlis;
int main() {


    Manager<int, int> manager(-2147483648);

    //double a[25]={12,32,43,13,54,23,23,43,53,54,67,6,75,23,78,14,54,32,23,47,27,36,27,26,16};
    for (int i = 500; i >=0; i--)
    {
         manager.insert_data(i, i);
    }

    for (int i=500;i>=0;i--)
    {
        manager.data_search(i);
    }




    int i;
    return 0;

}



