%{
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
	
%}

%union
{
	char *str;
}
%token BUYUKHARF KUCUKHARF CIZGI KUCUKOPR BUYUKOPR SEMICOLON
%token <str> BUYUKHARF KUCUKHARF KUCUKOPR BUYUKOPR
%type <str> input BUYUKHARF KUCUKHARF KUCUKOPR BUYUKOPR lefthandside 

%%

statements:
	statement statements
	|
	statement
	;
	
statement:
	lefthandside CIZGI BUYUKOPR input SEMICOLON
	{
		//cout<<$1<<" -> "<<$4<<endl;

		string birinci=string($1);
		string dorduncu=string($4);
		int pos = dorduncu.find(" ");//bosluga gelene kadar
		string sub = dorduncu.substr(pos+1);//bosluktan sonrası
		string bef = dorduncu.substr(0, pos);//bosluktan oncesi
		int z = birinci.find(">");
		string rec = birinci.substr(0, z);
		//cout<<bef<<endl;
		//cout<<sub<<endl;
		//cout<<rec<<endl;

		curr=birinci;
		LEFTHANDSIDE.push_back(birinci); //en sol kısım
		INPUT.push_back(dorduncu); //sag kısım komple
		BEF.push_back(bef); //bosluktan oncesi
		SUB.push_back(sub); //bosluktan sonrası
		REC.push_back(rec);

		
		
		
		
	}
	;
	
lefthandside:
	KUCUKOPR BUYUKHARF BUYUKOPR
	{
		string combined = string($1) + string($2) + string($3);
		$$ = strdup(combined.c_str());
	}
	;
	
input:
	KUCUKOPR BUYUKHARF BUYUKOPR
	{
		string combined = string($1) + string($2) + string($3);
		$$ = strdup(combined.c_str());
	}
	|
	KUCUKOPR BUYUKHARF BUYUKOPR input
	{
		string combined = string($1) + string($2) + string($3) + " " + string($4);
		$$ = strdup(combined.c_str());
	}
	|
	KUCUKHARF
	{
		$$ = strdup($1);
	}
	|
	KUCUKHARF input
	{
		string combined = string($1) + " " + string($2);
		$$ = strdup(combined.c_str());
	}
	|
	BUYUKHARF BUYUKOPR
	{
		cout<<"missing < symbol in line "<<linenum<<endl;
		errorFlag=true;
		exit(1);
	}
	|
	KUCUKOPR BUYUKHARF
	{
		cout<<"missing > symbol in line "<<linenum<<endl;
		errorFlag=true;
		exit(1);
	}
	;


%%

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

