PORTNAME=	opentoonz
DISTVERSIONPREFIX=	v
DISTVERSION=	1.7.1
CATEGORIES=	multimedia

PATCH_SITES=	https://github.com/${GH_ACCOUNT}/${GH_PROJECT}/commit/
PATCHFILES+=	6ef6ec2ce4e1da96c64172dbf97a0ff901808bb9.patch:-p1 # https://github.com/opentoonz/opentoonz/pull/5093

MAINTAINER=	rozhuk.im@gmail.com
COMMENT=	Open-source full-featured 2D animation creation software
WWW=		https://opentoonz.github.io/e/

LICENSE=	GPLv2+
LICENSE_FILE=	${WRKSRC}/LICENSE.txt

BUILD_DEPENDS=	boost-libs>0:devel/boost-libs
LIB_DEPENDS=	libfreetype.so:print/freetype2 \
		libjson-c.so:devel/json-c \
		liblz4.so:archivers/liblz4 \
		liblzo2.so:archivers/lzo2 \
		libmypaint.so:graphics/libmypaint \
		libopencv_core.so:graphics/opencv \
		libpng.so:graphics/png \
		libsuperlu.so:math/superlu \
		libturbojpeg.so:graphics/libjpeg-turbo
RUN_DEPENDS=	${LOCALBASE}/bin/ffprobe:multimedia/ffmpeg

USES=		cmake:noninja compiler:c++11-lang gettext-runtime gl \
		gnome jpeg pkgconfig qt:5
USE_GITHUB=	yes
USE_GL=		gl glew glu glut
USE_GNOME=	glib20
USE_QT=		core gui multimedia network opengl printsupport \
		script serialport svg uitools widgets xml \
		buildtools:build linguisttools:build qmake:build
CMAKE_ARGS=	-DWITH_SYSTEM_LZO:BOOL=ON \
		-DWITH_SYSTEM_SUPERLU:BOOL=ON
CMAKE_SOURCE_PATH=	${WRKSRC}/toonz/sources

OPTIONS_SINGLE=		BLASLIB
OPTIONS_SINGLE_BLASLIB=	CBLAS GSLCBLAS OPENBLAS
OPTIONS_DEFAULT=	OPENBLAS

CBLAS_LIB_DEPENDS=	libcblas.so:math/cblas
CBLAS_VARS=		BLASLIBS="cblas"
CBLAS_DESC=		C interface to the legacy Fortran BLAS
GSLCBLAS_LIB_DEPENDS=	libgslcblas.so:math/gsl
GSLCBLAS_VARS=		BLASLIBS="gslcblas"
GSLCBLAS_DESC=		The GNU Scientific Library - mathematical libs
OPENBLAS_USES=		blaslapack:openblas
OPENBLAS_VARS=		BLASLIBS="openblas"

.include <bsd.port.options.mk>

.if defined(WITH_DEBUG)
CXXFLAGS+=	-DDEBUG -g3 -ggdb
.else
CXXFLAGS+=	-DNDEBUG
.endif

post-extract:
	${FIND} ${WRKSRC} -name '*.gitkeep' -delete

post-patch:
	@${REINPLACE_CMD} -e "s|find_library(OPENBLAS_LIB NAMES.*|find_library(OPENBLAS_LIB NAMES ${BLASLIBS})|g" \
		${WRKSRC}/toonz/sources/CMakeLists.txt

post-install:
	@${STRIP_CMD} ${STAGEDIR}${PREFIX}/bin/lzo*
	@${STRIP_CMD} ${STAGEDIR}${PREFIX}/bin/OpenToonz
	@${STRIP_CMD} ${STAGEDIR}${PREFIX}/bin/t*
	@${STRIP_CMD} ${STAGEDIR}${PREFIX}/lib/opentoonz/*.so

.include <bsd.port.mk>
