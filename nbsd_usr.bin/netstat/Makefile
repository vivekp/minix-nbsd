#	$NetBSD: Makefile,v 1.32 2010/12/15 11:22:41 pooka Exp $
#	from: @(#)Makefile	8.1 (Berkeley) 6/12/93

.if defined(__MINIX)
.include "../minix-config.inc"
USE_INET6=	no
.endif

.include <bsd.own.mk>

USE_FORT?= yes	# setgid

RUMPPRG=netstat
SRCS=	atalk.c bpf.c fast_ipsec.c if.c inet.c inet6.c ipsec.c iso.c \
	main.c mbuf.c mroute.c mroute6.c show.c route.c unix.c
.PATH:	${NETBSDSRCDIR}/sys/netiso 
BINGRP=	kmem
BINMODE=2555
LDADD=	-lkvm
DPADD=	${LIBKVM}

.if defined(__MINIX)
CPPFLAGS+= -DIPSEC
.endif
CPPFLAGS+= -I${NETBSDSRCDIR}/sys/dist/pf

.if defined(__MINIX)
.PATH:  ${.CURDIR}/../../lib/nbsd_libc/gen
.PATH:  ${.CURDIR}/../../lib/nbsd_libc/net
.else
.PATH:  ${.CURDIR}/../../lib/libc/gen
.PATH:  ${.CURDIR}/../../lib/libc/net
.endif

CPPFLAGS+= -DRUMP_ACTION
RUMPSRCS+= sysctlbyname.c sysctlgetmibinfo.c sysctlnametomib.c
RUMPSRCS+= if_indextoname.c getifaddrs.c

.if (${USE_INET6} != "no")
CPPFLAGS+= -DINET6
.endif

.include <bsd.prog.mk>
