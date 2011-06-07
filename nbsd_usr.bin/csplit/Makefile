#	$NetBSD: Makefile,v 1.3 2009/04/14 22:15:19 lukem Exp $

.if defined(__MINIX)
.include "../minix-config.inc"
.endif

PROG=	csplit

.if defined(__MINIX)
LIBUTIL=	/usr/lib/libutil.a
.endif
DPADD+=	${LIBUTIL}
LDADD+=	-lutil

.include <bsd.prog.mk>
