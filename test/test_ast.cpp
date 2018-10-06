//
// Created by falleuion on 9/30/18.
//

#include <cstdlib>
#include "ast.h"
#include <iostream>

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

void scan_oprt_node(struct _OprtNode *root)
{

}

void print_NameList_node(columns_list_t *root)
{
    columns_list_t *head = root->next;

    while(head != NULL) {
        printf("%s\n", head->ref_);
        head = head->next;
    }
}

int main()
{
    columns_list_t *root = new_NameList_node();
    add_NameList_node(root, "test1");
    add_NameList_node(root, "test2");
    print_NameList_node(root);
    del_NameList_node(root);

    return 0;
}
