# $OpenBSD: Makefile,v 1.9 2018/04/16 12:30:49 sthen Exp $

CATEGORIES =	productivity
COMMENT =	collaboration services library for KDE
DISTNAME =	attica-0.4.2
MAINTAINER =	KDE porting team <openbsd-kde@googlegroups.com>
REVISION =	5

HOMEPAGE =	https://projects.kde.org/projects/frameworks/attica

SHARED_LIBS =	attica		1.0
EXTRACT_SUFX =	.tar.bz2

MASTER_SITES =	${MASTER_SITE_KDE:=stable/attica/}

WANTLIB =	m lib/qt4/QtNetwork
WANTLIB += ${COMPILER_LIBCXX}

# LGPLv2.1+
PERMIT_PACKAGE_CDROM =	Yes

MODULES =		x11/kde4
MODKDE4_USE =

# clang 6 problem
CXXFLAGS +=		--std=gnu++98

CONFIGURE_ARGS =	-DATTICA_ENABLE_TESTS:Bool=Yes \
			-DQT4_BUILD=Yes

.include <bsd.port.mk>
