# $OpenBSD: Makefile.template,v 1.78 2018/07/09 15:00:06 jca Exp $

# Use /usr/ports/infrastructure/bin/portcheck
COMMENT =	Experimental range library for C++11/14/17
GH_ACCOUNT =	ericniebler
GH_PROJECT =	range-v3
GH_TAGNAME =	0.4.0
DISTNAME =	${GH_PROJECT}-${GH_TAGNAME}

CATEGORIES =	devel

HOMEPAGE =	https://github.com/ericniebler/range-v3

# Most of the library code is BSL 1.0
# Code from libc++ is licensed as BSD-like or MIT
# Stepanov and McJones, "Elements of Programming" license
# SGI C++ Standard Template Library license
PERMIT_PACKAGE_CDROM =	Yes

COMPILER =		base-clang ports-gcc
MODULES =		devel/cmake

# Note: the build seems to be memory-hungry, it works on amd64 with
# ulimit -d 2621440

.include <bsd.port.mk>
