#include <iostream>
#include "vector"

#include "B-tree.cpp"

using namespace utlis;
int main() {


    middle_node<int> a;
    //middle_node<int> *c =  new middle_node<int>;
    //middle_node<int> *d =  new middle_node<int>;
//
    leaf_node<int,int> * b = new leaf_node<int,int>;
    //a.insert(1,c);
    leaf_node<int,int> * c = new leaf_node<int,int>;
    a.insert(2,b);
    a.insert(3,c);
    int s;
    return 0;

    //vector<vector<int>> a;



}