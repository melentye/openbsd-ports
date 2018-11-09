# $OpenBSD: Makefile.template,v 1.78 2018/07/09 15:00:06 jca Exp $

COMMENT =	open h.265 video codec implementation
V =		1.0.3
DISTNAME =	libde265-$V

SHARED_LIBS =	de265                0.10     # 0.10

CATEGORIES =	graphics
HOMEPAGE =	https://github.com/strukturag/libde265

# LGPLv3
PERMIT_PACKAGE_CDROM =	Yes

WANTLIB	+=		c m ${COMPILER_LIBCXX}

MASTER_SITES =		https://github.com/strukturag/libde265/releases/download/v$V/

SEPARATE_BUIILD =	Yes
CONFIGURE_STYLE =	gnu
CONFIGURE_ARGS =	--disable-dec265 \
			--disable-sherlock265

.include <bsd.port.mk>
