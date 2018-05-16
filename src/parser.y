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

%right ASSIGN
%left OR
%left XOR
%left ANDOP
%nonassoc IN IS LIKE REGEXP
%left NOT '!'
%left BETWEEN
%left <subtok> COMPARSION
%left '|'
%left '&'
%left '+' '-'
%left '*' '/' MOD '%'
%left '^'
%nonassoc UMINUS

%start stmt_list

%%

stmt_list: stmt ';'
    | stmt_list stmt ';'
    ;

