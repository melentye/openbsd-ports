# $OpenBSD: Makefile,v 1.17 2018/04/27 16:44:12 naddy Exp $

COMMENT=		utilities to manage well known user directories

DISTNAME=		xdg-user-dirs-0.17
REVISION=		0
CATEGORIES=		devel

HOMEPAGE=		http://freedesktop.org/wiki/Software/xdg-user-dirs/

MAINTAINER=		Antoine Jacoutot <ajacoutot@openbsd.org>

# GPLv2
PERMIT_PACKAGE_CDROM=	Yes

MASTER_SITES=		http://user-dirs.freedesktop.org/releases/

WANTLIB += c iconv intl

# man pages
BUILD_DEPENDS +=	textproc/docbook-xsl

LIB_DEPENDS=		devel/gettext

CONFIGURE_STYLE=	gnu
CONFIGURE_ENV=		CPPFLAGS="-I${LOCALBASE}/include" \
			LDFLAGS="-L${LOCALBASE}/lib"

FAKE_FLAGS=		sysconfdir=${PREFIX}/share/examples/xdg-user-dirs

.include <bsd.port.mk>
