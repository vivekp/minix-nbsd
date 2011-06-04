#	$NetBSD: Makefile,v 1.7 2003/08/03 09:23:15 lukem Exp $	

NOOBJ=		# defined

.include <bsd.own.mk>

.if defined(__MINIX)
.PATH:	${NETBSDSRCDIR}/lib/nbsd_libedit
.else
.PATH:	${NETBSDSRCDIR}/lib/libedit
.endif

INCS=		readline.h

.if defined(__MINIX)
INCSDIR=/usr/netbsd/include/readline
.else
INCSDIR=	/usr/include/readline
.endif
INCSYMLINKS=	readline.h ${INCSDIR}/history.h

.include <bsd.prog.mk>
