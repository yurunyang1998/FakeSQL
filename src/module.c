//
// Created by falleuion on 8/17/18.
//

#include "module.h"
#include "parser.h"
#include "scanner.h"

#ifdef __cplusplus
extern "C" {
#endif


module *new_module_from_string(char *src)
{
    module *mod = (module *) malloc(sizeof(module));
    mod->src.filefp = fmemopen(src, strlen(src) + 1, "r");
    return mod;
}

void delete_module(module* mod)
{
    if(mod->root != NULL) {
        del_oprt_node(mod->root);
    }
    fclose(mod->src.filefp);
    free(mod);
}

int parse_module(module* mod)
{
    yyscan_t sc;
    int res;

    yydebug = 1;

    yylex_init(&sc);
    yyset_in(mod->src.filefp, sc);
    res = yyparse(sc, mod);
    yylex_destroy(sc);

//    if(res == 0) {
//        print_node_sexp(mod->root);
//    }

    return res;
}

#ifdef __cplusplus
}
#endif