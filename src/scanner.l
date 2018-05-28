%option noyywrap yylineno case-insensitive
/* %option yyclass="base_utils::cmd_scanner" */

%{
#include <stdarg.h>
#include <string.h>
#include "parser.h"

int old_state;

%}

%x COMMENT
%s BTWMODE

%%

ADD                 { return ADD; }
ALL                 { return ALL; }
ALTER               { return ALTER; }
ANALYZE             { return ANALYZE; }

<BTWMODE>AND        { BEGIN INITIAL; return AND; }
AND                 { return ANDOP; }
AS                  { return AS; }
ASC                 { return ASC; }

BEFORE              { return BEFORE; }
BETWEEN             { return BETWEEN; }
INT8|BIGINT         { return BIGINT; }
BIT                 { return BIT; }
BOTH                { return BOTH; }
BY                  { return BY; }
BINARY              { return BINARY; }

CALL                { return CALL; }
CASE                { return CASE; }
CASCADE             { return CASCADE; }
CHANGE              { return CHANGE; }
CHAR(ACTER?)        { return CHAR; }
CHECK               { return CHECK; }
COLLATE             { return COLLATE; }
COLUMN              { return COLUMN; }
COMMIT              { return COMMIT; }
CONDITION           { return CONDITION; }
CONSTRAINT          { return CONSTRAINT; }
CONTINUE            { return CONTINUE; }
CONVERT             { return CONVERT; }
CREATE              { return CREATE; }
CROSS               { return CROSS; }
CURRENT_DATE        { return CURRENT_DATE; }
CURRENT_TIME        { return CURRENT_TIME; }
CURRENT_TIMESTAMP   { return CURRENT_TIMESTAMP; }
CURRENT_USER        { return CURRENT_USER; }
CURSOR              { return CURSOR; }
CYCLE               { return CYCLE; }

DATA                { return DATA; }
DATABASE            { return DATABASE; }
DATE                { return DATE; }
DAY                 { return DAY; }
DEC                 { return DEC; }
DESC                { return DESC; }
DECIMAL             { return DECIMAL; }
DEFAULT             { return DEFAULT; }
DECLARE             { return DECLARE; }
DEFERRABLE          { return DEFERRABLE; }
DELETE              { return DELETE; }
DEPTH               { return DEPTH; }
DESCRIBE            { return DESCRIBE; }
DISTINCT            { return DISTINCT; }
DISTINCTROW         { return DISTINCTROW; }
DOUBLE              { return DOUBLE; }
DROP                { return DROP; }
DYNAMIC             { return DYNAMIC; }

EACH                { return EACH; }
ELSE                { return ELSE; }
END                 { return END; }
EQUALS              { return EQUALS; }
ESCAPE              { return ESCAPE; }
EVERY               { return EVERY; }
EXCEPT              { return EXCEPT; }
EXCEPTION           { return EXCEPTION; }
EXEC                { return EXEC; }

FETCH               { return FETCH; }
FIRST               { return FIRST; }
FLOAT               { return FLOAT; }
FOR                 { return FOR; }
FORCE               { return FORCE; }
FOREIGN             { return FOREIGN; }
FROM                { return FROM; }
FULL                { return FULL; }
FUNCTION            { return FUNCTION; }

GLOBAL              { return GLOBAL; }
GROUP               { return GROUP; }
GRANT               { return GRANT; }
GROUPING            { return GROUPING; }

HAVING              { return HAVING; }
HOST                { return HOST; }
HOUR                { return HOUR; }

IDENTITY            { return IDENTITY; }
IGNORE              { return IGNORE; }
IN                  { return IN; }
IF                  { return IF; }
INDICATOR           { return INDICATOR; }
INDEX               { return INDEX; }
INITIALIZE          { return INITIALIZE; }
INNER               { return INNER; }
INOUT               { return INOUT; }
INPUT               { return INPUT; }
INSERT              { return INSERT; }
INT4|INTEGER        { return INTEGER; }
INT1|TINYINT        { return TINYINT; }
INTERVAL            { return INTERVAL; }
INTO                { return INTO; }
IS                  { return IS; }
ISOLATION           { return ISOLATION; }

JOIN                { return JOIN; }

KEY                 { return KEY; }

LANGUAGE            { return LANGUAGE; }
LARGE               { return LARGE; }
LEADING             { return LEADING; }
LAST                { return LAST; }
LEFT                { return LEFT; }
LESS                { return LESS; }
LOOP                { return LOOP; }
LIKE                { return LIKE; }
LIMIT               { return LIMIT; }
LOW_PRIORITY        { return LOW_PRIORITY; }

MINUTE              { return MINUTE; }
MOD                 { return MOD; }
MODIFIES            { return MODIFIES; }
MODIFY              { return MODIFY; }
MODULE              { return MODULE; }
MONTH               { return MONTH; }

NAMES               { return NAMES; }
NATIONAL            { return NATIONAL; }
NATURAL             { return NATURAL; }
NEW                 { return NEW; }
NEXT                { return NEXT; }
NO                  { return NO; }
NONE                { return NONE; }
NOT                 { return NOT; }
NULL                { return NULLOP; }
NUMERIC             { return NUMERIC; }

