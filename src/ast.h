//
// Created by falleuion on 8/17/18.
//

#ifndef AST_H_
#define AST_H_

#ifdef __cplusplus
extern "C" {
#endif

#include <strings.h>

enum atom_types
{
    AT_NUMBER, AT_STRING, AT_IDENTIFIER, AT_CONDITION
};

struct _ast_node_opts;
struct _ast_node_sexp;

typedef struct _ast_node_sexp ast_node_sexp;

typedef struct _ast_node_opts ast_node_opts;

// structure `ast_node_atom'
// This should be the node corresponding to the terminator.Its type can be the `number',
// `string'. `table reference' etc.
typedef struct
{
    enum atom_types type;
    union
    {
        long number;
        char *string;
        int subtok;
    } value;
    
} ast_node_atom;

// This function will generate a new item of the teminator
// Return: the structure of `ast_node_atom' on success.
ast_node_atom *
new_atom_node(enum atom_types type, void *v);

void
delete_atom_node(ast_node_atom *node);

void
print_node_atom(ast_node_atom *node);

// This function will add the parameter @v to the @node
void
add_atom_to_sexp(ast_node_sexp *_node, ast_node_atom *_atom);

typedef struct
{
    ast_node_sexp **list;
    ast_node_opts **opts;
    
    unsigned int length;
    unsigned int capacity;
} ast_node_list;

ast_node_list *
new_list_node();

void
delete_list_node(ast_node_list *node);

void
print_node_list(ast_node_list *node);

void
add_node_to_list(ast_node_list *list, ast_node_sexp *node);

enum sexp_types
{
    ST_ATOM, ST_LIST, ST_NONE
};

struct _ast_node_sexp
{
    enum sexp_types type;
    union
    {
        ast_node_atom *atom;
        ast_node_list *list;
    } value;
    struct _ast_node_sexp *next;
};

void
print_node_sexp(ast_node_sexp *node);

ast_node_sexp *
new_sexp_node(enum sexp_types type, void *v);

void
delete_sexp_node(ast_node_sexp *node);

enum opts_types
{
    OP_WHERE, OP_SELECT, OP_GROUPBY, OP_HAVING, OP_ORDERBY, OP_LIMIT, OP_INTO_LIST
};

struct _ast_node_opts
{
    enum opts_types type;
    union
    {
        ast_node_atom *atom;
        ast_node_list *list;
    } value;
};

ast_node_opts * new_opts_node(enum opts_types type, void *v);
void delete_opts_node(ast_node_opts *node);
void add_opts_node_to_list(ast_node_list *list, ast_node_opts *node);


// ---------- this following structure will be used as operator such as `SELECT', `CREATE', `INSERT' etc. -------

enum oprt_type
{
    CREATE, INSERT
};

struct _tabl_list;
struct _tabl_name_list;
struct _kv_pair;
struct _sql_opts;


struct _oprt_node
{
    // This member is used to mark the SQL command.
    enum oprt_type type_;
    
    /** The structure contains 'sql table' that users reference. It should be a list type.
     * In case users are specified in `name.name'
     */
    struct _tabl_list *table_;
    
    union
    {
        struct _tabl_name_list *table_name_list_;
        struct kv_pair *kv_list_;
    } universal_list_;
    
    struct _sql_opts *options_;
};

/**
 * The whole logical relation of the `oprt_node' struct should probably be the following.
 * Each of the three children of the `operator' will be a structure, and the `options' node
 * may NOT exist.
 *                    ,------.
 *                    | root |
 *                    `------'
 *                       |
 *                  ,----------.
 *                  | operator |
 *                 ,`----------'.
 *        ,______,'      |       `---------.
 *  ,---------. ,-----------------.  ,-----------.
 *  | options | | name_table list |  | name list |
 *  `---------' `-----------------'  `-----------'
 */


// linked list is easy to implement. at the same time it's useful.
struct _kv_pair {
    char first[32];
    char second[32];
    struct _kv_pair *next;
};

struct _tabl_name_list {
    char tabl_ref[32];
    struct _tabl_name_list *next;
};


struct _tabl_list {
    struct {
        // The `name' MUST be set, and the `sub_columns' may point the null.
        char name[32];
        char sub_columns[32];
    } tabl_ref;
    struct _tabl_list *next;
};


struct _sql_opts {
    char test[32];
};

struct _tabl_list *new_tabl_list(char *ref);
void delete_tabl_list(struct _tabl_list *list);

struct _oprt_node *new_oprt_node(enum oprt_type type);
void delete_oprt_node(struct _oprt_node *node);

struct _tabl_name_list *new_tablNameList_node(char *ref);
void delete_tablNameList_node(struct _tabl_name_list *node);

struct _kv_pair *new_kvPair_node(char *key, char *value);
void delete_kvPair_node(struct _kv_pair *kv);

#ifdef __cplusplus
}
#endif


#endif //AST_H_
