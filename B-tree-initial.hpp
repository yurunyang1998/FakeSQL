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




        middle_node <key_type, value_type> * initial_B_tree(key_type key)
        {

            middle_node<key_type, value_type> *root = new middle_node<key_type, value_type>;
            middle_node<key_type, value_type> *child_1 = new middle_node<key_type, value_type>(root);
            leaf_node<key_type, value_type> *leaf_node1 = new leaf_node<key_type, value_type>(child_1);

            middle_node<key_type, value_type> *child_2 = new middle_node<key_type, value_type>(root);
            leaf_node<key_type, value_type> *leaf_node2 = new leaf_node<key_type, value_type>(child_1);



            root->insert(key, child_1);
            root->insert(key+100,child_2);


            child_1->insert(key, leaf_node1);
            //leaf_node1->insert(12,321);

            whether_initialed =1;


            return root;
        }


        value_type data_search(key_type key)
        {
            try {

                if(!whether_initialed)
                    throw(-1);
                middle_node_t * temp_node =root;
                points_struct<key_type,value_type>*  point  = new points_struct<key_type,value_type>;

                point = temp_node->searchkey(key);//#
                //cout<<point->flag;
                while(1)
                {

                    //#point = temp_node->searchkey(key);
                    //break;
                    if(point->flag==0) {
                        delete point;
                        throw (-2);
                    }
                    if(point->flag==1)
                    {
                        point=point->middle_node_point->searchkey(key);
                    }
                    else
                    {
                        value_type value ;
                        value =point->leaf_node_point->searchkey(key);
                        cout<<value<<endl;
                        delete point;
                        break;
                    }

                }
            }


            catch(int &error)
            {
                if(error==-1)
                {
                    cout<<"树未初始化";


                    return -1;
                }
                if(error = -2)
                {
                    cout<<"The tree has not this key";
                    return -2;
                }
            }

        }


        int insert_data(key_type key,value_type value)
        {
            middle_node<key_type,value_type>  * temp_root = root;
            points_struct<key_type,value_type> * point = new points_struct<key_type,value_type>;

            while (1) {
                point = temp_root->searchkey(key);
                if (point->flag == 0)  //没有找到相关节点
                {
                    if (temp_root->user_paires() > 10) {
                        //split_node
                        break;
                    } else
                    {

                        middle_node<key_type,value_type>  * middle_node_t = new middle_node<key_type,value_type>;
                        leaf_node<key_type,value_type>  *  leaf_node_t =  new leaf_node<key_type,value_type>(middle_node_t);
                        middle_node_t->insert(key,leaf_node_t);
                        leaf_node_t->insert(key,value);
                        middle_node_t->updatekey();
                        temp_root->insert(key,middle_node_t);
                        return 1;
                    }
                }
            }

        }
















    };
}




#endif
