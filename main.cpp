#include <iostream>
#include "vector"

#include "B-tree.cpp"

using namespace utlis;
int main() {


    middle_node<int> a;
    //middle_node<int> *c =  new middle_node<int>;
    //middle_node<int> *d =  new middle_node<int>;
//
    middle_node<int> * b = new middle_node<int>;
    middle_node<int> * c = new middle_node<int>;
    middle_node<int> * d = new middle_node<int>;
    middle_node<int> * e = new middle_node<int>;

    leaf_node<int,int> * f = new leaf_node<int,int>;

    leaf_node<int,int> * g = new leaf_node<int,int>;

    leaf_node<int,int> * h = new leaf_node<int,int>;

    leaf_node<int,int> * i = new leaf_node<int,int>;



    a.insert(2,b);
    a.insert(3,c);
    a.insert(1,d);
    a.insert(32,e);
    e->insert(2,f);
    e->insert(22,g);
    e->insert(12,h);
    b->insert(13,i);
    int s;
    return 0;

    //vector<vector<int>> a;



}