# $FreeBSD$

#.include <src.opts.mk>

WARNS?= 3
PACKAGE=devd
CONFGROUPS=	CONFS DEVD
CONFS=	devd.conf
DEVD=	devmatch.conf
DEVDDIR=	/etc/devd
#.if ${MK_ACPI} != "no"
#DEVD+=	asus.conf
#.endif

#.if ${MK_HYPERV} != "no"   # We have to comment the conditionals. They do not agree with OPBSD's build system
#CONFGROUPS+=	HYPERV        # I presume that could be fixed???? Not current priority.
#HYPERVDIR=${DEVDDIR}
#HYPERV+=	hyperv.conf
#HYPERVPACKAGE=	hyperv-tools
#.endif

#.if ${MK_USB} != "no"
DEVD+=	uath.conf ulpt.conf
#.endif

#.if ${MACHINE_ARCH} == "powerpc"
#DEVD+=	apple.conf
#.endif

#.if ${MK_ZFS} != "no"  #We know that we are likely not using ZFS on OpenBSD...
#DEVD+=	zfs.conf
#.endif

PROG_CXX=devd
SRCS=	devd.cc token.l parse.y y.tab.h
MAN=	devd.8 devd.conf.5

LIBADD=	util

YFLAGS+=-v
CFLAGS+=-I. -I${.CURDIR}
CFLAGS.clang += -Wno-missing-variable-declarations
CFLAGS.gcc = -Wno-redundant-decls
CXXFLAGS.gcc = -Wno-redundant-decls

CLEANFILES= y.output y.tab.i

HAS_TESTS=
SUBDIR.${MK_TESTS}+= tests

.include <bsd.prog.mk>
