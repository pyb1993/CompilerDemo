/****************************************************/
/* File: scan.h                                     */
/* The scanner interface for the TINY compiler      */
/* Compiler Construction: Principles and Practice   */
/* Kenneth C. Louden                                */
/****************************************************/
#ifndef _SCAN_H_
#define _SCAN_H_
#include "globals.h"
#include "tinytype.h"

/* MAXTOKENLEN is the maximum size of a token */
#define MAXTOKENLEN 40

/* tokenString array stores the lexeme of each token */
extern char tokenString[MAXTOKENLEN + 5];
/* function getToken returns the
* next token in source file
*/
TokenType getToken(void);
void clear();
#endif
