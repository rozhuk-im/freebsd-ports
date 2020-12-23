# Created by: Rozhuk Ivan 2020 <rozhuk.im@gmail.com>
# $FreeBSD$

PORTNAME=	opentoonz
DISTVERSIONPREFIX=v
DISTVERSION=	1.4.0.20201221
PORTREVISION=	0
CATEGORIES=	graphics

PATCH_SITES=	https://github.com/${GH_ACCOUNT}/${GH_PROJECT}/commit/
#PATCHFILES+=	5170aae3.patch:-p3 # cppcheck

MAINTAINER=	rozhuk.im@gmail.com
COMMENT=	Open-source full-featured 2D animation creation software

LICENSE=	GPLv2+
LICENSE_FILE=	${WRKSRC}/../../LICENSE.txt

BUILD_DEPENDS=	${LOCALBASE}/lib/qt5/bin/qmake:devel/qt5-qmake	\
		${LOCALBASE}/lib/qt5/bin/moc:devel/qt5-buildtools
LIB_DEPENDS=	libboost_system.so:devel/boost-libs \
		libpng16.so:graphics/png \
		libfreetype.so:print/freetype2 \
		libsuperlu.so:math/superlu \
		libmypaint.so:graphics/libmypaint
RUN_DEPENDS=	${LOCALBASE}/bin/ffprobe:multimedia/ffmpeg

USES=		cmake:noninja compiler:c++11-lang desktop-file-utils \
		qt:5 gl localbase pkgconfig
USE_CXXSTD=	c++11
USE_GL=		gl glu glut glew
USE_QT=		core gui linguisttools multimedia network opengl \
		printsupport script svg widgets

USE_GITHUB=	yes
GH_TAGNAME=	6cb7a21e2b5cc88e4d4dcada3bfc38cc9930ee07
WRKSRC_SUBDIR=	toonz/sources
CMAKE_ARGS=	-DWITH_SYSTEM_LZO:BOOL=ON \
		-DWITH_SYSTEM_SUPERLU:BOOL=ON \
		-DWITH_STOPMOTION:BOOL=OFF
INSTALLS_ICONS=	yes

OPTIONS_SINGLE=		BLASLIB
OPTIONS_SINGLE_BLASLIB=	NETLIB OPENBLAS
OPTIONS_DEFAULT=	OPENBLAS

NETLIB_USES=		blaslapack:netlib
NETLIB_VARS=		BLASLIBS="cblas blas"
NETLIB_LIB_DEPENDS=	libcblas.so:math/cblas
OPENBLAS_USES=		blaslapack:openblas
OPENBLAS_VARS=		BLASLIBS="openblas gfortran"

.include <bsd.port.options.mk>

.if defined(WITH_DEBUG)
CXXFLAGS+=	-DDEBUG -g3 -ggdb
.else
CXXFLAGS+=	-DNDEBUG
.endif

post-extract:
	${FIND} ${WRKSRC}/../../ -name '*.gitkeep' -delete

post-patch:
	@${REINPLACE_CMD} -e "s|find_library(OPENBLAS_LIB NAMES.*|find_library(OPENBLAS_LIB NAMES ${BLASLIBS})|g" \
		${WRKSRC}/CMakeLists.txt

.include <bsd.port.mk>
