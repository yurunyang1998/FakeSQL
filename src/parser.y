%require "3.0.4"
%{

#include <stdarg.h>
#include <string.h>
#include <stdlib.h>

void emit(char *s, ...);
void yyerror(char *, ...);
int yylex();

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

%token ADD
%token ALL
%token ALTER
%token ANALYZE
%token AND
%token AS
%token ASC

%token BEFORE
%token BETWEEN
%token BIGINT
%token BIT
%token BY
%token BINARY
%token BOTH

%token CALL
%token CASE
%token CASCADE
%token CHANGE
%token CHAR
%token CHECK
%token COLLATE
%token COLUMN
%token COMMIT
%token CONDITION
%token CONSTRAINT
%token CONTINUE
%token CONVERT
%token CREATE
%token CROSS
%token CURRENT_DATE
%token CURRENT_TIME
%token CURRENT_TIMESTAMP
%token CURRENT_USER
%token CURSOR
%token CYCLE

%token DATA
%token DATABASE
%token DATE
%token DAY
%token DEC
%token DECIMAL
%token DEFAULT
%token DECLARE
%token DEFERRABLE
%token DELETE
%token DEPTH
%token DESCRIBE
%token DESC
%token DISTINCT
%token DISTINCTROW
%token DOUBLE
%token DROP
%token DYNAMIC

%token EACH
%token ELSE
%token END
%token EQUALS
%token ESCAPE
%token EVERY
%token EXCEPT
%token EXCEPTION
%token <subtok> EXISTS
%token EXEC

%token FETCH
%token FIRST
%token FLOAT
%token FOR
%token FORCE
%token FOREIGN
%token FROM
%token FULL
%token FUNCTION

%token GLOBAL
%token GROUP
%token GRANT
%token GROUPING

%token HAVING
%token HOST
%token HOUR
%token HIGH_PRIORITY

%token IDENTITY
%token IGNORE
%token IN
%token IF
%token INDICATOR
%token INDEX
%token INNER
%token INOUT
%token INPUT
%token INSERT
%token INTEGER
%token INITIALIZE
%token TINYINT
%token INTERVAL
%token INTO
%token IS
%token ISOLATION

%token JOIN

%token KEY

%token LANGUAGE
%token LARGE
%token LEADING
%token LAST
%token LEFT
%token LESS
%token LOOP
%token LIKE
%token LIMIT

%token MINUTE
%token MOD
%token MODIFIES
%token MODIFY
%token MODULE
%token MONTH

%token NATIONAL
%token NAMES
%token NEW
%token NEXT
%token NO
%token NONE
%token NOT
%token NULLOP
%token NUMERIC
%token NATURAL

%token OBJECT
%token OF
%token OFF
%token OLD
%token ON
%token ONDUPLICATE
%token ONLY
%token OPEN
%token OPERATION
%token OPTION
%token OR
%token ORDER
%token OUTER
%token OUTPUT

%token PRIMARY
%token PUBLIC

%token REFERENCES
%token RELATIVE
%token RESTRICT
%token RESULT
%token RIGHT
%token ROW
%token ROLLUP

%token SELECT
%token SESSION
%token SHOW
%token SET
%token SOME
%token SQL
%token SQLEXCEPTION
%token SQLSTATE
%token SQLWARNING
%token SQL_BIG_RESULT
%token SQL_CALC_FOUND_ROWS
%token SQL_SMALL_RESULT
%token SSL
%token STATE
%token STRUCTURE
%token STRAIGHT_JOIN

%token TABLE
%token TEXT
%token TINYTEXT
%token TEMPORARY
%token THEN
%token TO
%token TIME
%token TIMESTAMP
%token TRAILING

%token UNDO
%token UNION
%token UNIQUE
%token UNSIGNED
%token USE
%token USER
%token USING
%token UPDATE

%token VALUE
%token VALUES
%token VARCHAR
%token VARBINARY

%token WHEN
%token WHENEVER
%token WHERE
%token WHILE
%token WRITE
%token WITH
%token WITHOUT

%token XOR

%token YEAR
%token YEAR_MONTH

%token ZEROFILL

%token FSUBSTRING
%token FTRIM
%token FDATE_ADD FDATE_SUB
%token FCOUNT


%type <intval> select_opts select_expr_list
%type <intval> groupby_list opt_with_rollup opt_asc_desc
/** %type <intval> val_list */
%type <intval> table_references opt_inner_cross opt_left_or_right_outer
%type <intval> column_list left_or_right opt_outer
%type <intval> index_list opt_for_join

%start stmt_list

%%

stmt_list: stmt ';'
    | stmt_list stmt ';'
    ;

stmt: select_stmt { ("STMT"); }
    ;

select_stmt: SELECT select_opts select_expr_list { emit("SELECTNODATA %d %d", $2, $3); };
    | SELECT select_opts select_expr_list FROM table_references opt_where opt_groupby opt_having
        opt_limit opt_into_list { emit("SELECT %d %d %d", $2, $3, $5); };
    ;

opt_where:
    | WHERE expr { emit("WHERE"); }
    ;

opt_groupby:
    | GROUP BY groupby_list opt_with_rollup { emit("GROUPBYLIST %d %d", $3, $4); }
    ;

groupby_list: expr opt_asc_desc { emit("GROUPBY %d", $2); $$ = 1; }
    | groupby_list ',' expr opt_asc_desc { emit("GROUPBY %d", $4); $$ = $1 + 1; }
    ;

opt_asc_desc:       { $$ = 0; }
    | ASC           { $$ = 0; }
    | DESC          { $$ = 1; }
    ;

opt_with_rollup:    { $$ = 0; }
    | WITH ROLLUP   { $$ = 1; }
    ;

opt_having:
    | HAVING expr   { emit("HAVING"); }
    ;

opt_orderby:
    | ORDER BY groupby_list { emit("ORDER BY %d", $3); }
    ;

opt_limit:
    | LIMIT expr    { emit("LIMIT 1"); }
    | LIMIT expr ',' expr { emit("LIMIT 2"); }
    ;

opt_into_list:
    | INTO column_list  { emit("INTO %d", $2); }
    ;

column_list: NAME       { emit("COLUMN %s", $1); free($1); $$ = 1; }
    | column_list ',' NAME  { emit("COLUMN %s", $3); free($3); $$ = $1 + 1;}
    ;

select_opts:                            { $$ = 0; }
    | select_opts ALL                   { if($$ & 01) exit(-1); $$ = $1 | 01; }
    | select_opts DISTINCT              { if($$ & 02) exit(-2); $$ = $1 | 02; }
    | select_opts DISTINCTROW           { if($$ & 04) exit(-3); $$ = $1 | 04; }
    | select_opts HIGH_PRIORITY         { if($$ & 010) exit(-4); $$ = $1 | 010; }
    | select_opts STRAIGHT_JOIN         { if($$ & 020) exit(-5); $$ = $1 | 020; }
    | select_opts SQL_SMALL_RESULT      { if($$ & 040) exit(-6); $$ = $1 | 040; }
    | select_opts SQL_BIG_RESULT        { if($$ & 0100) exit(-7); $$ = $1 | 0100; }
    | select_opts SQL_CALC_FOUND_ROWS   { if($$ & 0200) exit(-8); $$ = $1 | 0200; }
    ;

select_expr_list: select_expr           { $$ = 1;}
    | select_expr_list ',' select_expr  { $$ = $1 + 1; }
    | '*'                               { emit("SELECTALL"); $$ = 1; }
    ;

select_expr: expr opt_as_alias ;

table_references: table_reference           { $$ = 1; }
    | table_references ',' table_reference  { $$ = $1 + 1; }
    ;

table_reference: table_factor
    | join_table
    ;

table_factor: NAME opt_as_alias index_hint  { emit("TABLE %s", $1); free($1); }
    | NAME '.' NAME opt_as_alias index_hint { emit("TABLE %s.%s", $1, $3); free($1); free($3); }
    | table_subquery opt_as NAME            { emit("SUBQUERY %s", $3); free($3); }
    | '(' table_references ')'              { emit("TABLEREFERENCES %d", $2); }
    ;

opt_as: AS
    |
    ;

opt_as_alias: AS NAME       { emit("ALIAS %s", $2); free($2); }
    | NAME                  { emit("ALIAS %s", $1); free($1); }
    ;

join_table: table_reference opt_inner_cross JOIN table_factor opt_join_condition        { emit("JOIN %d", 0100 + $2); }
    | table_reference STRAIGHT_JOIN table_factor                                        { emit("JOIN %d", 0200); }
    | table_reference STRAIGHT_JOIN table_factor ON expr                                { emit("JOIN %d", 0200); }
    | table_reference left_or_right opt_outer JOIN table_factor join_condition          { emit("JOIN %d", 0300 + $2 + $3); }
    | table_reference NATURAL opt_left_or_right_outer JOIN table_factor                 { emit("JOIN %d", 0400 + $3); }
    ;

opt_inner_cross:    { $$ = 0; }
    | INNER { $$ = 1; }
    | CROSS { $$ = 2; }
    ;

opt_outer:  { $$ = 0; }
    | OUTER { $$ = 4; }
    ;

left_or_right: LEFT { $$ = 1; }
    | RIGHT { $$ = 0; }
    ;

opt_left_or_right_outer: LEFT opt_outer { $$ = 1 + $2; }
    | RIGHT opt_outer   { $$ = 2 + $2; }
    |   { $$ = 0; }
    ;

opt_join_condition: join_condition
    |
    ;

join_condition: ON expr { emit("ONEXPR"); }
    | USING '(' column_list ')' { emit("using %s", $3); }
    ;

index_hint: USE KEY opt_for_join '(' index_list ')' { emit("INDEXHINT %d %d", $5, 010 + $3); }
    | IGNORE KEY opt_for_join '(' index_list ')'    { emit("INDEXHINT %d %d", $5, 020 + $3); }
    | FORCE KEY opt_for_join '(' index_list ')'     { emit("INDEXHINT %d %d", $5, 030 + $3); }
    |
    ;

opt_for_join: FOR JOIN      { $$ = 1; }
    |                       { $$ = 0; }
    ;
index_list: NAME            { emit("INDEX %s", $1); free($1); $$ = 1; }
    | index_list ',' NAME   { emit("INDEX %s", $3); free($3); $$ = $1 + 1; }
    ;

table_subquery: '(' select_stmt ')'     { emit("SUBQUERY"); }
    ;


/** demo expressions (Just for compiler) **/
expr:   NAME            { emit("NAME %s", $1); free($1); }
    | USERVAR           { emit("USERVAR %s", $1); free($1); }
    | NAME '.' NAME     { emit("FIELDNAME %s.%s", $1, $3); free($1); free($3); }
    | STRING            { emit("STRING %s", $1); free($1); }
    | INTNUM            { emit("NUMBER %d", $1); }
    | APPROXNUM         { emit("FLOAT %g", $1); }
    | BOOL              { emit("BOOL %d", $1); }
    ;


%%


/* for linker non error */
void emit(char *s, ...)
{

    return ;
}

void yyerror(char *s, ...)
{

    return ;
}