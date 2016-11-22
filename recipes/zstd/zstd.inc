SUMMARY = "Zstandard is a fast lossless compression algorithm"
LICENSE = "BSD-3-Clause"

SRC_URI = "https://github.com/facebook/zstd/archive/v${PV}.tar.gz"

RECIPE_TYPES = "machine native"

inherit make c

inherit library
inherit auto-package-utils

export PREFIX = "${prefix}"

DEPENDS_${PN} = "libc"
RDEPENDS_${PN} = "libc"

AUTO_PACKAGE_UTILS = "zstd"
AUTO_PACKAGE_UTILS_SYMLINKS_zstd = "unzstd zstdcat"
AUTO_PACKAGE_UTILS_DEPENDS = "libc"
AUTO_PACKAGE_UTILS_RDEPENDS = "libc"
