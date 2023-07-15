#define BUYUKHARF 257
#define KUCUKHARF 258
#define CIZGI 259
#define KUCUKOPR 260
#define BUYUKOPR 261
#define SEMICOLON 262
#ifdef YYSTYPE
#undef  YYSTYPE_IS_DECLARED
#define YYSTYPE_IS_DECLARED 1
#endif
#ifndef YYSTYPE_IS_DECLARED
#define YYSTYPE_IS_DECLARED 1
typedef union
{
	char *str;
} YYSTYPE;
#endif /* !YYSTYPE_IS_DECLARED */
extern YYSTYPE yylval;
