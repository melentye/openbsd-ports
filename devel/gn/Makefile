# $OpenBSD: Makefile.template,v 1.78 2018/07/09 15:00:06 jca Exp $

COMMENT =	meta-build system that generates build files for Ninja

COMMIT_HASH =	dd2f4cf07d12d9e1535d43bd854d26c8f1abd9bb
# The tarballs are named after Git commit hashes
DISTNAME =	${COMMIT_HASH}
# Fake version, if upstream introduces one it'll likely be > 0
V = 		0
PKGNAME =	gn-${V}

CATEGORIES =	devel

HOMEPAGE =	https://gn.googlesource.com/gn/

MAINTAINER =	Andrey Melentyev <andrey.melentyev@gmail.com>

# BSD-like
PERMIT_PACKAGE_CDROM =	Yes

WANTLIB += ${COMPILER_LIBCXX} c m

MASTER_SITES =		https://gn.googlesource.com/gn/+archive/

COMPILER =		base-clang ports-gcc
MODULES =		lang/python
MODPY_RUNDEP =		No
BUILD_DEPENDS =		devel/ninja

SEPARATE_BUILD =	Yes
CONFIGURE_STYLE =	none

# tarball is flat
WRKDIST =		${WRKDIR}

do-configure:
	@cp ${FILESDIR}/build_bsd.ninja.template \
		${WRKSRC}/build/build_bsd.ninja.template
	exec ${SETENV} ${CONFIGURE_ENV} \
		${MODPY_BIN} \
		${WRKSRC}/build/gen.py \
		--no-last-commit-position \
		--out-path ${WRKBUILD}
	@sed -e "s|@LAST_COMMIT_POSITION@|${COMMIT_HASH}|g" \
		${FILESDIR}/last_commit_position.h > \
		${WRKBUILD}/last_commit_position.h

do-build:
	exec ${SETENV} ${MAKE_ENV} \
		${LOCALBASE}/bin/ninja -C ${WRKBUILD}

pre-test:
	@ln -sf ${MODPY_BIN} ${WRKDIR}/bin/python

do-test:
	@cd ${WRKSRC} && \
		exec ${SETENV} ${ALL_TEST_ENV} \
		${WRKBUILD}/gn_unittests

do-install:
	${INSTALL_PROGRAM} ${WRKBUILD}/gn ${PREFIX}/bin/

.include <bsd.port.mk>
