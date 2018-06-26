//
// Created by yurunyang on 18-6-23.
//
#ifndef B_TREE_INITIAL_HPP
#define B_TREE_INITIAL_HPP


#include "B-tree_nodes.hpp"
#include "iostream"
#include "string"
namespace  utlis {


    template<class key_type, class value_type>
    class Manager {
    private:
        typedef  middle_node<key_type, value_type>  middle_node_t;

        int whether_initialed = 0;
        middle_node <key_type, value_type> *root;

    public:
        Manager(key_type key) {
            root = initial_B_tree(key);
        }




        middle_node <key_type, value_type> * initial_B_tree(key_type key) {

            middle_node<key_type, value_type> *root = new middle_node<key_type, value_type>;
            middle_node<key_type, value_type> *child_1 = new middle_node<key_type, value_type>(root);
            leaf_node<key_type, value_type> *leaf_node1 = new leaf_node<key_type, value_type>(child_1);
            root->insert(key, child_1);
            child_1->insert(key, leaf_node1);
            whether_initialed =1;


            return root;
        }


        int data_insert(key_type key)
        {
            try {

                if(!whether_initialed)
                    throw(-1);
                middle_node_t * temp_node =root;
                while(1)
                {
                    points_struct<key_type,value_type>*  point  = new points_struct<key_type,value_type>;

                    point = temp_node->searchkey(key);
                }
            }







            catch(int &error)
            {
                if(error==-1)
                {
                    cout<<"树未初始化";
                    return -1;
                }
            }

        }




    };
}




#endif
