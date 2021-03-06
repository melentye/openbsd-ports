# $OpenBSD: Makefile,v 1.27 2018/07/26 13:40:52 fcambus Exp $

COMMENT =		emulator for Nintendo Game Boy (Color/Advance)
BROKEN-alpha =		ICE or OOM on hq_implementation.cpp
BROKEN-hppa =		ICE or OOM on src/filters/hq/c/hq_base.h:421

GH_ACCOUNT =		visualboyadvance-m
GH_PROJECT =		${GH_ACCOUNT}
GH_TAGNAME =		v2.1.0
PKGNAME =		vbam-${GH_TAGNAME:S/v//}

CATEGORIES =		emulators

HOMEPAGE =		http://www.vba-m.com

# GPLv2+ (see doc/License.txt)
PERMIT_PACKAGE_CDROM =		Yes

WANTLIB += ${COMPILER_LIBCXX}
WANTLIB += GL GLU SDL2 c iconv intl m png sfml-network sfml-system
WANTLIB += z

MODULES =		devel/cmake

# c++11
COMPILER =		base-clang ports-gcc

BUILD_DEPENDS =		devel/gettext-tools

LIB_DEPENDS =		devel/gettext \
			devel/sdl2 \
			graphics/png \
			multimedia/sfml

CONFIGURE_ARGS +=	-DENABLE_FFMPEG=OFF \
			-DENABLE_WX=OFF \
			-DENABLE_SDL=ON
# Creates unlinkable files ('data' according to file(1))
CONFIGURE_ARGS +=	-DENABLE_LTO=OFF
# Assembler autodetection fails on i386, can be worked around with
# -DCMAKE_ASM_NASM_COMPILER=yasm, but then linking fails.
CONFIGURE_ARGS +=	-DENABLE_ASM=OFF

CXXFLAGS +=		-Wno-c++11-narrowing -I${X11BASE}/include

NO_TEST =		Yes

post-install:
	mv ${PREFIX}/etc/ ${PREFIX}/share/examples/vbam/

.include <bsd.port.mk>
