//
// Created by falleuion on 6/24/18.
//

#ifndef FAKESQL_DRIVER_H
#define FAKESQL_DRIVER_H

#include <scanner.h>

#ifdef __cplusplus
extern "C"
{
#endif

    typedef struct par_context {
        yyscan_t scaninfo;
        struct symbol *symtab;
        struct ast *ast;
    } context_t;

    struct symbol {
        char *name;
        double value;
        struct ast *func;
        struct symlist *syms;
    };

    struct symlist {
        struct symbol *sym;
        struct symlist *next;
    };

    struct ast {
        int node_type;
        struct ast *left;
        struct ast *right;
    };


#define NHASH 9997
    struct symbol symtab[NHASH];


    // built-in functions
    // TODO:暂时为实现...这或许就是有生之年
    enum bifs {
        // SQL String Functions
        B_ASCII = 1,
        B_CHAR,
        B_CHARINDEX,
        B_LEFT,
        B_LEN,
        B_LOWER,
        B_LTRIM,
        B_NCHAR,
        B_PATINDEX,
        B_REPLACE,
        B_RIGHT,
        B_RTRIM,
        B_SPACE,
        B_STR,
        B_STUFF,
        B_SUBSTRING,
        B_UPPER,

        // SQL Numeric Functions

    };


    // built-in function
    struct fncall {
        int node_type;
        struct ast *left;
        enum bifs func_type;
    };

    // comparison
    struct condition {
        int node_type;
        struct ast *competition;
        struct ast *left;
        struct ast *right;
    };

    // if-else sentence
    struct flow {
        int node_type;
        struct ast *cond;
        struct ast *tl;
        struct ast *el;
    };

    struct numval {
        int node_type;
        double value;
    };

    struct symref {
        int node_type;
        struct symbol *value;
    };

    struct symasgn {
        int node_type;
        struct symbol *sym;
        struct ast *value;
    };

    struct symbol *lookup(context_t *, char *);
    int driver(int, const char**);
    void yyerror(context_t *, char *s, ...);

#ifdef __cplusplus
}
#endif

#endif //FAKESQL_DRIVER_H
