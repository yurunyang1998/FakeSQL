//
// Created by falleuion on 9/30/18.
//

#include <cstdlib>
#include "ast.h"
#include <iostream>

// TODO: Implementing the unit testint of the `ast.h' file.
// unit test should be added below.

void print_OprtInfo(const struct _OprtNode *ref)
{
    switch (ref->type_) {
        case TS_CREATE:
            std::cout << "operator: CREATE" << std::endl;
            break;
        case TS_INSERT:
            std::cout << "operator: INSERT" << std::endl;
            break;
    }

}

void print_kv(const struct _kv_pair *head)
{
    const struct _kv_pair *tmp = head;

    while(tmp != NULL) {
        std::cout << "key: " << tmp->first_ << "   value: " << tmp->second_ << std::endl;
        tmp = tmp->next;
    }

}

int main()
{
    struct _OprtNode *head = new_oprt_node(TS_CREATE);
    columns_list_t *list = new_NameList_node(const_cast<char *>("test"));
    head->universalList_.tableNameList_ = list;

    struct _kv_pair *kv = new_kvPair_node(const_cast<char *>("test"), const_cast<char *>("test"));
    add_kvPair_node(kv, const_cast<char *>("key"), const_cast<char *>("test"));

    print_OprtInfo(head);
    print_kv(kv);

    del_oprt_node(head);
    del_NameList_node(list);
    del_kvPair_node(kv);

    return 0;
}
