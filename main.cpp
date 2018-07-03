#include <iostream>
#include "vector"

#include "B-tree_nodes.hpp"
#include "B-tree-initial.hpp"
using namespace utlis;
int main() {


    Manager<int,int> manager(1);

    for (int i=0;i<30;i+=1)
        manager.insert_data(i,i);

//    for(int i =0;i<30;i++)
//        manager.data_search(i);
    int a;


}



