# $OpenBSD: Makefile,v 1.67 2018/09/04 12:46:20 espie Exp $

COMMENT=	driver for ZjStream wire protocol compatible printers

VERSION=	20170320
DISTNAME=	foo2zjs-${VERSION}
REVISION=	1

CATEGORIES=	print

HOMEPAGE=	http://foo2zjs.rkkda.com/

MAINTAINER=	Antoine Jacoutot <ajacoutot@openbsd.org>

# GPLv2
PERMIT_PACKAGE_CDROM=	Yes

WANTLIB += c cups m pthread

# unversioned distfile
# http://foo2zjs.rkkda.com/foo2zjs.tar.gz
MASTER_SITES=	https://distfiles.bsdfrog.org/

USE_GMAKE=	Yes

WRKDIST=	${WRKDIR}/foo2zjs

BUILD_DEPENDS=	print/ghostscript/gnu # ps2pdf

LIB_DEPENDS=	print/cups,-libs

# foomatic-rip(1), foomatic-db(-engine)
RUN_DEPENDS +=	print/cups-filters

# patch-foo2zjs-pstops_sh
RUN_DEPENDS +=	textproc/gsed

MAKE_FLAGS+=	CUPS_SERVERBIN=`cups-config --serverbin`

NO_TEST=	Yes

# remove CVS ID
post-extract:
	sed -i "s,^VERSION=.*,VERSION=\'${VERSION}\'," ${WRKSRC}/getweb.in

post-patch:
	ln -sf ${WRKSRC}/modify-ppd ${WRKDIR}/bin/modify-ppd

pre-configure:
	sed -i 's,/usr/bin,${PREFIX}/bin,g' \
		${WRKSRC}/*.1in
	${SUBST_CMD} ${WRKSRC}/getweb.in

post-install:
	${INSTALL_SCRIPT} ${WRKSRC}/{getweb,msexpand} \
		${PREFIX}/share/doc/foo2zjs
	${INSTALL_DATA_DIR} ${PREFIX}/libexec/cups/filter
	ln -sf ${TRUEPREFIX}/bin/command2foo2lava-pjl \
		${WRKINST}/${LOCALBASE}/libexec/cups/filter/

.include <bsd.port.mk>
