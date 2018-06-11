//
// Created by yurunyang on 18-6-11.
//

#include <vector>
#include "iostream"


using namespace std;

template <class key_type,class value_type>
class key_value_pair
{
private:

    key_type key;
    value_type value;
public:
    key_value_pair(key_type key=NULL,value_type value=NULL)
    {
        this->key=key;
        this->value=value;
    }
    key_type getkey(void) { return key ; }
    value_type getvalue(void) { return  value; }
    void set_key(key_type  set_key)
    {   key = set_key;
        //return 0;
    }

    void set_value(value_type set_value )
    {
        value = set_value;
    }
};


template <class key_type,class value_type>
class leaf_node
{
public:
    //vector<int> v = vector<int>(10, 0);
    vector< key_value_pair<key_type,value_type> >key_value_pairs = vector< key_value_pair<key_type,value_type> >(1);
    int used_pairs;
public:
    leaf_node(){used_pairs=0;};

    int  insert(key_type key ,value_type value)
    {
        if(used_pairs==10)
        {
            return 0;  //该叶子节点已满,插入失败
        } else
        {
            key_value_pair<key_type,value_type> new_pair(key,value);  //初始化一个新的key_value_pair
            key_value_pairs.push_back(new_pair);   //加入到key_value_pairs 的vector 中
            used_pairs++;                       //当前已使用的pair加1
            return  1 ;  //insert successed
        }
    };


    int delete_pair(key_type key)
    {
        typename vector< key_value_pair<key_type,value_type> >::iterator iter= key_value_pairs.begin();
        while(iter!=key_value_pairs.end())
        {
            if(iter->getkey()==key)
            {
                iter->set_key(NULL);
                iter->set_value(NULL);
                key_value_pairs.erase(iter);
                used_pairs--;
                cout<<"delete";
                break;
            } else iter++;
        }
    }

    key_type get_key()
    {
        return 0;
    }


};