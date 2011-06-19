#	$NetBSD: Makefile,v 1.21 2006/12/16 12:59:17 bouyer Exp $
#	@(#)Makefile	8.1 (Berkeley) 6/6/93

.if defined(__MINIX)
.include "../minix-config.inc"
.endif

.include <bsd.own.mk>

PROG=	xinstall
SRCS=	xinstall.c getid.c
MAN=	install.1

.if defined(__MINIX)
.PATH:		${NETBSDSRCDIR}/nbsd_usr.sbin/mtree
CPPFLAGS+=	-I${NETBSDSRCDIR}/nbsd_usr.sbin/mtree
.else
.PATH:		${NETBSDSRCDIR}/usr.sbin/mtree
CPPFLAGS+=	-I${NETBSDSRCDIR}/usr.sbin/mtree
.endif

.if (${HOSTPROG:U} == "")
DPADD+= ${LIBUTIL}
LDADD+= -lutil
.endif

PROGNAME=install

.include <bsd.prog.mk>
