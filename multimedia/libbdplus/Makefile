# $OpenBSD: Makefile,v 1.3 2017/11/21 00:13:02 naddy Exp $

COMMENT =		BD+ support library for Blu-ray playback

V =			0.1.2
DISTNAME =		libbdplus-${V}
REVISION =		0

CATEGORIES =		multimedia

HOMEPAGE =		http://www.videolan.org/developers/libbdplus.html
MASTER_SITES =		https://download.videolan.org/pub/videolan/libbdplus/${V}/ \
			ftp://ftp.videolan.org/pub/videolan/libbdplus/${V}/
EXTRACT_SUFX =		.tar.bz2

# LGPL v2.1
PERMIT_PACKAGE_CDROM =	Free speech issue
PERMIT_PACKAGE_FTP =	Yes

WANTLIB =  gcrypt gpg-error iconv intl pthread

SHARED_LIBS +=		bdplus	0.0	# 1.0


LIB_DEPENDS =		security/libgcrypt

SEPARATE_BUILD =	Yes
CONFIGURE_STYLE =	gnu
CONFIGURE_ARGS =	--disable-optimizations \
			--without-libaacs

.include <bsd.port.mk>
