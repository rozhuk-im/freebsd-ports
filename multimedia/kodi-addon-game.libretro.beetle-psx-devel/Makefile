# Created by: Rozhuk Ivan <rozhuk.im@gmail.com>
# $FreeBSD: head/multimedia/kodi-addon-game.libretro.beetle-psx-devel/Makefile 528699 2020-03-19 07:54:02Z tobik $

PORTNAME=	game.libretro.beetle-psx
PORTVERSION=	0.9.44.12
DISTVERSIONSUFFIX=	-Leia
CATEGORIES=	multimedia games
PKGNAMEPREFIX=	kodi-addon-
PKGNAMESUFFIX=	-devel

MAINTAINER=	rozhuk.im@gmail.com
COMMENT=	Sony - PlayStation (Beetle PSX) for Kodi

LICENSE=	GPLv2+

BUILD_DEPENDS=	kodi-devel>=19.0.a20200318:multimedia/kodi-devel
LIB_DEPENDS=	libtinyxml.so:textproc/tinyxml
RUN_DEPENDS=	kodi-devel>=19.0.a20200318:multimedia/kodi-devel \
		kodi-addon-game.libretro-devel>=0:multimedia/kodi-addon-game.libretro-devel

USES=		cmake:noninja gmake localbase
USE_GITHUB=	yes
GH_ACCOUNT=	kodi-game \
		libretro:beetle_psx
GH_PROJECT=	beetle-psx-libretro:beetle_psx
# Keep in sync with: depends/common/beetle-psx/beetle-psx.txt
GH_TAGNAME=	c7c8ffd3d2cf1c780ccf98417e60908f9adf970d:beetle_psx

PLIST_SUB=	SOVERSION=${PORTVERSION}

CMAKE_ARGS=	-DBUILD_SHARED_LIBS=1 \
		-DADDONS_TO_BUILD=${PORTNAME} \
		-DBEETLE-PSX_LIB=depends/common/beetle-psx/mednafen_psx_libretro.so

post-extract:
	@${MV} ${WRKSRC_beetle_psx}/* ${WRKSRC}/depends/common/beetle-psx/

post-patch:
	@${REINPLACE_CMD} -e 's|find_library(BEETLE-PSX_LIB.*|add_subdirectory(depends/common/beetle-psx)|g' \
		${WRKSRC}/CMakeLists.txt
	@${REINPLACE_CMD} -e 's|defined(BSD)|!defined(CLOCK_REALTIME)|g' \
		${WRKSRC}/depends/common/beetle-psx/libretro-common/rthreads/rthreads.c

post-install:
	rm -rf ${STAGEDIR}${PREFIX}/lib/libretro

.include <bsd.port.mk>
