# $OpenBSD: Makefile,v 1.64 2018/10/24 14:28:12 sthen Exp $

COMMENT=		color profile manager for GNOME

GNOME_PROJECT=		gnome-color-manager
GNOME_VERSION=		3.28.0
REVISION=		2

CATEGORIES=		graphics

# GPLv2
PERMIT_PACKAGE_CDROM=	Yes

WANTLIB += ${COMPILER_LIBCXX} c cairo canberra canberra-gtk3 colord
WANTLIB += colord-gtk colordprivate exif exiv2 gdk-3 gdk_pixbuf-2.0
WANTLIB += gio-2.0 glib-2.0 gobject-2.0 gtk-3 intl lcms2 pango-1.0
WANTLIB += tiff vte-2.91

COMPILER =		base-clang ports-gcc base-gcc

MODULES=		devel/meson \
			x11/gnome

LIB_DEPENDS=		audio/libcanberra,-gtk3 \
			devel/vte3 \
			graphics/colord-gtk \
			graphics/exiv2 \
			graphics/libexif

RUN_DEPENDS=		graphics/argyll \
			graphics/shared-color-targets

MODGNOME_TOOLS=		desktop-file-utils gtk-update-icon-cache yelp
MODGNOME_LDFLAGS=	-L${X11BASE}/lib

CONFIGURE_ARGS=		-Denable-packagekit=false

pre-configure:
	sed -i -e 's,/usr/share,${LOCALBASE}/share,g' \
		-e 's,/usr/bin,${LOCALBASE}/bin,g' \
		${WRKSRC}/src/{gcm-calibrate.c,gcm-calibrate-argyll.c,gcm-picker.c,gcm-calibrate-main.c}

.include <bsd.port.mk>
