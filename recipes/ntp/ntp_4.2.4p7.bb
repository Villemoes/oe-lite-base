require ntp.inc

SRC_URI = "http://www.eecis.udel.edu/~ntp/ntp_spool/ntp4/ntp-4.2/${P}.tar.gz \
	file://tickadj.c.patch;patch=1 \
    file://ntp-4.2.4_p6-nano.patch;patch=1 \
	file://ntpd \
	file://ntp.conf \
	file://ntpdate"


# ntp originally includes tickadj. It's split off for inclusion in small firmware images on platforms
# with wonky clocks (e.g. OpenSlug)
RDEPENDS_${PN} = "${PN}-tickadj"
FILES_${PN} = "${bindir}/ntpd ${sysconfdir}/ntp.conf ${sysconfdir}/init.d/ntpd"
FILES_${PN}-bin = "${bindir}/ntp-wait ${bindir}/ntpdc ${bindir}/ntpq ${bindir}/ntptime ${bindir}/ntptrace"
FILES_${PN}-tickadj = "${bindir}/tickadj"
FILES_${PN}-utils = "${bindir}/*"
FILES_${PN}-date = "${bindir}/ntpdate ${sysconfdir}/network/if-up.d/ntpdate"

do_configure_prepend() {
	sed -i -e 's:dist_man_MANS=	sntp.1::g' sntp/Makefile.am
}

do_install_append() {
	install -d ${D}/${sysconfdir}/init.d
	install -m 644 ${WORKDIR}/ntp.conf ${D}/${sysconfdir}
	install -m 755 ${WORKDIR}/ntpd ${D}/${sysconfdir}/init.d
	install -d ${D}/${sysconfdir}/network/if-up.d
	install -m 755 ${WORKDIR}/ntpdate ${D}/${sysconfdir}/network/if-up.d
}
