# $OpenBSD: Makefile,v 1.1.1.1 2018/10/18 14:29:06 bket Exp $

COMMENT =		backport of the subprocess library module from Python 3

MODPY_EGG_VERSION =	3.5.2
DISTNAME =		subprocess32-${MODPY_EGG_VERSION}
PKGNAME =		py-${DISTNAME}

CATEGORIES =		devel

# PSF
PERMIT_PACKAGE_CDROM =	Yes

WANTLIB =	${MODPY_WANTLIB} pthread

MODULES =		lang/python
MODPY_PI =		Yes
MODPY_SETUPTOOLS =	Yes

.include <bsd.port.mk>
