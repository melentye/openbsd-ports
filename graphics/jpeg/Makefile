# $OpenBSD: Makefile,v 1.60 2018/10/01 14:16:55 ajacoutot Exp $

COMMENT=	SIMD-accelerated JPEG codec replacement of libjpeg

V=		2.0.0
DISTNAME=	jpeg-turbo-${V}
PKGNAME=	jpeg-${V}
EPOCH=		0

SHARED_LIBS+=	jpeg		69.0	# 64.0

CATEGORIES=	graphics
DPB_PROPERTIES=	parallel

HOMEPAGE=	https://libjpeg-turbo.org/

# BSD-style
PERMIT_PACKAGE_CDROM=	Yes

MASTER_SITES=	${MASTER_SITE_SOURCEFORGE:=libjpeg-turbo/}
DISTFILES=	libjpeg-turbo-${V}.tar.gz

WANTLIB=	c

MODULES=	devel/cmake

.if ${MACHINE_ARCH} == "amd64" || ${MACHINE_ARCH} == "i386"
BUILD_DEPENDS=	devel/yasm
.endif

CONFIGURE_ARGS+=-DCMAKE_INSTALL_PREFIX="${PREFIX}" \
		-DWITH_TURBOJPEG=False

WRKDIST=	${WRKDIR}/lib${DISTNAME}

post-install:
	${INSTALL_DATA_DIR} ${PREFIX}/share/doc/jpeg
	${INSTALL_DATA} ${WRKSRC}/libjpeg.txt ${WRKSRC}/wizard.txt \
	    ${PREFIX}/share/doc/jpeg
	${INSTALL_DATA_DIR} ${PREFIX}/share/examples/jpeg
	${INSTALL_DATA} ${WRKSRC}/example.txt ${PREFIX}/share/examples/jpeg
	# the turbojpeg wrapper library is disabled
	rm ${PREFIX}/lib/pkgconfig/libturbojpeg.pc

.include <bsd.port.mk>
