# $OpenBSD: Makefile,v 1.1.1.1 2018/07/11 15:10:47 chrisz Exp $

BROKEN =	in preparation for OCaml 4.06
COMMENT =	library for arithmetic on big integers and rationals
CATEGORIES =	math

V =		1.1
GH_ACCOUNT =	ocaml
GH_PROJECT =	num
#GH_TAGNAME =	v${V}
# This commit includes a necessary fix for installing via findlib.
# XXX: Switch back to GH_TAGNAME on next update
GH_COMMIT =	7dd5e935aaa2b902585b3b2d0e55ad9b2442fff0
DISTNAME =	${GH_PROJECT}-${V}
PKGNAME =	ocaml-${DISTNAME}
HOMEPAGE =	https://github.com/ocaml/num/

MAINTAINER =	Christopher Zimmermann <chrisz@openbsd.org>


# LGPL 2.1
PERMIT_PACKAGE_CDROM =		Yes

MODULES =	lang/ocaml

BUILD_DEPENDS =	sysutils/findlib

USE_GMAKE =	Yes

.include <bsd.port.arch.mk>
.if ${PROPERTIES:Mocaml_native}
MAKE_ENV =	NATIVE=true
.else
MAKE_ENV =	NATIVE=false
.endif

INSTALL_TARGET = findlib-install

.include <bsd.port.mk>
