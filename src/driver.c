//
// Created by falleuion on 6/24/18.
//

#include "parser.h"
#include "driver.h"
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <stdarg.h>

extern int driver(int ac, const char *av[])
{
    extern FILE *yyin;

    if(ac > 1 && !strcmp(av[1], "-d")) {
        yydebug = 1;
        ac--;
        av++;
    }

    if(ac > 1 && (yyin = fopen(av[1], "r")) == NULL) {
        perror(av[1]);
        exit(1);
    }

    if(!yyparse())
        printf("SQL parse worked\n");
    else
        printf("SQL parse failed\n");

    return 0;
}


static unsigned sample_hash(char *sym)
{
    unsigned int hash = 0;
    char c;

    while(*sym)
    {
        c = *sym;
        hash = hash * 9 ^ c;
        sym++;
    }

    return hash;
}


extern struct symbol *lookup(context_t *context, char *symbol)
{
    struct symbol *sp = &(context->symtab)[sample_hash(symbol) % NHASH];
    int score = NHASH;

    while(--score >= 0) {
        if(sp->name && !strcmp(sp->name, symbol)) {
            return sp;
        }

        if(!sp->name) {
            sp->name = strdup(symbol);
            sp->func = NULL;
            sp->value = 0;
            sp->syms = NULL;

            return sp;
        }

        if(++sp >= symtab + NHASH) {
            sp = symtab;
        }
    }
    yyerror(context, "Symbol table overflow\n");
    exit(-1);
}


extern void yyerror(context_t *context, char *s, ...)
{
    va_list ap;
    va_start(ap, s);

    fprintf(stderr, "%d: error: ", yyget_lineno(context->scaninfo));
    vfprintf(stderr, s, ap);
    fprintf(stderr, "\n");
}
