# $OpenBSD: Makefile,v 1.46 2018/10/24 14:28:00 sthen Exp $

# Memory hog, stuck for days on the same file (configoptions.cpp) during build.
# XXX check with different optimizer level? see doc/install.doc
NOT_FOR_ARCHS=	m88k sh
BROKEN-alpha=	.got subsegment exceeds 64K

COMMENT=	source code documentation generator tool

VERSION=	1.8.14
DISTNAME=	doxygen-${VERSION}.src
PKGNAME=	doxygen-${VERSION}
REVISION=	0

CATEGORIES=	devel textproc

HOMEPAGE=	http://www.doxygen.org/

MAINTAINER=	Rafael Sadowski <rsadowski@openbsd.org>

# GPLv2
PERMIT_PACKAGE_CDROM=	Yes

WANTLIB += c iconv m pthread ${COMPILER_LIBCXX} xapian z

COMPILER =		base-clang ports-gcc base-gcc

MASTER_SITES=	http://ftp.stack.nl/pub/users/dimitri/ \
		ftp://ftp.stack.nl/pub/users/dimitri/

LIB_DEPENDS=	converters/libiconv \
		databases/xapian-core

MODULES=	devel/cmake \
		lang/python

MODPY_RUNDEP=	No

.if ${MACHINE_ARCH} == "mips64" || ${MACHINE_ARCH} == "mips64el"
CXXFLAGS+=	-mxgot
.endif

BUILD_DEPENDS+=	devel/bison

RUN_DEPENDS+=	print/ghostscript/gnu \
		math/graphviz

CONFIGURE_ARGS+=-Dbuild_doc:Bool=ON \
		-Dbuild_app:Bool=ON \
		-Dbuild_search:Bool=ON

WRKDIST=	${WRKDIR}/doxygen-${VERSION}

NO_TEST=	Yes

.include <bsd.port.mk>
