#	$NetBSD: Makefile,v 1.11 2009/04/14 22:15:19 lukem Exp $
#	@(#)Makefile	8.1 (Berkeley) 6/6/93

.if defined(__MINIX)
.include "../minix-config.inc"
.endif

PROG=	ctags
CPPFLAGS+=-I${.CURDIR}
SRCS=	C.c ctags.c fortran.c lisp.c print.c tree.c yacc.c

.include <bsd.prog.mk>

.if !defined(HOSTPROGNAME)
.if (defined(HAVE_GCC) && ${HAVE_GCC} == 4) || defined(HAVE_PCC)
COPTS.ctags.c+=	-Wno-pointer-sign
.endif
.endif
