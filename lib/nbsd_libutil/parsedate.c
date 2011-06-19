#include <stdlib.h>
#ifndef lint
#if 0
static char yysccsid[] = "@(#)yaccpar	1.9 (Berkeley) 02/21/93";
#else
#if defined(__NetBSD__) && defined(__IDSTRING)
__IDSTRING(yyrcsid, "$NetBSD: skeleton.c,v 1.29 2008/07/18 14:25:37 drochner Exp $");
#endif /* __NetBSD__ && __IDSTRING */
#endif /* 0 */
#endif /* lint */
#define YYBYACC 1
#define YYMAJOR 1
#define YYMINOR 9
#define YYLEX yylex()
#define YYEMPTY -1
#define yyclearin (yychar=(YYEMPTY))
#define yyerrok (yyerrflag=0)
#define YYRECOVERING (yyerrflag!=0)
