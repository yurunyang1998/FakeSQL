#include <iostream>
#include "Btree_zhongjian_node.h"

int main() {
    Btree_leaf_Node<int> leaf;

    string it  = "hahah";
    int i = 4;
    cout<<&i<<"  "<<&it<<endl;
    leaf.insert_data(i,it);
    leaf.insert_data(5,"sdfsdf");
    leaf.print();

}