/* original parser id follows */
/* yysccsid[] = "@(#)yaccpar	1.9 (Berkeley) 02/21/93" */
/* (use YYMAJOR/YYMINOR for ifdefs dependent on parser version) */

#define YYBYACC 1
#define YYMAJOR 1
#define YYMINOR 9
#define YYPATCH 20140715

#define YYEMPTY        (-1)
#define yyclearin      (yychar = YYEMPTY)
#define yyerrok        (yyerrflag = 0)
#define YYRECOVERING() (yyerrflag != 0)
#define YYENOMEM       (-2)
#define YYEOF          0
#define YYPREFIX "yy"

#define YYPURE 0

#line 1 "project.y"

	#include <fstream>
	#include <vector>
	#include <sstream>
	#include <stdio.h>
	#include <iostream>
	#include <string>
	#include <string.h>
	#include <map>
	#include "y.tab.h"
	using namespace std;
	extern FILE *yyin;
	extern int yylex();
	extern int linenum;
	void yyerror(string s);
	vector<string> SUB;
	vector<string> INPUT;
	vector<string> LEFTHANDSIDE;
	vector<string> BEF;
	vector<string> REC;
	vector<string> ERR;
	string curr;
	string pre=" ";
	bool errorFlag = false;
	bool loopflag = false;

    FILE *out;
	
#line 31 "project.y"
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
#line 62 "y.tab.c"

/* compatibility with bison */
#ifdef YYPARSE_PARAM
/* compatibility with FreeBSD */
# ifdef YYPARSE_PARAM_TYPE
#  define YYPARSE_DECL() yyparse(YYPARSE_PARAM_TYPE YYPARSE_PARAM)
# else
#  define YYPARSE_DECL() yyparse(void *YYPARSE_PARAM)
# endif
#else
# define YYPARSE_DECL() yyparse(void)
#endif

/* Parameters sent to lex. */
#ifdef YYLEX_PARAM
# define YYLEX_DECL() yylex(void *YYLEX_PARAM)
# define YYLEX yylex(YYLEX_PARAM)
#else
# define YYLEX_DECL() yylex(void)
# define YYLEX yylex()
#endif

/* Parameters sent to yyerror. */
#ifndef YYERROR_DECL
#define YYERROR_DECL() yyerror(const char *s)
#endif
#ifndef YYERROR_CALL
#define YYERROR_CALL(msg) yyerror(msg)
#endif

extern int YYPARSE_DECL();

#define BUYUKHARF 257
#define KUCUKHARF 258
#define CIZGI 259
#define KUCUKOPR 260
#define BUYUKOPR 261
#define SEMICOLON 262
#define YYERRCODE 256
typedef short YYINT;
static const YYINT yylhs[] = {                           -1,
    0,    0,    3,    2,    1,    1,    1,    1,    1,    1,
};
static const YYINT yylen[] = {                            2,
    2,    1,    5,    3,    3,    4,    1,    2,    2,    2,
};
static const YYINT yydefred[] = {                         0,
    0,    0,    0,    0,    0,    0,    1,    4,    0,    0,
    0,    0,    0,    9,    8,    0,    3,    0,    6,
};
static const YYINT yydgoto[] = {                          2,
   13,    3,    4,
};
static const YYINT yysindex[] = {                      -257,
 -252,    0, -253, -257, -251, -250,    0,    0, -256, -249,
 -256, -248, -254,    0,    0, -247,    0, -256,    0,
};
static const YYINT yyrindex[] = {                         0,
    0,    0,    0,   13,    0,    0,    0,    0,    0,    0,
 -246,    0,    0,    0,    0, -245,    0, -244,    0,
};
static const YYINT yygindex[] = {                        11,
  -11,    0,    0,
};
#define YYTABLESIZE 18
static const YYINT yytable[] = {                         15,
   10,   11,    1,   12,    5,    6,   19,   17,   16,    8,
    9,   14,    2,   18,    7,    7,   10,    5,
};
static const YYINT yycheck[] = {                         11,
  257,  258,  260,  260,  257,  259,   18,  262,  257,  261,
  261,  261,    0,  261,    4,  262,  262,  262,
};
#define YYFINAL 2
#ifndef YYDEBUG
#define YYDEBUG 0
#endif
#define YYMAXTOKEN 262
#define YYUNDFTOKEN 268
#define YYTRANSLATE(a) ((a) > YYMAXTOKEN ? YYUNDFTOKEN : (a))
#if YYDEBUG
static const char *const yyname[] = {

"end-of-file",0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,"BUYUKHARF","KUCUKHARF","CIZGI",
"KUCUKOPR","BUYUKOPR","SEMICOLON",0,0,0,0,0,"illegal-symbol",
};
static const char *const yyrule[] = {
"$accept : statements",
"statements : statement statements",
"statements : statement",
"statement : lefthandside CIZGI BUYUKOPR input SEMICOLON",
"lefthandside : KUCUKOPR BUYUKHARF BUYUKOPR",
"input : KUCUKOPR BUYUKHARF BUYUKOPR",
"input : KUCUKOPR BUYUKHARF BUYUKOPR input",
"input : KUCUKHARF",
"input : KUCUKHARF input",
"input : BUYUKHARF BUYUKOPR",
"input : KUCUKOPR BUYUKHARF",

};
#endif

