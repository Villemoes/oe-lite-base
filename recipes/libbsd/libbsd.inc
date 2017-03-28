SUMMARY = "Utility functions from BSD systems"

HOMEPAGE = "https://libbsd.freedesktop.org/releases/"

# See the COPYING file for details; different source files are covered
# by different licenses making a single short description impossible.
LICENSE = "BSD-n-Clause, ISC, public domain, Beerware"

SRC_URI = "https://libbsd.freedesktop.org/releases/libbsd-${PV}.tar.xz"

inherit autotools library

DEPENDS_${PN} = "libc"
RDEPENDS_${PN} = "libc"
