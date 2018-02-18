//
// Created by yurunyang on 18-2-16.
//
#include "Btree_leaf_node.h"
#include "assert.h"
#ifndef FAKESQL_BTREE_ZHONGJIAN_NODE_H
#define FAKESQL_BTREE_ZHONGJIAN_NODE_H

namespace utils {

template <class key_type >
class zhongjian_Node{
public:
    zhongjian_Node()
    {
        this->used_nodes=0;

    };

    void set_this_to_root_node(){
        this->whether_root = true;
    }

    void set_parent_node(zhongjian_Node<key_type> *parent_copy) {

        assert(this->parent = parent_copy)
        {
            std::cout << "set parent_node failed" << std::endl;
        }
            std::cout << "set parent_node succeed" << std::endl;

    }

    int get_used_nodes_number(){
        return  this->used_nodes;
    }

    int get_empty_nodes_number()
    {
        return (5-used_nodes);
    }

    int spile_node();   //分裂自己


    void set_child_node(zhongjian_Node<key_type> * child,int i,key_type key_g){ // i 表示使用过的节点

        switch (i)
        {
            case 0 :{
                this->key0 = key_g;
                this
            }
        }
    }









private:

    zhongjian_Node<key_type>  *parent;   //父节点
    int used_nodes; //已经使用过的节点

    bool whether_root = false;      //表示这个是不是根节点


    //当作为中间的节点时，使用下面的属性

    key_type zhongjian_key_0;
    key_type zhongjian_key_1;
    key_type zhongjian_key_2;
    key_type zhongjian_key_3;
    key_type zhongjian_key_4;

    zhongjian_Node<key_type>  *zhongjian_index_0;
    zhongjian_Node<key_type>  *zhongjian_index_1;
    zhongjian_Node<key_type>  *zhongjian_index_2;
    zhongjian_Node<key_type>  *zhongjian_index_3;
    zhongjian_Node<key_type>  *zhongjian_index_4;











    //当作为倒数第二个层节点时使用下面的属性
    key_type key0;
    key_type key1;
    key_type key2;
    key_type key3;

    Btree_leaf_Node<key_type>   *index0;       //key <0
    Btree_leaf_Node<key_type>   *index0_1;         //0<=key<1
    Btree_leaf_Node<key_type>   *index1_2;         //1<= key <2
    Btree_leaf_Node<key_type>   *index2_3;         //2<=key <3
    Btree_leaf_Node<key_type>   *index3_;          //3 <= key
    //当作为倒数第二层节点时，使用上面的参数
};

} // end of utils

#endif //FAKESQL_BTREE_ZHONGJIAN_NODE_H