int      yydebug;
int      yynerrs;

int      yyerrflag;
int      yychar;
YYSTYPE  yyval;
YYSTYPE  yylval;

/* define the initial stack-sizes */
#ifdef YYSTACKSIZE
#undef YYMAXDEPTH
#define YYMAXDEPTH  YYSTACKSIZE
#else
#ifdef YYMAXDEPTH
#define YYSTACKSIZE YYMAXDEPTH
#else
#define YYSTACKSIZE 10000
#define YYMAXDEPTH  10000
#endif
#endif

#define YYINITSTACKSIZE 200

typedef struct {
    unsigned stacksize;
    YYINT    *s_base;
    YYINT    *s_mark;
    YYINT    *s_last;
    YYSTYPE  *l_base;
    YYSTYPE  *l_mark;
} YYSTACKDATA;
/* variables for the parser stack */
static YYSTACKDATA yystack;
#line 125 "project.y"


void yyerror(string s){
	cout<<"error at line: "<<linenum<<endl;
	errorFlag=true;
}
int yywrap(){
	return 1;
}

int main(int argc, char *argv[])
{
    /* Call the lexer, then quit. */

    yyin=fopen(argv[1],"r");
    yyparse();
	
	string kelime;
	int lefthandsize = LEFTHANDSIDE.size();
	int index;
	int linesayisi = LEFTHANDSIDE.size()+1;
	
	
	for(int i=0;i<LEFTHANDSIDE.size();i++){
		if(LEFTHANDSIDE[i]!=LEFTHANDSIDE[i+1]){
			index = i;
			//cout<<"index: "<<index<<endl;
			//cout<<"i: "<<i<<endl;
			kelime = LEFTHANDSIDE[i];
			//cout<<kelime<<endl;
			break;
		}
		
	}
	for(int i=lefthandsize ; i>index; i--)
	{
		
			
		if(LEFTHANDSIDE[i] == kelime)
		{	
			cout<<"In line "<<linesayisi<<", nonterminal "<<kelime<<" is at the wrong place"<<endl;
			loopflag=true;
			exit(1);
		}
		
		linesayisi--;

	}
	
	
	
	for(int i=0;i<LEFTHANDSIDE.size();i++){
		//cout<<LEFTHANDSIDE[i]<<" -> "<<INPUT[i]<<endl;
		if(LEFTHANDSIDE[i]==BEF[i]){
			if(curr!=pre){
				cout<<LEFTHANDSIDE[i]<<" -> "<<INPUT[i+1]<<" "<<REC[i]<<"2>"<<endl;
				cout<<REC[i]<<"2> -> epsilon"<<endl;
				cout<<REC[i]<<"2> -> "<<SUB[i]<<" "<<REC[i]<<"2>"<<endl;
				INPUT.pop_back();
				
			}
			
			pre==curr;
			//INPUT.pop_back();
		}
		else{
			
			//cout<<LEFTHANDSIDE[i]<<" -> "<<INPUT[i]<<endl;
			
		}
		
	}
	

	
	
    fclose(yyin);
	
    return 0;
}

#line 286 "y.tab.c"

#if YYDEBUG
#include <stdio.h>		/* needed for printf */
#endif

#include <stdlib.h>	/* needed for malloc, etc */
#include <string.h>	/* needed for memset */

/* allocate initial stack or double stack size, up to YYMAXDEPTH */
static int yygrowstack(YYSTACKDATA *data)
{
    int i;
    unsigned newsize;
    YYINT *newss;
    YYSTYPE *newvs;

    if ((newsize = data->stacksize) == 0)
        newsize = YYINITSTACKSIZE;
    else if (newsize >= YYMAXDEPTH)
        return YYENOMEM;
    else if ((newsize *= 2) > YYMAXDEPTH)
        newsize = YYMAXDEPTH;

    i = (int) (data->s_mark - data->s_base);
    newss = (YYINT *)realloc(data->s_base, newsize * sizeof(*newss));
    if (newss == 0)
        return YYENOMEM;

    data->s_base = newss;
    data->s_mark = newss + i;

    newvs = (YYSTYPE *)realloc(data->l_base, newsize * sizeof(*newvs));
    if (newvs == 0)
        return YYENOMEM;

    data->l_base = newvs;
    data->l_mark = newvs + i;

    data->stacksize = newsize;
    data->s_last = data->s_base + newsize - 1;
    return 0;
}

