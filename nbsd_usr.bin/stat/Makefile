#	$NetBSD: Makefile,v 1.7 2003/07/25 03:21:17 atatat Exp $

.if defined(__MINIX)
.include "../minix-config.inc"
.endif

PROG=	stat

.if !defined(HOSTPROG)
LINKS=	${BINDIR}/stat ${BINDIR}/readlink
MLINKS=	stat.1 readlink.1
.endif

.include <bsd.prog.mk>
