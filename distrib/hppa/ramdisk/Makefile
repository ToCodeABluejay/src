#	$OpenBSD: Makefile,v 1.48 2021/07/26 12:47:45 kn Exp $

LIF=		lif${OSrev}.img
CDROM=		cd${OSrev}.iso
MTREE=		${UTILS}/mtree.conf
RAMDISK=	RAMDISK

LISTS=		${.CURDIR}/list
UTILS=		${.CURDIR}/../../miniroot

MRDISKTYPE=	rdroot
MRMAKEFSARGS=	-o disklabel=${MRDISKTYPE},minfree=0,density=4096

all: ${LIF} ${CDROM}

${LIF}: bsd.lif
	/usr/mdec/mkboot -v ${DESTDIR}/usr/mdec/boot bsd.lif ${LIF}

${CDROM}: bsd.rd
	rm -rf ${.OBJDIR}/cd-dir/
	mkdir -p ${.OBJDIR}/cd-dir/
	cp bsd.rd ${.OBJDIR}/cd-dir/bsd.rd
	mkhybrid -A "OpenBSD ${OSREV} ${MACHINE} bootonly CD" \
	    -P "Copyright (c) `date +%Y` Theo de Raadt, The OpenBSD project" \
	    -p "Theo de Raadt <deraadt@openbsd.org>" \
	    -V "OpenBSD/${MACHINE} ${OSREV} boot-only CD" \
	    -o ${.OBJDIR}/${CDROM} ${.OBJDIR}/cd-dir
	dd if=${DESTDIR}/usr/mdec/cdboot of=${.OBJDIR}/${CDROM} \
	    bs=32k count=1 conv=notrunc
	dd if=/dev/zero bs=64k count=1 >> ${.OBJDIR}/${CDROM}

bsd.lif: bsd.rd
	(cat bsd.rd ; dd if=/dev/zero count=1) | gzip -9n > bsd.lif

bsd.rd: mr.fs bsd
	cp bsd bsd.rd
	rdsetroot bsd.rd mr.fs
	strip -R .SUNW_ctf bsd.rd

bsd:
	cd ${.CURDIR}/../../../sys/arch/${MACHINE}/compile/${RAMDISK} && \
	    su ${BUILDUSER} -c '${MAKE} config && ${MAKE} clean && exec ${MAKE} ${MFLAGS}'
	cp -p ${.CURDIR}/../../../sys/arch/${MACHINE}/compile/${RAMDISK}/obj/bsd bsd

mr.fs: instbin
	rm -rf $@.d
	install -d -o root -g wheel $@.d
	mtree -def ${MTREE} -p $@.d -u
	CURDIR=${.CURDIR} OBJDIR=${.OBJDIR} OSrev=${OSrev} \
	    TARGDIR=$@.d UTILS=${UTILS} RELEASEDIR=${RELEASEDIR} \
	    sh ${UTILS}/runlist.sh ${LISTS}
	rm $@.d/instbin
	makefs ${MRMAKEFSARGS} $@ $@.d

instbin.mk instbin.cache instbin.c: instbin.conf
	crunchgen -E -D ${.CURDIR}/../../.. -L ${DESTDIR}/usr/lib \
	    -c instbin.c -e instbin -m instbin.mk instbin.conf

instbin: instbin.mk instbin.cache instbin.c
	${MAKE} ${MFLAGS} -f instbin.mk SRCLIBDIR=${.CURDIR}/../../../lib all

instbin.conf: ${LISTS}
	awk -f ${UTILS}/makeconf.awk  ${LISTS} > instbin.conf

.ifdef RELEASEDIR
install:
	cp bsd.rd ${RELEASEDIR}/bsd.rd
	chmod a+r ${RELEASEDIR}/bsd.rd
	cp ${LIF} ${RELEASEDIR}
	cp ${CDROM} ${RELEASEDIR}
.endif

clean cleandir:
	rm -f *.core mr.fs instbin instbin.mk instbin.cache \
	    lib*.a lib*.olist instbin.map \
	    instbin.conf *.o *.lo *.c bsd bsd.* ${LIF} ${CDROM}
	rm -rf mr.fs.d

.include <bsd.obj.mk>