#if YYPURE || defined(YY_NO_LEAKS)
static void yyfreestack(YYSTACKDATA *data)
{
    free(data->s_base);
    free(data->l_base);
    memset(data, 0, sizeof(*data));
}
#else
#define yyfreestack(data) /* nothing */
#endif

#define YYABORT  goto yyabort
#define YYREJECT goto yyabort
#define YYACCEPT goto yyaccept
#define YYERROR  goto yyerrlab

int
YYPARSE_DECL()
{
    int yym, yyn, yystate;
#if YYDEBUG
    const char *yys;

    if ((yys = getenv("YYDEBUG")) != 0)
    {
        yyn = *yys;
        if (yyn >= '0' && yyn <= '9')
            yydebug = yyn - '0';
    }
#endif

    yynerrs = 0;
    yyerrflag = 0;
    yychar = YYEMPTY;
    yystate = 0;

#if YYPURE
    memset(&yystack, 0, sizeof(yystack));
#endif

    if (yystack.s_base == NULL && yygrowstack(&yystack) == YYENOMEM) goto yyoverflow;
    yystack.s_mark = yystack.s_base;
    yystack.l_mark = yystack.l_base;
    yystate = 0;
    *yystack.s_mark = 0;

yyloop:
    if ((yyn = yydefred[yystate]) != 0) goto yyreduce;
    if (yychar < 0)
    {
        if ((yychar = YYLEX) < 0) yychar = YYEOF;
#if YYDEBUG
        if (yydebug)
        {
            yys = yyname[YYTRANSLATE(yychar)];
            printf("%sdebug: state %d, reading %d (%s)\n",
                    YYPREFIX, yystate, yychar, yys);
        }
#endif
    }
    if ((yyn = yysindex[yystate]) && (yyn += yychar) >= 0 &&
            yyn <= YYTABLESIZE && yycheck[yyn] == yychar)
    {
#if YYDEBUG
        if (yydebug)
            printf("%sdebug: state %d, shifting to state %d\n",
                    YYPREFIX, yystate, yytable[yyn]);
#endif
        if (yystack.s_mark >= yystack.s_last && yygrowstack(&yystack) == YYENOMEM)
        {
            goto yyoverflow;
        }
        yystate = yytable[yyn];
        *++yystack.s_mark = yytable[yyn];
        *++yystack.l_mark = yylval;
        yychar = YYEMPTY;
        if (yyerrflag > 0)  --yyerrflag;
        goto yyloop;
    }
    if ((yyn = yyrindex[yystate]) && (yyn += yychar) >= 0 &&
            yyn <= YYTABLESIZE && yycheck[yyn] == yychar)
    {
        yyn = yytable[yyn];
        goto yyreduce;
    }
    if (yyerrflag) goto yyinrecovery;

    YYERROR_CALL("syntax error");

    goto yyerrlab;

yyerrlab:
    ++yynerrs;

yyinrecovery:
    if (yyerrflag < 3)
    {
        yyerrflag = 3;
        for (;;)
        {
            if ((yyn = yysindex[*yystack.s_mark]) && (yyn += YYERRCODE) >= 0 &&
                    yyn <= YYTABLESIZE && yycheck[yyn] == YYERRCODE)
            {
#if YYDEBUG
                if (yydebug)
                    printf("%sdebug: state %d, error recovery shifting\
 to state %d\n", YYPREFIX, *yystack.s_mark, yytable[yyn]);
#endif
                if (yystack.s_mark >= yystack.s_last && yygrowstack(&yystack) == YYENOMEM)
                {
                    goto yyoverflow;
                }
                yystate = yytable[yyn];
                *++yystack.s_mark = yytable[yyn];
                *++yystack.l_mark = yylval;
                goto yyloop;
            }
            else
            {
#if YYDEBUG
                if (yydebug)
                    printf("%sdebug: error recovery discarding state %d\n",
                            YYPREFIX, *yystack.s_mark);
#endif
                if (yystack.s_mark <= yystack.s_base) goto yyabort;
                --yystack.s_mark;
                --yystack.l_mark;
            }
        }
    }
    else
    {
        if (yychar == YYEOF) goto yyabort;
#if YYDEBUG
        if (yydebug)
        {
            yys = yyname[YYTRANSLATE(yychar)];
            printf("%sdebug: state %d, error recovery discards token %d (%s)\n",
                    YYPREFIX, yystate, yychar, yys);
        }
#endif
        yychar = YYEMPTY;
        goto yyloop;
    }

yyreduce:
#if YYDEBUG
    if (yydebug)
        printf("%sdebug: state %d, reducing by rule %d (%s)\n",
                YYPREFIX, yystate, yyn, yyrule[yyn]);
#endif
    yym = yylen[yyn];
    if (yym)
        yyval = yystack.l_mark[1-yym];
    else
        memset(&yyval, 0, sizeof yyval);
    switch (yyn)
    {
case 3:
#line 49 "project.y"
	{
		/*cout<<$1<<" -> "<<$4<<endl;*/

		string birinci=string(yystack.l_mark[-4].str);
		string dorduncu=string(yystack.l_mark[-1].str);
		int pos = dorduncu.find(" ");/*bosluga gelene kadar*/
		string sub = dorduncu.substr(pos+1);/*bosluktan sonrası*/
		string bef = dorduncu.substr(0, pos);/*bosluktan oncesi*/
		int z = birinci.find(">");
		string rec = birinci.substr(0, z);
		/*cout<<bef<<endl;*/
		/*cout<<sub<<endl;*/
		/*cout<<rec<<endl;*/

		curr=birinci;
		LEFTHANDSIDE.push_back(birinci); /*en sol kısım*/
		INPUT.push_back(dorduncu); /*sag kısım komple*/
		BEF.push_back(bef); /*bosluktan oncesi*/
		SUB.push_back(sub); /*bosluktan sonrası*/
		REC.push_back(rec);

		
		
		
		
	}
break;
case 4:
#line 79 "project.y"
	{
		string combined = string(yystack.l_mark[-2].str) + string(yystack.l_mark[-1].str) + string(yystack.l_mark[0].str);
		yyval.str = strdup(combined.c_str());
	}
break;
case 5:
#line 87 "project.y"
	{
		string combined = string(yystack.l_mark[-2].str) + string(yystack.l_mark[-1].str) + string(yystack.l_mark[0].str);
		yyval.str = strdup(combined.c_str());
	}
break;
case 6:
#line 93 "project.y"
	{
		string combined = string(yystack.l_mark[-3].str) + string(yystack.l_mark[-2].str) + string(yystack.l_mark[-1].str) + " " + string(yystack.l_mark[0].str);
		yyval.str = strdup(combined.c_str());
	}
break;
case 7:
#line 99 "project.y"
	{
		yyval.str = strdup(yystack.l_mark[0].str);
	}
break;
case 8:
#line 104 "project.y"
	{
		string combined = string(yystack.l_mark[-1].str) + " " + string(yystack.l_mark[0].str);
		yyval.str = strdup(combined.c_str());
	}
break;
case 9:
#line 110 "project.y"
	{
		cout<<"missing < symbol in line "<<linenum<<endl;
		errorFlag=true;
		exit(1);
	}
break;
case 10:
#line 117 "project.y"
	{
		cout<<"missing > symbol in line "<<linenum<<endl;
		errorFlag=true;
		exit(1);
	}
break;
#line 567 "y.tab.c"
    }
    yystack.s_mark -= yym;
    yystate = *yystack.s_mark;
    yystack.l_mark -= yym;
    yym = yylhs[yyn];
    if (yystate == 0 && yym == 0)
    {
#if YYDEBUG
        if (yydebug)
            printf("%sdebug: after reduction, shifting from state 0 to\
 state %d\n", YYPREFIX, YYFINAL);
#endif
        yystate = YYFINAL;
        *++yystack.s_mark = YYFINAL;
        *++yystack.l_mark = yyval;
        if (yychar < 0)
        {
            if ((yychar = YYLEX) < 0) yychar = YYEOF;
#if YYDEBUG
            if (yydebug)
            {
                yys = yyname[YYTRANSLATE(yychar)];
                printf("%sdebug: state %d, reading %d (%s)\n",
                        YYPREFIX, YYFINAL, yychar, yys);
            }
#endif
        }
        if (yychar == YYEOF) goto yyaccept;
        goto yyloop;
    }
    if ((yyn = yygindex[yym]) && (yyn += yystate) >= 0 &&
            yyn <= YYTABLESIZE && yycheck[yyn] == yystate)
        yystate = yytable[yyn];
    else
        yystate = yydgoto[yym];
#if YYDEBUG
    if (yydebug)
        printf("%sdebug: after reduction, shifting from state %d \
to state %d\n", YYPREFIX, *yystack.s_mark, yystate);
#endif
    if (yystack.s_mark >= yystack.s_last && yygrowstack(&yystack) == YYENOMEM)
    {
        goto yyoverflow;
    }
    *++yystack.s_mark = (YYINT) yystate;
    *++yystack.l_mark = yyval;
    goto yyloop;

yyoverflow:
    YYERROR_CALL("yacc stack overflow");

yyabort:
    yyfreestack(&yystack);
    return (1);

yyaccept:
    yyfreestack(&yystack);
    return (0);
}
