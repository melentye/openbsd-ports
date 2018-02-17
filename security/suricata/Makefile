# $OpenBSD: Makefile,v 1.2 2018/02/15 16:19:41 ajacoutot Exp $

COMMENT =	high performance network IDS, IPS and security monitoring

DISTNAME =	suricata-4.0.4
REVISION =	0
CATEGORIES =	security
SHARED_LIBS +=  htp                       0.0 # 1.0

HOMEPAGE =	https://suricata-ids.org/

MAINTAINER =	Gonzalo L. R. <gonzalo@openbsd.org> \
		Jasper Lievisse Adriaanse <jasper@openbsd.org>

# GPLv2
PERMIT_PACKAGE_CDROM=	Yes

MASTER_SITES =	https://www.openinfosecfoundation.org/download/

WANTLIB += c iconv jansson magic net nspr4 nss3 nssutil3 pcap
WANTLIB += pcre plc4 plds4 pthread smime3 ssl3 yaml-0 z

MODULES =	lang/python

BUILD_DEPENDS =	textproc/py-sphinx

LIB_DEPENDS =	converters/libiconv \
		devel/jansson \
		devel/nspr \
		devel/libyaml \
		devel/libmagic \
		devel/pcre \
		net/libnet/1.1 \
		security/nss

CONFIGURE_STYLE = gnu

CONFIGURE_ENV = ac_cv_path_HAVE_PDFLATEX= \
		ac_cv_path_HAVE_GIT_CMD=

post-install:
	${INSTALL_DATA_DIR} ${PREFIX}/share/examples/suricata/rules
	${INSTALL_DATA} ${WRKSRC}/*.config ${PREFIX}/share/examples/suricata
	${INSTALL_DATA} ${WRKSRC}/suricata.yaml ${PREFIX}/share/examples/suricata
	${INSTALL_DATA} ${WRKSRC}/rules/*.rules ${PREFIX}/share/examples/suricata/rules
	rm ${PREFIX}/share/doc/suricata/{*.txt,GITGUIDE,INSTALL*}
	${INSTALL_DATA} ${WRKSRC}/doc/{AUTHORS,NEWS,README,TODO} \
		${PREFIX}/share/doc/suricata

.include <bsd.port.mk>