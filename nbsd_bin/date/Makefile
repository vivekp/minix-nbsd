#	$NetBSD: Makefile,v 1.14 2006/11/17 22:11:28 christos Exp $
#	@(#)Makefile	8.1 (Berkeley) 5/31/93

.if defined(__MINIX)
.include "../minix-config.inc"
.endif

PROG=	date
SRCS=	date.c netdate.c
.if defined(__MINIX)
LIBUTIL= /usr/lib/libutil.a
.endif
DPADD+=	${LIBUTIL}
LDADD+=	-lutil
CPPFLAGS+=-I${.CURDIR}

.include <bsd.prog.mk>
