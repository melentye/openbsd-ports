# $OpenBSD: Makefile,v 1.11 2018/10/24 14:28:04 sthen Exp $

COMMENT =	WMS viewer built on top of spatialite and rasterlite2
DISTNAME =	librewms-1.0.0
REVISION =	7

# Licence: GPLv3

LIB_DEPENDS +=	x11/wxWidgets \
		databases/sqlite3 \
		geo/spatialite/libspatialite \
		geo/spatialite/librasterlite2
RUN_DEPENDS +=	devel/desktop-file-utils
WANTLIB += ICE SDL SM X11 Xcomposite Xcursor Xdamage Xext Xfixes Xi
WANTLIB += Xinerama Xrandr Xrender Xxf86vm atk-1.0 c cairo crypto curl
WANTLIB += expat ffi fontconfig freetype freexl gdk-x11-2.0
WANTLIB += gdk_pixbuf-2.0 geos geos_c geotiff gif gio-2.0 glib-2.0
WANTLIB += gmodule-2.0 gobject-2.0 graphite2 gthread-2.0 gtk-x11-2.0
WANTLIB += harfbuzz iconv intl iodbc jpeg lzma m mspack nghttp2 pango-1.0
WANTLIB += pangocairo-1.0 pangoft2-1.0 pcre pixman-1 png proj pthread
WANTLIB += rasterlite2 sndio spatialite sqlite3 ssl ${COMPILER_LIBCXX}
WANTLIB += tiff usbhid webp wx_base wx_base_net wx_base_odbc wx_base_xml
WANTLIB += wx_gtk2_adv wx_gtk2_aui wx_gtk2_core wx_gtk2_dbgrid
WANTLIB += wx_gtk2_html wx_gtk2_qa wx_gtk2_richtext wx_gtk2_xrc xcb
WANTLIB += xcb-render xcb-shm xml2 z

COMPILER =		base-clang ports-gcc base-gcc

post-install:
	${INSTALL_DATA_DIR} ${PREFIX}/share/{pixmaps,applications}
	${INSTALL_DATA} ${WRKSRC}/gnome_resource/*.desktop ${PREFIX}/share/applications/
	${INSTALL_DATA} ${WRKSRC}/gnome_resource/*.png ${PREFIX}/share/pixmaps/

.include <bsd.port.mk>
