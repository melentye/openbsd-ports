# $OpenBSD: Makefile,v 1.29 2018/04/26 16:01:45 ajacoutot Exp $

COMMENT=		library for fingerprint reader devices

DISTNAME=		libfprint-0.6.0

CATEGORIES=    		security

SHARED_LIBS +=  fprint               1.1      # 0.0

HOMEPAGE=a		http://www.freedesktop.org/wiki/Software/fprint/libfprint
MASTER_SITES=		http://people.freedesktop.org/~hadess/
EXTRACT_SUFX=		.tar.xz

MAINTAINER=		Robert Nagy <robert@openbsd.org>

# LGPLv2.1
PERMIT_PACKAGE_CDROM=	Yes

WANTLIB += glib-2.0 iconv intl m nspr4 nss3 nssutil3 pcre pixman-1
WANTLIB += plc4 plds4 pthread smime3 ssl3 usb-1.0

CONFIGURE_STYLE=	gnu

LIB_DEPENDS=		devel/glib2 \
			devel/libusb1 \
			security/nss

post-install:
	rm -r ${WRKINST}/rules.d

.include <bsd.port.mk>
