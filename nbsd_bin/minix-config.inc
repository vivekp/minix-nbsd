.if !defined(MINIXSRCDIR)
MINIXSRCDIR= 	/usr/src
.endif

NETBSDSRCDIR=	${MINIXSRCDIR}
MACHINE_ARCH?= 	i386

WARNS?=	4
BINDIR?= /bin

CPPFLAGS+= -D_NETBSD_SOURCE
NBSD= y
INSTPRIV= no
USE_TOOLS=  no
