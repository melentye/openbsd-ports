# $OpenBSD: Makefile,v 1.3 2017/12/23 11:32:28 landry Exp $

COMMENT =	viewer for geospatial point clouds
GH_ACCOUNT =	c42f
GH_PROJECT =	displaz
GH_TAGNAME =	v0.4.0

HOMEPAGE =	http://c42f.github.io/displaz/

CATEGORIES =	graphics

# BSD 3-clause
PERMIT_PACKAGE_CDROM =	Yes

MODULES =	devel/cmake x11/qt5
LIB_DEPENDS =	graphics/glew>=2.0 \
		graphics/ilmbase

# links with static liblas.a
BUILD_DEPENDS =	textproc/py-docutils \
		converters/lastools

WANTLIB += GL GLEW Iex Imath Qt5Core Qt5Gui Qt5Network Qt5OpenGL
WANTLIB += Qt5Widgets c m pthread
WANTLIB += ${COMPILER_LIBCXX}

CONFIGURE_ARGS =	-DDISPLAZ_EMBED_GLEW=false \
			-DLASLIB_LIBRARY=${LOCALBASE}/lib/liblas.a \

SUBST_VARS +=	TRUEPREFIX
post-patch:
	${SUBST_CMD} ${WRKSRC}/src/gui/guimain.cpp

post-install:
	# glsl 1.4 works..
	 sed -i -e 's/^#version 150/#version 140/' ${PREFIX}/share/displaz/shaders/*.glsl

.include <bsd.port.mk>
