//
// Created by falleuion on 6/24/18.
//

#include "parser.h"
#include "driver.h"
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

extern int driver(int ac, const char *av[])
{
    extern FILE *yyin;
    yydebug = 1;

    if(ac > 1 && !strcmp(av[1], "-d")) {
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


