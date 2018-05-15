%option noyywrap nodefault yylineno

%{
#include <stdarg.h>
#include <string.h>

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

%%