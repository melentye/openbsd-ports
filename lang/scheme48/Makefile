# $OpenBSD: Makefile,v 1.14 2017/05/28 16:23:28 espie Exp $

COMMENT=	Scheme Underground's implementation of R5RS
# '

V=		1.9.2
DISTNAME=	scheme48-$V
CATEGORIES=	lang

HOMEPAGE=	http://www.s48.org/

MAINTAINER=	Aaron W. Hsu <arcfide@sacrideo.us>

# 3-clause BSD
PERMIT_PACKAGE_CDROM=	Yes

MASTER_SITES=		${HOMEPAGE}/$V/
EXTRACT_SUFX=		.tgz

WANTLIB=		c m pthread

USE_GMAKE=		Yes
ALL_TARGET=		enough

CONFIGURE_STYLE=	gnu
CONFIGURE_ENV=		LD="${CC}" LDFLAGS="-Wl,--export-dynamic"

post-install: 
	${INSTALL_DATA_DIR} ${PREFIX}/share/doc/scheme48
	${INSTALL_DATA} ${WRKSRC}/doc/*.txt ${WRKSRC}/doc/*.ps \
		${WRKSRC}/doc/*.pdf ${PREFIX}/share/doc/scheme48
	${INSTALL_DATA} ${WRKSRC}/COPYING ${PREFIX}/share/doc/scheme48
	${INSTALL_DATA_DIR} ${PREFIX}/share/doc/scheme48/html
	${INSTALL_DATA} ${WRKSRC}/doc/html/* \
		${PREFIX}/share/doc/scheme48/html

.include <bsd.port.mk>
