# Created by: Rozhuk Ivan <rozhuk.im@gmail.com>
# $FreeBSD: head/multimedia/kodi-addon-game.libretro.picodrive-devel/Makefile 528699 2020-03-19 07:54:02Z tobik $

PORTNAME=	game.libretro.picodrive
PORTVERSION=	1.92.0.10
DISTVERSIONSUFFIX=	-Leia
CATEGORIES=	multimedia games
PKGNAMEPREFIX=	kodi-addon-
PKGNAMESUFFIX=	-devel

MAINTAINER=	rozhuk.im@gmail.com
COMMENT=	Sega - MS/MD/CD/32X (PicoDrive) for Kodi

LICENSE_FILE=	${WRKSRC}/depends/common/picodrive/COPYING

BUILD_DEPENDS=	kodi-devel>=19.0.a20200318:multimedia/kodi-devel
LIB_DEPENDS=	libtinyxml.so:textproc/tinyxml
RUN_DEPENDS=	kodi-devel>=19.0.a20200318:multimedia/kodi-devel \
		kodi-addon-game.libretro-devel>=0:multimedia/kodi-addon-game.libretro-devel

USES=		cmake:noninja gmake
USE_GITHUB=	yes
GH_ACCOUNT=	kodi-game \
		libretro:picodrive
GH_PROJECT=	picodrive:picodrive
# Keep in sync with: depends/common/picodrive/picodrive.txt
GH_TAGNAME=	600894ec6eb657586a972a9ecd268f50907a279c:picodrive

PLIST_SUB=	SOVERSION=${PORTVERSION}

CMAKE_ARGS=	-DCMAKE_BUILD_TYPE=Release \
		-DBUILD_SHARED_LIBS=1 \
		-DADDONS_TO_BUILD=${PORTNAME} \
		-DPICODRIVE_LIB=depends/common/picodrive/picodrive_libretro.so

post-extract:
	@${MV} ${WRKSRC_picodrive}/* ${WRKSRC}/depends/common/picodrive/

post-patch:
	@${REINPLACE_CMD} -e 's|find_library(PICODRIVE_LIB.*|add_subdirectory(depends/common/picodrive)|g' \
		${WRKSRC}/CMakeLists.txt

post-install:
	rm -rf ${STAGEDIR}${PREFIX}/lib/libretro

.include <bsd.port.mk>
