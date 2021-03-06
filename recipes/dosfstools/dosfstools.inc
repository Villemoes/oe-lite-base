# -*- mode:python; -*-
# dosfstools OE build file
# Copyright (C) 2004-2006, Advanced Micro Devices, Inc.  All Rights Reserved
# Released under the MIT license (see packages/COPYING)

DESCRIPTION = "DOS FAT Filesystem Utilities"
LICENSE = "GPL-3.0+"

RECIPE_TYPES = "machine native sdk"
COMPATIBLE_HOST_ARCHS = ".*linux .*darwin"

SRC_URI = "https://github.com/${PN}/${PN}/releases/download/v${PV}/${P}.tar.xz"
inherit c autotools pkgconfig

# output of getconf LFS_CFLAGS
#
CFLAGS += '-D_LARGEFILE_SOURCE -D_FILE_OFFSET_BITS=64'

EXTRA_OECONF += "--enable-compat-symlinks"

inherit auto-package-utils

AUTO_PACKAGE_UTILS = "fatlabel fsck-fat:fsck.fat mkfs-fat:mkfs.fat"
AUTO_PACKAGE_UTILS_DEPENDS += "libc libgcc"
AUTO_PACKAGE_UTILS_RDEPENDS += "libc libgcc"

AUTO_PACKAGE_UTILS_SYMLINKS_fatlabel = "dosfslabel"
AUTO_PACKAGE_UTILS_SYMLINKS_fsck-fat = "dosfsck fsck-msdos:fsck.msdos fsck-vfat:fsck.vfat"
AUTO_PACKAGE_UTILS_SYMLINKS_mkfs-fat = "mkdosfs mkfs-msdos:mkfs.msdos mkfs-vfat:mkfs.vfat"

# auto-package-utils.oeclass currently translates . to - in the
# PROVIDES, but we need util/mkfs.vfat etc. for backward
# compatibility. So add these extra provides by hand.
PROVIDES_${PN}-fsck-fat += "util/fsck.fat util/fsck.msdos util/fsck.vfat"
PROVIDES_${PN}-mkfs-fat += "util/mkfs.fat util/mkfs.msdos util/mkfs.vfat"

RDEPENDS_${PN} = "${AUTO_PACKAGE_UTILS_PACKAGES}"
DEPENDS_${PN} = "${AUTO_PACKAGE_UTILS_PACKAGES}"
