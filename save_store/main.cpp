#include <iostream>
#include "Btree_zhongjian_node.h"

int main() {
    utils::Btree_leaf_Node<int> leaf;

    std::string it  = "hahah";
    int i = 4;
    std::cout << &i << "  " << &it << std::endl;
    leaf.insert_data(i,it);
    leaf.insert_data(5,"sdfsdf");
    leaf.print();

}