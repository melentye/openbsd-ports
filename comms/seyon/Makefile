# $OpenBSD: Makefile,v 1.32 2017/11/25 13:27:48 espie Exp $

COMMENT=	communication package for X11

DISTNAME=	Seyon-2.14b
PKGNAME=	${DISTNAME:L}
REVISION=	5
CATEGORIES=	comms x11

MASTER_SITES=	ftp://sipb.mit.edu/pub/seyon/
EXTRACT_SUFX=	-tar.Z
FIX_EXTRACT_PERMISSIONS =	Yes

# BSD
PERMIT_PACKAGE_CDROM=	Yes

WANTLIB=	ICE SM X11 Xau Xdmcp Xaw Xext Xmu Xpm Xt c

CONFIGURE_STYLE=imake

WRKDIST=	${WRKDIR}/seyon

NO_TEST=	Yes

.include <bsd.port.mk>
