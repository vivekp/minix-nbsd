#	$NetBSD: Makefile,v 1.17 2010/12/15 00:09:41 pooka Exp $	

.if defined(__MINIX)
.include "../minix-config.inc"
.endif

WARNS?=	1	# XXX: out of date third-party program 

USE_FORT?= yes	# network client

RUMPPRG=traceroute
MAN=	traceroute.8 

CPPFLAGS+=-DHAVE_MALLOC_H=1 -DHAVE_SYS_SELECT_H=1 -DHAVE_SYS_SOCKIO_H=1
CPPFLAGS+=-DHAVE_STRERROR=1 -DHAVE_SETLINEBUF=1 -DHAVE_SOCKADDR_SA_LEN=1 
CPPFLAGS+=-DHAVE_RAW_OPTIONS=1

.if !defined(__MINIX)
CPPFLAGS+=-DIPSEC
LDADD+=	-lipsec
DPADD+=	${LIBIPSEC}
.endif

BINOWN= root
BINMODE=4555

SRCS=	traceroute.c ifaddrlist.c 
SRCS+= version.c as.c

.if defined(__MINIX)
.PATH: ${.CURDIR}/../../lib/nbsd_libc/net
.else
.PATH: ${.CURDIR}/../../lib/libc/net
.endif
RUMPSRCS= getifaddrs.c
CPPFLAGS+= -DRUMP_ACTION

AWKS=	median.awk mean.awk 

.include <bsd.prog.mk>
