//
// Created by yurunyang on 18-2-15.
//
#include <iostream>
#include "string"
#ifndef FAKESQL_BTREE_NODE_H
#define FAKESQL_BTREE_NODE_H

#endif //FAKESQL_BTREE_NODE_H

using namespace std;


template <class key_type>
class zhongjian_Node;      //在这里声明一下





template  <class key_type>
class  Btree_leaf_Node{
public:
    Btree_leaf_Node(){
        this->used_key_number=0;
    };

    void insert_data(key_type key_g,string data_g)// _g 结尾表示外面来的数据指针，防止和内部的key，data命名混淆
    {
        int now_used_number ;
        now_used_number = this->get_key_numbers();
        if(now_used_number<=5){
            switch (now_used_number){
                case 0:{
                    this->key0 = new key_type;
                    *key0 = key_g;
                    this->data0 = new string;
                    *data0 = data_g;

                    used_key_number++;
                    break;
                }
                case 1:{
                    this->key1 = new key_type;
                    *key1 = key_g;
                    this->data1 = new string;
                    *data1 = data_g;

                    used_key_number++;
                    break;

                }
                case 2:{
                    this->key2 = new key_type;
                    *key2 = key_g;
                    this->data2 = new string;
                    *data2 = data_g;

                    used_key_number++;
                    break;
                }
                case 3:{
                    this->key3 = new key_type;
                    *key3 = key_g;
                    this->data3 = new string;
                    *data3 = data_g;

                    used_key_number++;
                    break;
                }
                case 4:{
                    this->key4 = new key_type;
                    *key4 = key_g;
                    this->data4 = new string;
                    *data4 = data_g;

                    used_key_number++;
                    break;
                }

            }

        }

    }

    void print(){
        cout << *this->key1<<"  "<<this->key1<<endl;
        cout << *this->data1<<"  "<<this->data1<<endl;
    }



    void set_brother_node(Btree_leaf_Node<key_type> *bro_node) {   //设置兄弟节点
        try {
            this->brother=bro_node;
            cout<<"Add brother_node succeed"<<endl;
        }
        catch(...)
        {
        }
    }

    void set_parent_node(zhongjian_Node<key_type> *parent_copy)
    {
        try{
            this->parent=parent_copy;
            cout<<"set parent_node succeed"<<endl;
        }catch (...)
        {

        }
    }
    int    get_key_numbers(){
        //std::cout << used_key_number<<std::endl;
        return this->used_key_number;
    }

private:

    int  used_key_number ;  // 当前本叶子节点已使用的key数量

    zhongjian_Node<key_type>  *parent ; //父节点地址

    Btree_leaf_Node<key_type>  *brother ; //兄弟节点

    key_type  *key0;
    string *data0;

    key_type *key1;
    string *data1;

    key_type *key2;
    string *data2;

    key_type *key3;
    string *data3;

    key_type *key4;
    string *data4;

};


