//
// Created by falleuion on 8/17/18.
//

#ifndef AST_H_
#define AST_H_

#ifdef __cplusplus
extern "C" {
#endif

enum atom_types {
    AT_NUMBER, AT_STRING, AT_IDENTIFIER, AT_CONDITION
};

typedef struct {
    enum atom_types type;
    union {
        long number;
        char *string;
        int subtok;
    } value;

} ast_node_atom;

ast_node_atom* new_atom_node(enum atom_types type, void *v);

void delete_atom_node(ast_node_atom *node);

void print_node_atom(ast_node_atom *node);



struct _ast_node_opts;
struct _ast_node_sexp;

typedef struct _ast_node_sexp ast_node_sexp;
typedef struct _ast_node_opts ast_node_opts;

typedef struct {
    ast_node_sexp **list;
    ast_node_opts **opts;

    unsigned int length;
    unsigned int capacity;
} ast_node_list;

ast_node_list *new_list_node();

void delete_list_node(ast_node_list *node);

void print_node_list(ast_node_list *node);

void add_node_to_list(ast_node_list *list, ast_node_sexp *node);



enum sexp_types {
    ST_ATOM, ST_LIST
};

struct _ast_node_sexp {
    enum sexp_types type;
    union {
        ast_node_atom *atom;
        ast_node_list *list;
    } value;
};

void print_node_sexp(ast_node_sexp *node);

ast_node_sexp *new_sexp_node(enum sexp_types type, void *v);

void delete_sexp_node(ast_node_sexp *node);



enum opts_types {
    OP_WHERE, OP_SELECT, OP_GROUPBY, OP_HAVING, OP_ORDERBY, OP_LIMIT, OP_INTO_LIST
};

struct _ast_node_opts {
    enum opts_types type;
    union {
        ast_node_atom *atom;
        ast_node_list *list;
    } value;
};

ast_node_opts *new_opts_node(enum opts_types type, void *v);
void delete_opts_node(ast_node_opts *node);
void add_opts_node_to_list(ast_node_list *list, ast_node_opts *node);

typedef struct table_list {
    char *name;
    struct table_list *next;
} table_list_t;


typedef struct command_callback {
    void (*callback)(void *);
    struct command_list *next;
} cmd_list_t;


typedef struct columns_list {

} columns_list_t;


struct sql_cmd {
    table_list_t *TableList;
    cmd_list_t *CmdList;
};


#ifdef __cplusplus
}
#endif


#endif //AST_H_
