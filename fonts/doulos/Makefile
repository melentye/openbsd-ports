# $OpenBSD: Makefile,v 1.7 2017/11/15 09:49:39 bentley Exp $

TYPEFACE =		doulos
V =			5.000
COMMENT =		Unicode-based font for Roman and Cyrillic
DISTNAME =		DoulosSIL-$V
CATEGORIES =		fonts
REVISION =		0

HOMEPAGE =		https://software.sil.org/doulos/

MAINTAINER =		George Rosamond <george@nycbug.org>

# SIL OFL 1.1
PERMIT_PACKAGE_CDROM =	Yes

MASTER_SITES =		https://software.sil.org/downloads/r/doulos/

MODULES =		font

NO_BUILD =		Yes
NO_TEST =		Yes

WRKDIST =		${WRKDIR}/${DISTNAME}
DOCDIR =		${PREFIX}/share/doc/doulos

post-install:
	${INSTALL_DATA_DIR} ${DOCDIR}
	${INSTALL_DATA} ${WRKDIST}/*.txt ${DOCDIR}

.include <bsd.port.mk>
