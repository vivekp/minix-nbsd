# Makefile for the kernel image.
.include <bsd.own.mk>
.include "nbsd.config"

u=/usr
MDEC=	/usr/mdec
GEN_FILES=	*.bak image kernel *.iso *.iso.gz cdfdimage rootimage src

# Specify the programs that are part of the system image.
PROGRAMS=	kernel \
	../servers/ds/ds \
	../servers/rs/rs \
	../servers/pm/pm \
	../servers/sched/sched \
	../servers/vfs/vfs \
	../drivers/memory/memory \
	../drivers/log/log \
	../drivers/tty/tty \
	../servers/mfs/mfs \
	../servers/vm/vm \
	../servers/pfs/pfs \
	../servers/init/init

usage:	
	@echo " " >&2
	@echo "Master Makefile to create new MINIX configuration." >& 2
	@echo "Root privileges are required." >&2
	@echo " " >&2
	@echo "Usage:" >&2
	@echo "	make includes   # Install include files" >&2
	@echo "	make depend     # Generate dependency files" >&2
	@echo "	make libraries  # Make system libraries" >&2
	@echo "	make services   # Compile and install all services" >&2
	@echo "	make image      # Make needed services and create boot image" >&2
	@echo "	make install    # Make image, and install to hard disk" >&2
	@echo "	make hdboot     # Make image, and install to hard disk" >&2
	@echo "	make fdboot     # Make image, and install to floppy disk" >&2
	@echo "	make bootable   # Make hard disk bootable" >&2
	@echo "	make nbsd_fetch	# Download current NetBSD reference sources" >&2
	@echo " make nbsd_userland_fetch # Download current NetBSD userland reference sources" >&2
	@echo "	make nbsd_diff	# Update minix-port.patch in NetBSD sources" >&2
	@echo "	make clean      # Remove all compiler results, except libs" >&2
	@echo " " >&2
	@echo "To create a fresh MINIX configuration, try:" >&2
	@echo "	make clean install      # new boot image" >&2
	@echo "	make fresh install      # new everything" >&2
	@echo " " >&2

all: services image

# Pad the kernel text only if ACK compiler is used. padtext does not work for
# gnu-like compilers as they generate common I&D and a linker script can do the
# same in a nicer way
.if ${COMPILER_TYPE} == "gnu"
PAD_KERNEL_TEXT := cp ../kernel/kernel kernel
.else
PAD_KERNEL_TEXT := padtext ../kernel/kernel kernel
.endif

# for fast complie kernel and generate image, skip servers and drivers
image_mb: includes
	cd ../kernel && $(MAKE)
	${PAD_KERNEL_TEXT}
	installboot -image $@ $(PROGRAMS)
	
image:  includes services
	${PAD_KERNEL_TEXT}
	installboot -image $@ $(PROGRAMS)

# rebuild the program or system libraries
includes:
	$(MAKE) -C .. includes

depend: includes .gitignore
	$(MAKE) -C ../ depend

.gitignore: Makefile
	echo $(GEN_FILES) | tr ' ' '\n' >.gitignore

services: includes kernel servers .WAIT drivers

kernel: includes
	$(MAKE) -C ../kernel 

servers: includes
	$(MAKE) -C ../servers all install

drivers: includes servers
	$(MAKE) -C ../drivers all install

libraries: includes
	cd ../lib && sh ack_build.sh clean obj depend all install

# make bootable and place system images
bootable:
	exec su root mkboot bootable

hdboot:	image
	exec sh mkboot $@
	@sync

fdboot:	image
	exec su root mkboot $@
	@sync

install: includes services hdboot

# download and update NetBSD reference sources.
nbsd_fetch:
	cd ${MINIXSRCDIR} && awk '{print $$2;}' < tools/nbsd_ports \
		| xargs -t cvs -d ${NBSD_CVSROOT} co -N -d nbsdsrc ${NBSD_REF}

nbsd_diff:
	cd ${MINIXSRCDIR} && awk '{ system("sh tools/nbsd_diff.sh " \
	   "nbsdsrc/"$$2" "$$1" "$$1"/minix-port.patch");}' < tools/nbsd_ports

# download and update NetBSD userland reference source.
nbsd_userland_fetch:
	cd ${MINIXSRCDIR} && awk '{print $$2;}' < tools/nbsd_userland_ports \
		| xargs -t cvs -d ${NBSD_CVSROOT} co -N -d nbsdsrc ${NBSD_REF}

# clean up compile results
clean:
	$(MAKE) -C ../kernel $@
	$(MAKE) -C ../servers $@
	$(MAKE) -C ../drivers $@
	rm -rf $(GEN_FILES)

cleandepend::
	$(MAKE) -C ../kernel $@
	$(MAKE) -C ../servers  $@
	$(MAKE) -C ../drivers  $@
