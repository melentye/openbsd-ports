# $OpenBSD: Makefile,v 1.19 2018/07/24 19:03:47 bcallah Exp $

COMMENT =	scientific plotting and graphing package
MODPY_EGG_VERSION =	3.0.1
DISTNAME =	veusz-${MODPY_EGG_VERSION}
CATEGORIES =	math graphics

HOMEPAGE =	https://veusz.github.io/
MAINTAINER =	Brian Callahan <bcallah@openbsd.org>

# GPLv2+
PERMIT_PACKAGE_CDROM =	Yes

WANTLIB += Qt5Core Qt5Gui Qt5Widgets Qt5Xml m
WANTLIB += ${COMPILER_LIBCXX} ${MODPY_WANTLIB}

MASTER_SITES =	https://github.com/veusz/veusz/releases/download/${DISTNAME}/

MODULES =	lang/python \
		x11/qt5

BUILD_DEPENDS =	math/py-numpy \
		x11/py-qt5

RUN_DEPENDS =	math/py-numpy \
		x11/py-qt5
TEST_DEPENDS =	${BASE_PKGPATH}

do-test:
	cd ${WRKSRC}/tests && ${MODPY_BIN} runselftest.py

.include <bsd.port.mk>
