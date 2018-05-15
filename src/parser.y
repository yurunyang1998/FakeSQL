%{

#include <stdarg.h>
#include <string.h>
#include <stdlib.h>

void emit(char *s, ...);

%}

%union {
    int intval;
    double floatval;
    char *strval;
    int subtok;
}

%token <strval> NAME
%token <strval> STRING
%token <intval> INTNUM
%token <intval> BOOL
%token <floatval> APPROXNUM
%token <strval> USERVAR

