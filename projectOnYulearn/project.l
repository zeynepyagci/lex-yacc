%{
#include <stdio.h>
#include <string.h>
#include "y.tab.h"
int linenum=1;
%}
%%
[A-Z] {yylval.str = strdup(yytext);return BUYUKHARF;}
[a-z] {yylval.str = strdup(yytext);return KUCUKHARF;}
\-  return CIZGI;
\<  {yylval.str = strdup(yytext);return KUCUKOPR;}
\>  {yylval.str = strdup(yytext);return BUYUKOPR;}
\;  return SEMICOLON;
\n	linenum++;
[ \t]+
%%
