//
// Created by falleuion on 8/17/18.
//

#include "ast.h"


#ifdef __cplusplus
# include <cstdio>
# include <cstdlib>
# include <cstring>
# include <cassert>

extern "C" {
#else
# include <stdlib.h>
# include <string.h>
# include <stdio.h>
# include <assert.h>

#endif

ast_node_list* new_list_node()
{
    ast_node_list *node = (ast_node_list*) malloc(sizeof(ast_node_list));
    node->length = 0;
    node->capacity = 16;
    node->list = (ast_node_sexp **)malloc(16 * sizeof(ast_node_sexp *));
    node->opts = (ast_node_opts **)malloc(16 * sizeof(ast_node_opts *));

    return node;
}

void delete_list_node(ast_node_list* node)
{
    int i;
    for(i = 0; i < node->length; i++) {
        delete_sexp_node(node->list[i]);
        delete_opts_node(node->opts[i]);
    }
    free(node->list);
    free(node->opts);
    free(node);
}

void add_node_to_list(ast_node_list *list, ast_node_sexp *node)
{
    if(list->length == list->capacity) {
        // TODO should allocate some more space
    }
    list->list[list->length] = node;
    list->length++;
}

void print_node_list(ast_node_list* node)
{
    int i = 0;
    printf("list node with %d elements\n", node->length);
    for(i = 0; i < node->length; i++) {
        print_node_sexp(node->list[i]);
    }
}

ast_node_atom *new_atom_node(enum atom_types type, void *v)
{
    ast_node_atom *node = (ast_node_atom *)malloc(sizeof(ast_node_atom));
    node->type = type;

    switch(type) {
    case AT_IDENTIFIER:
    case AT_STRING:
        node->value.string = (char *) malloc(strlen((char *) v) + 1);
        strcpy(node->value.string, (char *) v);
        break;
    case AT_NUMBER:
        node->value.number = *((long *) v);
        break;
    case AT_CONDITION:
        node->value.subtok = *((int *)v);
        break;
    }
    return node;
}


void add_atom_to_sexp(ast_node_sexp *_node, ast_node_atom *_item)
{
    ast_node_sexp *_next = (ast_node_sexp *)malloc(sizeof(ast_node_sexp));
    bzero(_next, sizeof(ast_node_sexp));
    _next->type = ST_NONE;
    _node->type = ST_LIST;

    _node->value.atom = _item;
    _node->next = _next;
    _next->next = NULL;
}

void delete_atom_node(ast_node_atom* node)
{
    switch(node->type) {
    case AT_IDENTIFIER:
    case AT_STRING:
        free(node->value.string);
        break;
    case AT_NUMBER:
        break;
    }
    free(node);
}

void print_node_atom(ast_node_atom* node)
{
    if(node->type == AT_IDENTIFIER) {
        printf("identifier node: %s\n", node->value.string);
    }
    else if(node->type == AT_STRING) {
        printf("string node: %s\n", node->value.string);
    }
    else if(node->type == AT_NUMBER) {
        printf("number node: %ld\n", node->value.number);
    }
    else if(node->type == AT_CONDITION) {
        printf("condition node's type: %d\n", node->value.subtok);
    }
    else {
        printf("unknown atom node");
    }
}

ast_node_sexp *new_sexp_node(enum sexp_types type, void *v)
{
    ast_node_sexp *node = (ast_node_sexp *)malloc(sizeof(ast_node_sexp));
    node->type = type;
    node->next = NULL;

    switch(type) {
        case ST_ATOM:
            node->value.atom = (ast_node_atom*) v;
            break;
        case ST_LIST:
            node->value.list = (ast_node_list*) v;
            break;

    }
    return node;
}

void delete_sexp_node(ast_node_sexp *node)
{
    switch(node->type) {
    case ST_ATOM:
        delete_atom_node(node->value.atom);
        break;
    case ST_LIST:
        delete_list_node(node->value.list);
        break;
    }
    free(node);
}

void print_node_sexp(ast_node_sexp *node)
{
    if(node->type == ST_ATOM) {
        printf("node is an atom: ");
        print_node_atom(node->value.atom);
    }
    else if(node->type == ST_LIST) {
        printf("node is a list\n");
        print_node_list(node->value.list);
    }
    else {
        printf("node is a what?\n");
    }
}


ast_node_opts *new_opts_node(enum opts_types type, void *v)
{
    ast_node_opts *node = (ast_node_opts *)malloc(sizeof(ast_node_opts));
    node->type = type;

    switch(type) {
    case OP_WHERE:
        break;
    }
}

void delete_opts_node(ast_node_opts *node)
{
    switch(node->type) {
    // TODO: 完成
    case OP_HAVING:
        break;
    case OP_GROUPBY:
        break;
    case OP_INTO_LIST:
        delete_list_node(node->value.list);
        break;
    case OP_LIMIT:
        break;
    case OP_ORDERBY:
        break;
    case OP_SELECT:
        delete_list_node(node->value.list);
        break;
    case OP_WHERE:
        break;
    }
    free(node);
}


// ----------------- added on ---------------------

struct _oprt_node *new_oprt_node(enum oprt_type type)
{
    struct _oprt_node *root = (struct _oprt_node *)malloc(sizeof(struct _oprt_node));
    assert(root != NULL);
    
    bzero(root, sizeof(struct _oprt_node));
    root->type_ = type;
    return root;
}

void delete_oprt_node(struct _oprt_node *node)
{
    assert(node != NULL);

    del_tabl_list(node->table_);
    switch(node->type_) {
    case TS_CREATE:
        del_kvPair_node((struct _kv_pair *) node->universal_list_.kv_list_);
        break;
    case TS_INSERT:
        del_NameList_node(node->universal_list_.table_name_list_);
        break;
    default:
        // mei xiang hao
        break;
    }
}


struct _tabl_list *new_tabl_list(char *ref_fir, char *ref_sec)
{
    struct _tabl_list *list = (struct _tabl_list *)malloc(sizeof(struct _tabl_list));
    assert(list != NULL);

    bzero(list, sizeof(struct _tabl_list));
    assert(ref_fir != NULL);
    strncpy(list->tabl_ref.name, ref_fir, strlen(ref_fir));
    if(ref_sec != NULL) {
        strncpy(list->tabl_ref.sub_columns, ref_sec, strlen((ref_sec)));
    }

    list->next = NULL;
    return list;
}

void add_tabl_list(struct _tabl_list *head, char *ref)
{

}

void del_tabl_list(struct _tabl_list *list)
{
    assert(list != NULL);

    struct _tabl_list *head = list->next;

    while(head != NULL) {
        free(list);
        list = head;

        head = head->next;
    }
}


columns_list_t *new_NameList_node(char *ref)
{
    struct _name_list *tmp = (struct _name_list *)malloc(sizeof(struct _name_list));
    assert(tmp != NULL);
    assert(ref != NULL);

    strncpy(tmp->_ref, ref, strlen(ref));
    tmp->next = NULL;
    return tmp;
}

void add_NameList_node(columns_list_t *head, const char *ref)
{

}

void del_NameList_node(columns_list_t *node)
{
    assert(node != NULL);
    struct _name_list *head = node->next;

    while(head != NULL) {
        free(node);
        node = head;

        head = head->next;
    }
}


struct _kv_pair *new_kvPair_node(char *key, char *value)
{
    struct _kv_pair *tmp = (struct _kv_pair *)malloc(sizeof(struct _kv_pair));
    assert(tmp != NULL);

    bzero(tmp, sizeof(struct _kv_pair));
    strncpy(tmp->first, key, strlen(key));
    strncpy(tmp->second, value, strlen(value));

    tmp->next = NULL;
    return tmp;
}

void add_kvPair_node(struct _kv_pair *list, char *key, char *value)
{
    assert(list != NULL);
    struct _kv_pair *tmp = (struct _kv_pair *)malloc(sizeof(struct _kv_pair));

    strncpy(tmp->first, key, strlen(key));
    strncpy(tmp->second, value, strlen(value));

    tmp->next = list->next;
    list->next = tmp;
}

void del_kvPair_node(struct _kv_pair *kv)
{
    assert(kv != NULL);

    struct _kv_pair *head = kv->next;
    while(head != NULL) {
        free(kv);
        kv = head;

        head = head->next;
    }
}


#ifdef __cplusplus
}
#endif
