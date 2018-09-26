//
// Created by falleuion on 8/17/18.
//

#ifndef AST_H_
#define AST_H_

#ifdef __cplusplus
extern "C" {
#endif


enum atom_types {
    AT_NUMBER, AT_STRING, AT_IDENTIFIER, AT_CONDITION, AT_TABLE, AT_NAME
};

struct _ast_node_opts;
struct _ast_node_sexp;

typedef struct _ast_node_sexp ast_node_sexp;
typedef struct _ast_node_opts ast_node_opts;

// structure `ast_node_atom'
// This should be the node corresponding to the terminator.Its type can be the `number',
// `string'. `table reference' etc.
typedef struct {
    enum atom_types type;
    union {
        long number;
        char *string;
        int subtok;
    } value;

} ast_node_atom;

// This function will generate a new item of the teminator
// Return: the structure of `ast_node_atom' on success.
ast_node_atom* new_atom_node(enum atom_types type, void *v);

void delete_atom_node(ast_node_atom *node);

void print_node_atom(ast_node_atom *node);

// This function will add the parameter @v to the @node
ast_node_sexp *add_atom_node_to(ast_node_sexp *_node, enum atom_type type, void *v);


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
    ST_ATOM, ST_LIST, ST_NONE
};

struct _ast_node_sexp {
    enum sexp_types type;
    union {
        ast_node_atom *atom;
        ast_node_list *list;
    } value;
    void *next;
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


#ifdef __cplusplus
}
#endif


#endif //AST_H_
