/****************************************************/
/* File: parse.h                                    */
/* The parser interface for the TINY compiler       */
/* Compiler Construction: Principles and Practice   */
/* Kenneth C. Louden                                */
/****************************************************/

#ifndef _PARSE_H_
#define _PARSE_H_
#include "globals.h"

/* Function parse returns the newly
* constructed syntax tree
*/
TreeNode * parse(void);
/* function prototypes for recursive calls */
bool match_possible_lbracket();



#endif
