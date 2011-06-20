#	$NetBSD: Makefile,v 1.17 2009/02/14 08:31:13 lukem Exp $
#	@(#)Makefile	8.3 (Berkeley) 5/8/95

.if defined(__MINIX)
.include "../minix-config.inc"
.endif

.include <bsd.own.mk>

PROG=	df
.if defined(__MINIX)
.PATH:  ${NETBSDSRCDIR}/nbsd_bin/csh
.else
.PATH:  ${NETBSDSRCDIR}/bin/csh
.endif
SRCS=	df.c strpct.c

.include <bsd.prog.mk>
