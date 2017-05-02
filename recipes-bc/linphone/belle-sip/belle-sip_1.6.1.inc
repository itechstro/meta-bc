DESCRIPTION = "SIP stack from Belledonne Communications"
LICENSE = "GPLv2"
HOMEPAGE = "http://www.linphone.org/technical-corner/belle-sip/overview"
SECTION = "libs/network"

INC_PR = "r0"

DEPENDS = "libantlr3c-bc bctoolbox zlib"
PROVIDES = "libbellesip"
S = "${WORKDIR}/git"


EXTRA_OECMAKE += " -DENABLE_STRICT=NO -DCMAKE_SKIP_INSTALL_RPATH=ON "

ANTLR_CFLAGS += " -I ${STAGING_DIR_HOST}${layout_exec_prefix}/usr/include"
ANTLR_LIBS += " -L ${STAGING_DIR_HOST}${layout_exec_prefix}/usr/lib"

CFLAGS += " ${ANTLR_CFLAGS} ${ANTLR_LIBS} -lantlr3c"

INSANE_SKIP_${PN} += "dev-deps"

inherit cmake  pkgconfig


FILES_${PN}-dev = " \
    ${includedir} \
    ${libdir}/lib*.so \
    ${libdir}/*.la \
    ${libdir}/*.a \
    ${libdir}/*.o \
    ${libdir}/pkgconfig \
    ${prefix}/share/BelleSIP/"
