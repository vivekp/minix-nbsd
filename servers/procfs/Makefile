# Makefile for ProcFS server
PROG=	procfs
SRCS=	buf.c main.c pid.c root.c tree.c util.c cpuinfo.c

CPPFLAGS+= -I${MINIXSRCDIR} -I${MINIXSRCDIR}/servers

DPADD+=	${LIBVTREEFS} ${LIBSYS}
LDADD+=	-lvtreefs -lsys

MAN=

BINDIR?= /sbin

.include <bsd.prog.mk>
