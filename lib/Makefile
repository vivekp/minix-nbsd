.include <bsd.own.mk>

.if defined(NBSD_LIBC) && (${NBSD_LIBC} != "no")
LIBC_DIR=	nbsd_libc
LIBM_DIR=	nbsd_libm
LIBCOMPAT_DIR=	nbsd_libcompat_minix
LIBMINLIB_DIR=	nbsd_libminlib
LIBASYN_DIR=	nbsd_libasyn
.endif

LIBC_DIR?=	libc
LIBM_DIR?=	libm
LIBCOMPAT_DIR?=
LIBMINLIB_DIR?=
LIBASYN_DIR?=

SUBDIR= csu ${LIBCOMPAT_DIR} ${LIBC_DIR} libcurses libdriver libnetdriver \
	libedit ${LIBM_DIR} libsys libtimers libutil libbz2 libl libhgfs  \
	libz libfetch libarchive libvtreefs libaudiodriver libmthread     \
	libexec libdevman libusb ${LIBMINLIB_DIR} ${LIBASYN_DIR}          \
	libddekit

.if ${COMPILER_TYPE} == "ack"
SUBDIR+= ack/libd ack/libe ack/libfp ack/liby
.endif

.if ${OBJECT_FMT} == "a.out"
SUBDIR+= libend
.endif

.include <bsd.subdir.mk>

build_ack:
	sh ack_build.sh obj depend all install
.if defined(MINIX_GENERATE_ELF)
build_elf_base:
	sh elf_build_base.sh obj depend all install
.else
build_gnu:
	sh gnu_build.sh obj depend all install

build_clang:
	sh clang_build.sh obj depend all install

build_elf:
	sh elf_build.sh obj depend all install
.endif
clean_ack:
	sh ack_build.sh clean

clean_elf_base:
	sh elf_build.sh clean

clean_clang:
	sh clang_build.sh clean

clean_gnu:
	sh gnu_build.sh clean

clean_elf:
	sh elf_build.sh clean
