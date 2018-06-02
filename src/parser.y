%require "3.0.4"
%{

#include <stdio.h>
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
%left <subtok> SHIFT
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
%token DELAYED
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
%token LOW_PRIORITY

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

%token QUICK

%token REFERENCES
%token RELATIVE
%token RESTRICT
%token RESULT
%token RIGHT
%token ROW
%token ROLLUP
%token REPLACE

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
%token SCHEMA
%token SCHEMAS

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
%type <intval> index_list opt_for_join delete_opts delete_list
%type <intval> opt_if_not_exists insert_opts insert_vals_list insert_asgn_list
%type <intval> insert_vals update_opts update_asgn_list


%left <subtok> COMPARISON

%start stmt_list

%%

stmt_list: stmt ';'
    | stmt_list stmt ';'
    ;

stmt: select_stmt { emit("STMT"); }
    ;

/* create database */

stmt: create_database_stmt      { emit("STMT"); }
    ;

create_database_stmt: CREATE DATABASE opt_if_not_exists NAME    { emit("CREATEDATABASE %d %s", $3, $4); free($4); }
    | CREATE SCHEMA opt_if_not_exists NAME                      { emit("CREATEDATABASE %d %s", $3, $4); free($4); }
    ;

/* force stop when error arise */
opt_if_not_exists:  { $$ = 0; }
    | IF EXISTS     { if(!$2) exit(-1); $$ = $2; }
    ;


/* SELECT sentence */
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


/* DELETE sentence */

stmt: delete_stmt       { emit("STMT"); }
    ;

delete_stmt: DELETE delete_opts FROM NAME opt_where opt_orderby opt_limit { emit("DELETEONE %d %s", $2, $4); free($4); }
    ;

delete_opts: delete_opts LOW_PRIORITY   { $$ = $1 + 0x01; }
    | delete_opts QUICK                 { $$ = $1 + 0x02; }
    | delete_opts IGNORE                { $$ = $1 + 0x04; }
    |                                   { $$ = 0; }
    ;

delete_stmt: DELETE delete_opts delete_list FROM table_references opt_where { emit("DELETEMULTI %d %d %d", $2, $3, $5); }

delete_list: NAME opt_dot_star          { emit("TABLE %s", $1); free($1); $$ = 1; }
    | delete_list ',' NAME opt_dot_star { emit("TABLE %s", $3); free($3);  $$ = $1 + 1; }
    ;

opt_dot_star:
    | '.' '*'
    ;

delete_stmt: DELETE delete_opts FROM delete_list USING table_references opt_where   { emit("DELETEMULTI %d %d %d", $2, $4, $6); }
    ;


/* INSERT sentence */
stmt: insert_stmt       { emit("STMT"); }
    ;

insert_stmt: INSERT insert_opts opt_into NAME opt_col_names VALUES insert_vals_list
           opt_ondupupdate  { emit("INSERTVALS %d %d %s", $2, $7, $4); free($4); }
    ;

opt_ondupupdate:
    | ONDUPLICATE KEY UPDATE insert_asgn_list   { emit("DUPUPDATE %d", $4); }
    ;

insert_opts:        { $$ = 0; }
    | insert_opts LOW_PRIORITY  { $$ = $1 | 0x01; }
    | insert_opts DELAYED       { $$ = $1 | 0x02; }
    | insert_opts HIGH_PRIORITY { $$ = $1 | 0x04; }
    | insert_opts IGNORE        { $$ = $1 | 0x05; }
    ;

opt_into: INTO
    |
    ;

opt_col_names:
    | '(' column_list ')'   { emit("INSERTCOLS %d", $2); }
    ;

insert_vals_list: '(' insert_vals ')'   { emit("VALUES %d", $2); $$ = 1; }
    | insert_vals_list ',' '(' insert_vals ')' { emit("VALUES %d", $4); $$ = $1 + 1; }

insert_vals: expr   { $$ = 1; }
    | DEFAULT       { emit("DEFAULT"); $$ = 1; }
    | insert_vals ',' expr      { $$ = $1 + 1; }
    | insert_vals ',' DEFAULT   { emit("DEFAULT"); $$ = $1 + 1; }
    ;

insert_stmt: INSERT insert_opts opt_into NAME SET insert_asgn_list opt_ondupupdate
           { emit("INSERTASGN %d %d %s", $2, $6, $4); free($4); }
    ;

insert_stmt: INSERT insert_opts opt_into NAME opt_col_names select_stmt opt_ondupupdate
           { emit("INSERTSELECT %d %s", $2, $4); free($4); }
    ;

insert_asgn_list: NAME COMPARISON expr              { if($2 != 4) { printf("bad insert assignment to %s\n", $1); exit(-2); }
                emit("ASSIGN %s", $1); free($1); $$ = 1; }
    | NAME COMPARISON DEFAULT                       { if($2 != 4) { printf("bad insert assignment to %s\n", $1); exit(-2); }
                emit("DEFAULT"); emit("ASSIGN %s", $1); free($1); $$ = 1; }
    | insert_asgn_list ',' NAME COMPARISON expr     { if($4 != 4) { printf("bad insert assignment to %s\n", $1); exit(-2); }
                emit("ASSIGN %s", $3); free($3); $$ = $1 + 1; }
    | insert_asgn_list ',' NAME COMPARISON DEFAULT  { if($4 != 4) { printf("bad insert assignment to %s\n", $1); exit(-2); }
                emit("DEFAULT"); emit("ASSIGN %s", $3); free($3); $$ = $1 + 1; }
    ;


/* REPLACE sentence */
stmt: replace_stmt  { emit("STMT"); }
    ;

replace_stmt: REPLACE insert_opts opt_into NAME
            opt_col_names VALUES insert_vals_list
            opt_ondupupdate     { emit("REPLACEVALS %d %d %s", $2, $7, $4); free($4); }
    ;

replace_stmt: REPLACE insert_opts opt_into NAME
            SET insert_asgn_list opt_ondupupdate
            { emit("REPLACEASGN %d %d %s", $2, $6, $4); free($4); }
    ;

replace_stmt: REPLACE insert_opts opt_into NAME
            opt_col_names select_stmt opt_ondupupdate
            { emit("REPLACESELECT %d %s", $2, $4); free($4); }
    ;


/* UPDATE sentence */
stmt: update_stmt   { emit("STMT"); }
    ;

update_stmt: UPDATE update_opts table_references SET update_asgn_list
           opt_where opt_orderby opt_limit  { emit("UPDATE %d %d %d", $2, $3, $5); }
    ;

update_opts:    { $$ = 0; }
    | insert_opts LOW_PRIORITY  { $$ = $1 | 0x01; }
    | insert_opts IGNORE        { $$ = $1 | 0x02; }
    ;

update_asgn_list: NAME COMPARISON expr                      { if($2 != 4) { printf("bad insert assignment to %s", $1); exit(-3); }
                emit("ASSIGN %s", $1); free($1); $$ = 1; }
    | NAME '.' NAME COMPARISON expr                         { if($4 != 4) { printf("bad insert assignment to %s", $1); exit(-3); }
                emit("ASSIGN %s.%s", $1, $3); free($1); free($3); $$ = 1; }
    | update_asgn_list ',' NAME COMPARISON expr             { if($4 != 4) { printf("bad insert assignment to %s", $3); exit(-3); }
                emit("ASSIGN %s", $3); free($3); $$ = 1; }
    | update_asgn_list ',' NAME '.' NAME COMPARISON expr    { if($6 != 4) { printf("bad insert assignment to %s.%s", $3, $5); exit(-3); }
                emit("ASSIGN %s.%s", $3, $5); free($3); free($5); $$ = 1;}
    ;


/* Create table sentence */

stmt: create_table_stmt { emit("STMT"); }
    ;

create_table_stmt: CREATE opt_temporary TABLE opt_if_not_exist NAME '(' create_col_list ')'
                 create_select_statement    { emit("CREATE %d %d %d %s", $2, $4, $7, $5); free($5); }
    ;

create_table_stmt: CREATE opt_temporary TABLE opt_if_not_exist NAME '.' NAME '(' create_col_list ')'
                 { emit("CREATE %d %d %d %s.%s", $2, $4, $9, $5, $7); free($5); free($7); }
    ;

create_table_stmt: CREATE opt_temporary TABLE opt_if_not_exist NAME '(' create_col_list ')'
                 create_select_statement    { emit("CREATESELECT %d %d %d 0 %s", $2, $4, $7, $5); free($5); }
    ;

create_table_stmt: CREATE opt_temporary TABLE opt_if_not_exist NAME '.' NAME '(' create_col_list ')'
                 create_select_statement    { emit("CREATESELECT %d %d 0 %s.%s", $2, $4, $5, $7); free($5); free($7); }
    ;

create_table_stmt: CREATE opt_temporary TABLE opt_if_not_exist NAME create_select_statement
                 { emit("CREATESELECT %d %d 0 %s", $2, $4, $5); free($5); }
    ;

create_table_stmt: CREATE opt_temporary TABLE opt_if_not_exist NAME '.' NAME create_select_statement
                 { emit("CREATESELECT %d %d 0 %s.%s", $2, $4, $5, $7); free($5); free($7); }
    ;

create_col_list: create_definition  { $$ = 1; }
    | create_col_list ',' create_definition { $$ = $1 + 1;}
    ;

create_definition: { emit("STARTCOL"); } NAME data_type column_atts { emit("COLUMNDEF %d %s", $3, $2); free($2); }
    | PRIMARY KEY '(' column_list ')'           { emit("PRIKEY %d", $4); }
    | KEY '(' column_list ')'                   { emit("KEY %d", $3); }
    | INDEX '(' column_list ')'                 { emit("KEY %d", $3); }
    | FULLTEXT INDEX '(' column_list ')'        { emit("TEXTINDEX %d", $4); }
    | FULLTEXT KEY '(' column_list ')'          { emit("TEXTINDEX %d", $4); }
    ;

column_atts:    { $$ = 0; }
    | column_atts NOT NULLX                     { emit("ATTR NOTNULL"); $$ = $1 + 1; }
    | column_atts NULLX
    | column_atts DEFAULT STRING                { emit("ATTR DEFAULT STRING %s", $3); free($3); $$ = $1 + 1; }
    | column_atts DEFAULT INTNUM                { emit("ATTR DEFAULT NUMBER %d", $3); free($3); $$ = $1 + 1; }
    | column_atts DEFAULT APPROXNUM             { emit("ATTR DEFAULT FLOAT %f", $3); $$ = $1 + 1; }
    | column_atts DEFAULT BOOL                  { emit("ATTR DEFAULT BOOL %d", $3); $$ = $1 + 1; }
    | column_atts AUTO_INCREMENT                { emit("ATTR AUTOINC"); $$ = $1 + 1; }
    | column_atts UNIQUE '(' column_list ')'    { emit("ATTR UNIQUEKEY %d", $4); $$ = $1 + 1; }
    | column_atts UNIQUE KEY                    { emit("ATTR UNIQUEKEY"); $$ = $1 + 1; }
    | column_atts PRIMARY KEY                   { emit("ATTR PRIKEY"); $$ = $1 + 1; }
    | column_atts KEY                           { emit("ATTR PRIKEY"); $$ = $1 + 1; }
    | column_atts COMMENT STRING                { emit("ATTR COMMENT %s", $3); free($3); $$ = $1 + 1; }
    ;

opt_length:             { $$ = 0; }
    | '(' INTNUM ')'    { $$ = $2; }
    | '(' INTNUM ',' INTNUM ')' { $$ = $2 + 1000 * $4; }
    ;

opt_binary:     { $$ = 0; }
    | BINARY    { $$ = 4000; }
    ;

opt_uz:                 { $$ = 0; }
    | opt_uz UNISGNED   { $$ = $1 | 1000; }
    | opt_uz ZEROFILL   { $$ = $1 | 2000; }
    ;

opt_csc:
    | opt_csc CHAR SET STRING { emit("COLCHARSET %s", $4); free($4); }
    | opt_csc COLLATE STRING  { emit("COLCOLLATE %s", $3); free($3); }
    ;

data_type: BIT opt_length                   { $$ = 10000 + $2; }
    | TINYINT opt_length opt_uz             { $$ = 10000 + $2; }
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
