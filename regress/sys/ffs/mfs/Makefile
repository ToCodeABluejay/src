# $OpenBSD: Makefile,v 1.1 2021/10/03 08:56:53 claudio Exp $

TESTS=		chflags chmod chown link mkdir mkfifo open rename rmdir \
		symlink truncate unlink

.PHONY: mount umount unconfig clean

REGRESS_SETUP_ONCE+=	mount
mount:
	mkdir -p /mnt/regress-mfs
	mount_mfs -s 4096 swap /mnt/regress-mfs

REGRESS_CLEANUP+=	umount
umount:
	umount /mnt/regress-mfs

REGRESS_CLEANUP+=	unconfig
unconfig:
	-umount -f /mnt/regress-mfs 2>/dev/null || true
	-rmdir /mnt/regress-mfs 2>/dev/null || true

REGRESS_SETUP+=		${.OBJDIR}/../fstest
${.OBJDIR}/../fstest:
	${.MAKE} -C ${.CURDIR}/.. fstest

.for t in ${TESTS}
REGRESS_TARGETS+=	run-$t
run-$t:
	cd /mnt/regress-mfs && env FSTEST=${.OBJDIR}/../fstest \
	    /bin/sh ${.CURDIR}/../run ${.CURDIR}/../tests/$t/*.t
.endfor

.include <bsd.regress.mk>
