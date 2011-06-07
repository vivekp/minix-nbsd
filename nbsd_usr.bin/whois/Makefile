#	$NetBSD: Makefile,v 1.7 2009/04/14 22:15:29 lukem Exp $
#	@(#)Makefile	8.1 (Berkeley) 6/6/93

.if defined(__MINIX)
.include "../minix-config.inc"
USE_FORT?= no
.else
USE_FORT?= yes	# network client
.endif

PROG=		whois
CPPFLAGS+=	-DRIPE

.include <bsd.prog.mk>
