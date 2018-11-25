# $OpenBSD: Makefile.template,v 1.78 2018/07/09 15:00:06 jca Exp $
#
# Replace ??? with appropriate values
# Remove extraneous comments before commit
# Use /usr/ports/infrastructure/bin/portcheck

# Reasons why the port/package shouldn't be built
#
#ONLY_FOR_ARCHS =	???
#NOT_FOR_ARCHS =	???
#COMES_WITH =		???
#BROKEN =		reason

#
# Very short description of the package, 60 chars max
#		|----------------------------------------------------------|
COMMENT =	Telegram Desktop messaging app
# COMMENT-foo =	???	for multi packages

#
# What port/package will be created
#
GH_ACCOUNT =	telegramdesktop
GH_PROJECT =	tdesktop
GH_TAGNAME =	v1.4.7
DISTNAME =	telegram-desktop-${GH_TAGNAME:C/^v//}

#
# github:
# /releases/ -> preferred. ignore GH_*, just use MASTER_SITES and DISTNAME.
# /archive/ ->  GH_ACCOUNT and GH_PROJECT, plus either GH_TAGNAME or GH_COMMIT.
#
# set DISTNAME if using GH_COMMIT, or if using GH_TAGNAME and the tag is not in
# the format "v1.00" or "1.00".
#
#GH_ACCOUNT =	username
#GH_PROJECT =	project
#GH_TAGNAME =	1.0
#GH_COMMIT =	abab123456789abacafeabab123123b1e4ble4bl

# for any port that creates shared libraries.
# both libtool and cmake automatically set filenames based on this variable.
# for libtool- or cmake-based ports, have a look at WRKBUILD/shared_libs.log
#SHARED_LIBS =	???

# the category used in the directory name, /usr/ports/<category>/portname,
# must be included and listed first.
CATEGORIES =	net www

HOMEPAGE =	https://github.com/telegramdesktop/tdesktop	

PERMIT_PACKAGE_CDROM =	Yes

# If pledge is used, annotate with `uses pledge()' in a comment

# "make port-lib-depends-check" can help
#WANTLIB =		???

# where the source files and patches can be fetched
#
#MASTER_SITES =		https://github.com/telegramdesktop/tdesktop/archive
#DISTFILES =		???
#EXTRACT_ONLY =		???
#EXTRACT_SUFX =		.tar.bz2

#DIST_SUBDIR =		???

# PATCHFILES are also retrieved from MASTER_SITES*
#PATCHFILES =		???
#PATCH_DIST_STRIP =	-p0

# Dependencies
#
COMPILER =		base-clang ports-gcc
MODULES =		devel/cmake
BUILD_DEPENDS =		devel/gyp
#RUN_DEPENDS =		???
#LIB_DEPENDS =		???
#TEST_DEPENDS =		???

#MAKE_FLAGS =		???
#MAKE_ENV =		???
#FAKE_FLAGS =		???
#TEST_FLAGS =		???

# build/configuration variables
#
SEPARATE_BUILD =	Yes
#SEPARATE_BUILD =	flavored (distinct flavors may share a common WRKSRC)
#USE_GMAKE =		Yes
#USE_GROFF =		Yes
# Programs that require GNU libtool to build instead of the OpenBSD one
# should use this option. Add a comment explaining why. Don't use this if
# a port requires libtool's .m4 files but otherwise can use OpenBSD libtool,
# in that case use "BUILD_DEPENDS=devel/libtool" instead.
#USE_LIBTOOL=		gnu
# Set CONFIGURE_STYLE to value corresponding to some standard configuration
# 	  perl [modbuild]: perl's MakeMaker Makefile.PL (modbuild: perl's
#	  Module::Build Build.PL)
# 	  gnu [autoconf] [old] [dest]: gnu style configure (old: no
# 	  sysconfdir), (dest: add DESTDIR, does not handle it),
# 	  (autoconf: needed by port, implies gnu)
# 	XXX: cygnus products do NOT use autoconf for making the main
# 		configure from configure.in
# 	  imake [noman]: port uses imake for configuration.
#	  (noman: no man page installation)
# 	  simple: port has its own configure script
#CONFIGURE_STYLE =	
#CONFIGURE_SCRIPT =	??? (if other than configure)
#CONFIGURE_ARGS =	???
#CONFIGURE_ENV =	???

# for gnu stuff
#AUTOCONF_VERSION =	??? (defaults to 2.13)
#AUTOMAKE_VERSION =	??? (defaults to 1.4)
# config.guess and others are copied here
#MODGNU_CONFIG_GUESS_DIRS = ??? (defaults to ${WRKSRC})

# Is the build automagic or is it interactive
#
#IS_INTERACTIVE =		Yes
#TEST_IS_INTERACTIVE =		Yes

# Assume you have one multiple choice flavor: 1 2 3 and switches a b.
# You would write
#
#FLAVORS =	1 2 3 a b
#FLAVOR ?=
# grab multiple choice value
#CHOICE = ${FLAVOR:Na:Nb}
# check that CHOICE is 1 OR 2 OR 3, or error out
#.if ${CHOICE} == "1"
# code for 1
#.elif ${CHOICE} == "2"
# code for 2
#.elif ${CHOICE} == "3"
# code for 3
#.else
#ERRORS += "Fatal: Conflicting flavor: ${FLAVOR}"
#.endif
# check for switches
#.if ${FLAVOR:Ma}
# code for a
#.endif
#.if ${FLAVOR:Mb}
# code for b
#.endif

# Things that we don't want to do for this port/package
# Generally, DON'T set anything to No if it's not needed.
# The time gained is not worth it.
#
#NO_BUILD =		Yes
#NO_TEST =		Yes

# Overrides for default values
#
#CFLAGS =		???
#LDFLAGS =		???
#MAKE_FILE =		???
#PKG_ARCH =		??? (* for arch-independent packages)
#WRKDIST =		??? if other than ${WRKDIR}/${DISTNAME}
#WRKSRC =		??? if other than ${WRKDIST}
#WRKBUILD =		??? if other than ${WRKSRC}
#WRKCONF =		??? if other than ${WRKBUILD}

#ALL_TARGET =		???
#INSTALL_TARGET =	???
#TEST_TARGET =		???

TELEGRAM_API_ID =	17349
TELEGRAM_API_HASH =	344583e45741c457fe1862106095a5eb

GYP_DEFINES= TDESKTOP_DISABLE_CRASH_REPORTS,TDESKTOP_DISABLE_AUTOUPDATE,TDESKTOP_DISABLE_REGISTER_CUSTOM_SCHEME

pre-configure:
	cd ${WRKSRC} && gyp \
		--depth=Telegram/gyp \
		--format=cmake \
		--generator-output=${WRKBUILD} \
		-Gconfig=Release \
		-Goutput_dir=out \
		-Dapi_id=${TELEGRAM_API_ID} \
		-Dapi_hash=${TELEGRAM_API_HASH} \
		-Dbuild_defines=${GYP_DEFINES} \
		Telegram/gyp/Telegram.gyp

.include <bsd.port.mk>
