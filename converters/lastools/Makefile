# $OpenBSD: Makefile,v 1.7 2018/10/24 14:27:59 sthen Exp $

COMMENT =	tools for LiDAR processing
DISTNAME =	lastools-0.20170108
GH_ACCOUNT =	LAStools
GH_PROJECT =	LAStools
GH_TAGNAME =	f00fa125075ea984993057c5916d746cb605835c
REVISION =	2

CATEGORIES =	converters textproc devel

# LGPLv2.1
PERMIT_PACKAGE_CDROM =	Yes

WANTLIB += c m ${COMPILER_LIBCXX}

COMPILER =		base-clang ports-gcc base-gcc

MAKE_FLAGS =	COMPILER="${CXX}" \
		LINKER="${CXX}"

post-patch:
	find ${WRKSRC} -name Makefile | xargs sed -i 's/-O3/${CXXFLAGS}/'

PROGS =	laszip lasinfo lasprecision las2txt txt2las las2las lasdiff lasmerge lasindex

do-install:
	${INSTALL_DATA} ${WRKSRC}/LASlib/src/liblas.a ${PREFIX}/lib/
	${INSTALL_DATA} ${WRKSRC}/LASlib/inc/*.hpp ${PREFIX}/include/
	${INSTALL_DATA} ${WRKSRC}/LASzip/src/{mydefs,laspoint,laszip,lasquantizer,lasattributer}.hpp \
		${PREFIX}/include/
	${INSTALL_DATA_DIR} ${PREFIX}/share/doc/lastools/
.for f in ${PROGS}
	${INSTALL_PROGRAM} ${WRKSRC}/bin/${f} ${PREFIX}/bin/
	${INSTALL_DATA} ${WRKSRC}/bin/${f}_README.txt ${PREFIX}/share/doc/lastools/
.endfor

.include <bsd.port.mk>