OBJECT              { return OBJECT; }
OF                  { return OF; }
OFF                 { return OFF; }
OLD                 { return OLD; }
ON                  { return ON; }
ON[ \t\n]+DUPLICATE { return ONDUPLICATE; }
ONLY                { return ONLY; }
OPEN                { return OPEN; }
OPERATION           { return OPERATION; }
OPTION              { return OPTION; }
OR                  { return OR; }
ORDER               { return ORDER; }
OUTER               { return OUTER; }
OUTPUT              { return OUTPUT; }

PRIMARY             { return PRIMARY; }
PUBLIC              { return PUBLIC; }

QUICK               { return QUICK; }

REFERENCES          { return REFERENCES; }
RELATIVE            { return RELATIVE; }
RESTRICT            { return RESTRICT; }
RESULT              { return RESULT; }
RIGHT               { return RIGHT; }
ROLLUP              { return ROLLUP; }
ROW                 { return ROW; }

SELECT              { return SELECT; }
SESSION             { return SESSION; }
SHOW                { return SHOW; }
SET                 { return SET; }
SOME                { return SOME; }
SQL                 { return SQL; }
SQLEXCEPTION        { return SQLEXCEPTION; }
SQLSTATE            { return SQLSTATE; }
SQLWARNING          { return SQLWARNING; }
SQL_BIG_RESULT      { return SQL_BIG_RESULT; }
SQL_CALC_FOUND_ROWS { return SQL_CALC_FOUND_ROWS; }
SQL_SMALL_RESULT    { return SQL_SMALL_RESULT; }
SSL                 { return SSL; }
STATE               { return STATE; }
STRUCTURE           { return STRUCTURE; }
STRAIGHT_JOIN       { return STRAIGHT_JOIN; }
SCHEMA              { return SCHEMA; }
SCHEMAS             { return SCHEMAS; }

TABLE               { return TABLE; }
TEXT                { return TEXT; }
TINYTEXT            { return TINYTEXT; }
TEMPORARY           { return TEMPORARY; }
THEN                { return THEN; }
TO                  { return TO; }
TIME                { return TIME; }
TIMESTAMP           { return TIMESTAMP; }
TRAILING            { return TRAILING; }

UNDO                { return UNDO; }
UNION               { return UNION; }
UNIQUE              { return UNIQUE; }
UNSIGNED            { return UNSIGNED; }
USE                 { return USE; }
USER                { return USER; }
USING               { return USING; }
UPDATE              { return UPDATE; }

VALUE               { return VALUE; }
VALUES              { return VALUES; }
VARCHAR             { return VARCHAR; }
VARBINARY           { return VARBINARY; }

WHEN                { return WHEN; }
WHENEVER            { return WHENEVER; }
WHERE               { return WHERE; }
WHILE               { return WHILE; }
WRITE               { return WRITE; }
WITH                { return WITH; }
WITHOUT             { return WITHOUT; }

XOR                 { return XOR; }

YEAR                { return YEAR; }
YEAR_MONTH          { return YEAR_MONTH; }

ZEROFILL            { return ZEROFILL; }

-?[0-9]+            { yylval.intval = atoi(yytext); return INTNUM; }

-?[0-9]+"."[0-9]* |
-?"."[0-9]+ |
-?[0-9]+E[-+]?[0-9]+ |
-?[0-9]+"."[0-9]*E[-+]?[0-9]+ |
-?"."[0-9]+E[-+]?[0-9]+ { yylval.floatval = atof(yytext); return APPROXNUM; }

TRUE                { yylval.intval = 1; return BOOL; }
UNKNOWN             { yylval.intval = -1; return BOOL; }
FALSE               { yylval.intval = 0; return BOOL; }

'(\\.|''|[^'\n])*' |
\"(\\.|\"\"|[^"\n])*\" { yylval.strval = strdup(yytext); return STRING; }

X'[0-9A-F]+' |
0X[0-9A-F]+         { yylval.strval = strdup(yytext); return STRING; }

B'[01]+'            { yylval.strval = strdup(yytext); return STRING; }


[-+&~|^/%*(),.:!]   { return yytext[0]; }

"&&"                { return ANDOP; }
"||"                { return OR; }
"="                 { yylval.subtok = 1; return COMPARSION; }
">"                 { yylval.subtok = 2; return COMPARSION; }
">="                { yylval.subtok = 3; return COMPARSION; }
"<"                 { yylval.subtok = 4; return COMPARSION; }
"<="                { yylval.subtok = 5; return COMPARSION; }
"!="|"<>"           { yylval.subtok = 6; return COMPARSION; }
":="                { return ASSIGN; }

SUBSTR(ING)?/"("    { return FSUBSTRING; }
TRIM/"("            { return FTRIM; }
DATE_ADD/"("        { return FDATE_ADD; }
DATE_SUB/"("        { return FDATE_SUB; }

COUNT               { int c = input(); unput(c); if(c == '(') return FCOUNT; yylval.strval = strdup(yytext); return NAME; }

[A-Za-z][A-Za-z0-9_]* { yylval.strval = strdup(yytext); return NAME; }

`[^'/\\.\n]+`       { yylval.strval = strdup(yytext + 1); yylval.strval[yyleng - 2] = 0; return NAME; }


@[0-9a-z_.$]+ |
@\"[^"\n]+\" |
@`[^`\n]+` |
@'[^'\n]+'          { yylval.strval = strdup(yytext + 1); return USERVAR; }

#.* ;
"--"[ \t].* ;
"/*"                { old_state = YY_START; BEGIN COMMENT; }
<COMMENT>"*/"       { BEGIN old_state; }
<COMMENT>.|\n ;

%%

