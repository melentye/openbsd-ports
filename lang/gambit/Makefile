# $OpenBSD: Makefile,v 1.32 2018/09/20 21:41:40 juanfra Exp $

COMMENT=	complete, efficient and reliable implementation of Scheme

V=		4.9.0
DISTNAME=	gambit-v${V:S/./_/g}
PKGNAME=	gambit-$V
REVISION=	0
API_V=		${V:R:S/./0/}00${V:E}
SUBST_VARS+=	API_V

CATEGORIES=	lang

HOMEPAGE=	http://gambitscheme.org/

MAINTAINER=	Juan Francisco Cantero Hurtado <juanfra@openbsd.org>

# LGPLv2.1 / Apachev2.0
PERMIT_PACKAGE_CDROM=	Yes

MASTER_SITES=	http://www.iro.umontreal.ca/~gambit/download/gambit/v${V:R}/source/
EXTRACT_SUFX=	.tgz

WANTLIB +=	c crypto m ssl util

CONFIGURE_STYLE=gnu
CONFIGURE_ARGS+=--disable-cplusplus \
		--disable-absolute-shared-libs \
		--docdir=${PREFIX}/share/doc/gambit/ \
		--includedir=${PREFIX}/include/gambit/ \
		--libdir=${PREFIX}/lib/gambit/ \
		--enable-c-opt="${CFLAGS}" \
		--enable-openssl \
		--enable-poll

CONFIGURE_ENV=	CC=${CC} CXX=${CXX} CFLAGS="${CFLAGS}" CXXFLAGS="${CXXFLAGS}"

MAKE_FILE=	${WRKSRC}/makefile

# On sparc64, gcc crashes with the default stack limit:
# "cc: Internal error: Illegal instruction" on _gambc.c
do-build:
	ulimit -s 12288 && cd ${WRKSRC} && ${SETENV} ${MAKE_ENV} \
		${MAKE_PROGRAM} ${MAKE_FLAGS} -f ${MAKE_FILE} ${ALL_TARGET}

do-test:
	cd ${WRKSRC}/tests && ${SETENV} ${TEST_ENV} ${MAKE_PROGRAM} \
		${TEST_FLAGS} -f makefile ${TEST_TARGET}

# alpha: "cc1: out of memory allocating 1608 bytes"
# hppa: "virtual memory exhausted: Cannot allocate memory" (in a system with 2GB RAM)
# sparc64: "virtual memory exhausted: Cannot allocate memory" (ports cluster)
.if ${MACHINE_ARCH} == "alpha" || ${MACHINE_ARCH} == "hppa" || ${MACHINE_ARCH} == "sparc64"
CFLAGS += -O0
.endif

.include <bsd.port.mk>
