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
%token DISTINCT
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
%token NEW
%token NEXT
%token NO
%token NONE
%token NOT
%token NULLOP
%token NUMERIC

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

%token SELECT
%token SESSION
%token SHOW
%token SET
%token SOME
%token SQL
%token SQLSTATE
%token SQLWARNING
%token SQL_BIG_RESULT
%token SQL_CALC_FOUND_ROWS
%token SQL_SMALL_RESULT
%token SSL
%token STATE
%token STRUCTURE

%token TABLE
%token TEXT
%token TINYTEXT
%token TEMPORARY
%token THEM
%token TO
%token TIME
%token TIMESTAMP
%token TRAILING

%token UNDO
%token UNION
%token UNIQUE
%token UNSIGNED
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
%type <intval> val_list opt_val_list case_list
%type <intval> table_reference

%start stmt_list

%%

stmt_list: stmt ';'
    | stmt_list stmt ';'
    ;

stmt: select_stmt { emit("STMT"); }
    ;

select_stmt: SELECT select_opts select_expr_list { emit("SELECTNODATA %d %d", $2, $3); };
    | SELECT select_opts select_expr_list FORM table_references opt_where opt_groupby opt_having
        opt_limit opt_into_list { emit("SELECT %d %d %d", $2, $3, $5); };
    ;

opt_where:
    | WHERE expr { emit("WHERE"); }
    ;

opt_groupby:
    | GROUP BY group_list opt_with_rollup { emit("GROUPBYLIST %d %d", $3, $4); }
    ;

groupby_list: expr opt_asc_desc { emit("GROUPBY %d", $2); $$ = 1}
    | groupby_list ',' expr opt_asc_desc { emit("GROUPBY %d", $4); $$ = $1 + 1}
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

