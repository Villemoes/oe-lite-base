# -*- mode:python; -*-
DESCRIPTION = "Libcap is a library for getting and setting POSIX.1e \
	(formerly POSIX 6) draft 15 capabilities."
LICENSE = "GPL-2.0+,BSD-3-Clause"

RECIPE_TYPES = "native machine sdk"
COMPATIBLE_HOST_ARCHS = ".*linux"

inherit make c library auto-package-utils

require conf/fetch/kernelorg.conf
SRC_URI = "${KERNELORG_GIT}/linux/kernel/git/morgan/libcap.git"
S = "${SRCDIR}/libcap"

DEPENDS = "native:bison native:flex libattr"

BUILD_CFLAGS += "-I${S}/libcap/include"
EXTRA_OEMAKE = "PAM_CAP=no"

do_install() {
	oe_runmake DESTDIR="${D}" \
		sbindir="${sbindir}" libdir="${libdir}" \
		mandir="${mandir}" incdir="${includedir}" \
		CC='${CC}' CFLAGS='${CFLAGS}' LDFLAGS='${LDFLAGS}' \
		BUILD_CC='${BUILD_CC}' BUILD_CFLAGS='${BUILD_CFLAGS}' \
		AR='${AR}' RANLIB='${RANLIB}' \
		RAISE_SETFCAP=no \
		install
}

DEPENDS_${PN} += "libattr"

AUTO_PACKAGE_UTILS = "capsh getcap getpcaps setcap"
AUTO_PACKAGE_UTILS_RDEPENDS = "${PN}"

LIBRARY_NAME = "libcap"
LIBRARY_VERSION = "2"

DEPENDS_${PN} += "libc libattr"
RDEPENDS_${PN} += "libc libattr"
