/****************************************************/
/* File: globals.h                                  */
/* Global types and vars for TINY compiler          */
/* must come before other include files             */
/* Compiler Construction: Principles and Practice   */
/* Kenneth C. Louden                                */
/****************************************************/

#ifndef _GLOBALS_H_
#define _GLOBALS_H_

#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>
#include <stdbool.h>

#ifndef FALSE
#define FALSE 0
#endif

#ifndef TRUE
#define TRUE 1
#endif

/* MAXRESERVED = the number of reserved words */
#define MAXRESERVED 20

typedef enum
/* book-keeping tokens */
{
	ENDFILE, ERROR,
	/* reserved words */
	IF, THEN, ELSE, END, WHILE,BREAK,UNTIL, READ, WRITE,
	/* multicharacter tokens */
	ID, NUM, FlOATNUM,
	/* special symbols */
	ASSIGN, EQ, LT, GT, PLUS, MINUS, TIMES, OVER, LPAREN, RPAREN, SEMI, COMMA,
	LBRACKET, RBRACKET, LE, GE,STRING,
	/*variable type*/
	INT,FLOAT,FUN
} TokenType;

extern FILE* source; /* source code text file */
extern FILE* listing; /* listing output text file */
extern FILE* code; /* code text file for TM simulator */
extern int lineno; /* source line number for listing */

/**************************************************/
/***********   Syntax tree for parsing ************/
/**************************************************/

typedef enum { StmtK, ExpK } NodeKind;
typedef enum { IfK, RepeatK, AssignK, ReadK, WriteK,DeclareK,BreakK } StmtKind;
typedef enum { OpK, ConstK, IdK } ExpKind;
/* ExpType is used for type checking */
typedef enum { Void, RInteger, RBoolean,RFloat} ExpType;//experssion type
typedef enum { Integer } Vartype;//variable type

#define MAXCHILDREN 3

typedef struct treeNode
{
	struct treeNode * child[MAXCHILDREN];
	struct treeNode * sibling;
	int lineno;
	NodeKind nodekind;
	union { StmtKind stmt; ExpKind exp; } kind;
	union {
		TokenType op;//eg < > == + - * /
		char * name;// the id name
        union {
			int integer;
			float flt;
			char *str;
		} val;// constk should contain one of three values
	} attr;
    union{
        ExpType etype;//ExpType type; /* for type checking of exps */
        Vartype vtype;//variable type; for allocate memory and type checking
    }type;
	
} TreeNode;

/**************************************************/
/***********   Flags for tracing       ************/
/**************************************************/

/* EchoSource = TRUE causes the source program to
* be echoed to the listing file with line numbers
* during parsing
*/
extern int EchoSource;

/* TraceScan = TRUE causes token information to be
* printed to the listing file as each token is
* recognized by the scanner
*/
extern int TraceScan;

/* TraceParse = TRUE causes the syntax tree to be
* printed to the listing file in linearized form
* (using indents for children)
*/
extern int TraceParse;

/* TraceAnalyze = TRUE causes symbol table inserts
* and lookups to be reported to the listing file
*/
extern int TraceAnalyze;

/* TraceCode = TRUE causes comments to be written
* to the TM code file as code is generated
*/
extern int TraceCode;

/* Error = TRUE prevents further passes if an error occurs */
extern int Error;
#endif
