//
// Created by falleuion on 8/17/18.
//

#ifndef AST_H_
#define AST_H_

#ifdef __cplusplus
extern "C" {
#endif
#include "commons.h"
#include <strings.h>
#include <stdint.h>

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
    } value;
};

ast_node_opts * new_opts_node(enum opts_types type, void *v);
void delete_opts_node(ast_node_opts *node);

// ---------- this following structure will be used as operator such as `SELECT', `CREATE', `INSERT' etc. -------

static uint8_t __Sql_NOTNULLX = 0x01;
static uint8_t __Sql_AUTOINC = 0x02;
static uint8_t __Sql_UNIKEY = 0x04;
static uint8_t __Sql_PRIKEY = 0x08;
static uint8_t __Sql_KEY = 0x10;

enum DataType
{
    DT_BIT, DT_TINYINT, DT_SMALLINT, DT_MEDINT, DT_INT, DT_INTEGER, DT_BIGINT, DT_REAL, DT_DOUBLE, DT_FLOAT,
    DT_DECIMAL, DT_DATE, DT_TIME, DT_TIMESTAMP, DT_DATETIME, DT_YEAR, DT_CHAR, DT_VARCHAR, DT_BINARY, DT_MEDBIN,
    DT_TINYBLOB, DT_BLOB, DT_MEDBLOB, DT_VARBIN, DT_LONGBLOB, DT_TINYBIN, DT_LONGBIN, DT_TEXT, DT_TINYTEXT, DT_MEDTEXT, DT_LONGTEXT
};


struct _TablList;
struct _NameList;
struct _kv_pair;
struct _SqlOpts;
struct _DefOpts;

struct _OprtNode
{
    // This member is used to mark the SQL command.
    enum OprtType type_;
    
    /** The structure contains 'sql table' that users reference. It should be a list type.
     * In case users are specified in `name.name'
     */
    struct _TablList *table_;
    
    union
    {
        struct _NameList *tableNameList_;
        struct _DefOpts *defOpts_;
    } universalList_;
    
    struct _SqlOpts *options_;
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
    char first_[32];
    char second_[32];
    struct _kv_pair *next;
};

struct _DataType {
    uint32_t type_;
    uint64_t size_;
    uint8_t uz_;        // meaning unsigned or fill with zero..
    uint8_t isBin_;
};

struct _DefOpts {
    struct _kv_pair *kvPair_;
    int attri_;
    struct _DataType dataType_;

    struct _DefOpts *next;
};

struct _NameList {
    char ref_[32];
    struct _NameList *next;
};


struct _TablList {
    struct {
        // The `name_' MUST be set, and the `subColumns_' may point the null.
        char name_[32];
        char subColumns_[32];
    } _TablRef;
    struct _TablList *next;
};


struct _SqlOpts {
    char test[32];
};

// alias...
typedef struct _NameList columns_list_t;

// 如果`ref_sec' 没有参数,直接将它设置味 `NULL' 就好
struct _TablList *new_tabl_list(char *ref_fir, char *ref_sec);
void add_tabl_list(struct _TablList *head, char *ref);
void del_tabl_list(struct _TablList *list);

struct _OprtNode *new_oprt_node(enum OprtType type);
void del_oprt_node(struct _OprtNode *node);

columns_list_t *new_NameList_node(char *ref);
void add_NameList_node(columns_list_t *head, const char *ref);
void del_NameList_node(columns_list_t *node);

struct _kv_pair *new_kvPair_node(char *key, char *value);
void add_kvPair_node(struct _kv_pair *list, char *key, char *value);
void del_kvPair_node(struct _kv_pair *kv);

struct _DefOpts *new_DefOpts_node();
void del_DefOpts_node(struct _DefOpts *node);

#ifdef __cplusplus
}
#endif


#endif //AST_H_
