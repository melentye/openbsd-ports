# $OpenBSD: Makefile.template,v 1.78 2018/07/09 15:00:06 jca Exp $

COMMENT =	ISO/IEC 23008-12:2017 HEIF file format decoder and encoder
V = 		1.3.2
DISTNAME =	libheif-$V

SHARED_LIBS =	heif		4.2	# 4.2

CATEGORIES =	graphics
HOMEPAGE =	https://github.com/strukturag/libheif

# LGPLv3
PERMIT_PACKAGE_CDROM =	Yes

WANTLIB =		c de265 jpeg m png x265 z ${COMPILER_LIBCXX}

MASTER_SITES =		https://github.com/strukturag/libheif/releases/download/v$V/

RUN_DEPENDS +=		misc/shared-mime-info
LIB_DEPENDS +=		graphics/libde265 \
			multimedia/x265 \
			graphics/jpeg \
			graphics/png \


SEPARATE_BUILD =	Yes
CONFIGURE_STYLE =	gnu
CONFIGURE_ENV =	CFLAGS="${CFLAGS} -I${LOCALBASE}/include" \
		CPPFLAGS="${CPPFLAGS} -I${LOCALBASE}/include" \
		LDFLAGS="${LDFLAGS} -L${LOCALBASE}/lib"

.include <bsd.port.mk>
