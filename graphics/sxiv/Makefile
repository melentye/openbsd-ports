# $OpenBSD: Makefile,v 1.14 2018/06/29 22:16:17 espie Exp $

COMMENT =	simple X Image Viewer

GH_PROJECT =	sxiv
GH_ACCOUNT =	muennich
GH_TAGNAME =	v24
REVISION =	2

CATEGORIES =	graphics x11

MAINTAINER =	Klemens Nanni <kl3@posteo.org>

# GPLv2+
PERMIT_PACKAGE_CDROM =		Yes

WANTLIB +=	Imlib2 X11 Xft c exif gif lib/inotify/inotify

RUN_DEPENDS =	devel/desktop-file-utils \
		x11/gtk+3,-guic

LIB_DEPENDS =	devel/libinotify \
		graphics/imlib2 \
		graphics/libexif

MAKE_FLAGS =	CC="${CC}" \
		V=1 \
		PREFIX=${PREFIX} \
		MANPREFIX=${PREFIX}/man \
		CFLAGS="${CFLAGS} -I${X11BASE}/include -I${X11BASE}/include/freetype2 -I${LOCALBASE}/include -I${LOCALBASE}/include/inotify" \
		LDFLAGS="-L${X11BASE}/lib -L${LOCALBASE}/lib -L${LOCALBASE}/lib/inotify -linotify -Wl,-rpath ${LOCALBASE}/lib/inotify"

NO_TEST =	Yes

post-install:
	cd ${WRKSRC}/icon && make install
	${INSTALL_DATA_DIR} ${PREFIX}/share/applications
	${INSTALL_DATA} ${WRKSRC}/sxiv.desktop ${PREFIX}/share/applications

.include <bsd.port.mk>
