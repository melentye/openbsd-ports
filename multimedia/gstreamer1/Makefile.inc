# $OpenBSD: Makefile.inc,v 1.54 2018/10/24 14:28:08 sthen Exp $

# Most frequent usage of the GStreamer packages:
# core		base library
# plugins-base	minimal set: audio (sndio), gio, playback, Ogg Vorbis
# plugins-good	audio mixer (oss)
# plugins-ugly	mp3 decoding, dvd
# plugins-bad	vaapi
# plugins-libav	divx, mpeg4, h264, vp8 (same decoding capabilities as FFmpeg)
#
# i.e. applications that use GStreamer require:
#     gstreamer1-plugins-base and gstreamer1-plugins-good
# audio/video support for MP3 decoding requires:
#     gstreamer1-plugins-ugly
# support for most video codecs is provided by
#     gstreamer1-plugins-libav

PORTROACH=		limitw:1,even

V ?=			1.14.4
API=			1.0
SUBST_VARS +=		API

CATEGORIES ?=		multimedia devel

HOMEPAGE ?=		http://gstreamer.freedesktop.org/

MAINTAINER ?=		Antoine Jacoutot <ajacoutot@openbsd.org>

GST_PKGNAME_PREFIX=	gstreamer1

# GPLv2 - GPLv2+ - LGPLv2
PERMIT_PACKAGE_CDROM ?=	Yes
PERMIT_PACKAGE_FTP ?=	Yes
PERMIT_DISTFILES_FTP ?=	Yes

DIST_SUBDIR=		gstreamer
MASTER_SITE_GST=	http://gstreamer.freedesktop.org/src/
EXTRACT_SUFX ?=		.tar.xz
P=			multimedia/${GST_PKGNAME_PREFIX}

.if defined(MULTI_PACKAGES)
.for i in ${MULTI_PACKAGES}
TEST_DEPENDS +=	${BASE_PKGPATH},${i}
.endfor
.else
TEST_DEPENDS +=	${BASE_PKGPATH}
.endif

MODULES +=		lang/python

COMPILER =		base-clang ports-gcc base-gcc
COMPILER_LANGS ?=	c
MODGCC4_ARCHS =		powerpc

# python is only used to generate documentation
MODPY_RUNDEP=		No

USE_GMAKE ?=		Yes
AUTOCONF_VERSION ?=	2.69

CONFIGURE_STYLE ?=	autoconf
CONFIGURE_ENV +=	CPPFLAGS="${CPPFLAGS}" \
			LDFLAGS="${LDFLAGS}"
CONFIGURE_ARGS +=	--with-package-name="OpenBSD ${DISTNAME} package" \
			--with-package-origin="https://www.openbsd.org/" \
			--with-default-audiosink=sndiosink \
			--with-default-audiosrc=sndiosrc \
			--with-default-videosink=xvimagesink \
			--with-default-videosrc=v4l2src \
			--with-default-visualizer=goom \
			--enable-introspection \
			--disable-valgrind

# BDEP on gtk+2|gtk+3
CONFIGURE_ARGS +=	--disable-examples

CPPFLAGS +=		-I${LOCALBASE}/include \
			-I${X11BASE}/include
LDFLAGS +=		-L${LOCALBASE}/lib \
			-L${X11BASE}/lib

.if !target(post-install)
post-install:
	rm ${PREFIX}/lib/gstreamer-${API}/*.{a,la}
.endif
