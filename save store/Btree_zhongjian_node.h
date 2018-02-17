//
// Created by yurunyang on 18-2-16.
//
#include "Btree_leaf_node.h"

#ifndef FAKESQL_BTREE_ZHONGJIAN_NODE_H
#define FAKESQL_BTREE_ZHONGJIAN_NODE_H

namespace utils {

template <class key_type >
class zhongjian_Node{
public:
    zhongjian_Node()
    {

    };

    void set_parent_node(zhongjian_Node<key_type> *parent_copy)
    {
        try{
            this->parent=parent_copy;
            cout<<"set parent_node succeed"<<endl;
        }catch (...)
        {

        }
    }

    int spile_node();   //分裂自己


private:

    zhongjian_Node<key_type>  *parent;   //父节点


    key_type key0;
    key_type key1;
    key_type key2;
    key_type key3;

    Btree_leaf_Node<key_type>   *index0;       //key <0
    Btree_leaf_Node<key_type>   *index0_1;         //0<=key<1
    Btree_leaf_Node<key_type>   *index1_2;         //1<= key <2
    Btree_leaf_Node<key_type>   *index2_3;         //2<=key <3
    Btree_leaf_Node<key_type>   *index3_;          //3 <= key

};

} // end of utils

#endif //FAKESQL_BTREE_ZHONGJIAN_NODE_H
