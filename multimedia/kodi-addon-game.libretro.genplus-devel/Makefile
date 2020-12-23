# Created by: Rozhuk Ivan <rozhuk.im@gmail.com>
# $FreeBSD: head/multimedia/kodi-addon-game.libretro.genplus-devel/Makefile 528699 2020-03-19 07:54:02Z tobik $

PORTNAME=	game.libretro.genplus
PORTVERSION=	1.7.4.9
DISTVERSIONSUFFIX=	-Leia
CATEGORIES=	multimedia games
PKGNAMEPREFIX=	kodi-addon-
PKGNAMESUFFIX=	-devel

MAINTAINER=	rozhuk.im@gmail.com
COMMENT=	Sega - MS/GG/MD/CD (Genesis Plus GX) for Kodi

LICENSE_FILE=	${WRKSRC}/depends/common/genplus/LICENSE.txt

BUILD_DEPENDS=	kodi-devel>=19.0.a20200318:multimedia/kodi-devel
LIB_DEPENDS=	libtinyxml.so:textproc/tinyxml
RUN_DEPENDS=	kodi-devel>=19.0.a20200318:multimedia/kodi-devel \
		kodi-addon-game.libretro-devel>=0:multimedia/kodi-addon-game.libretro-devel

USES=		cmake:noninja gmake
USE_GITHUB=	yes
GH_ACCOUNT=	kodi-game \
		libretro:genplus
GH_PROJECT=	Genesis-Plus-GX:genplus
# Keep in sync with: depends/common/genplus/genplus.txt
GH_TAGNAME=	50551066f71f8a5ea782ea3747891fd6d24ebe67:genplus

PLIST_SUB=	SOVERSION=${PORTVERSION}

CMAKE_ARGS=	-DCMAKE_BUILD_TYPE=Release \
		-DBUILD_SHARED_LIBS=1 \
		-DADDONS_TO_BUILD=${PORTNAME} \
		-DGENPLUS_LIB=depends/common/genplus/genesis_plus_gx_libretro.so

post-extract:
	@${MV} ${WRKSRC_genplus}/* ${WRKSRC}/depends/common/genplus/

post-patch:
	@${REINPLACE_CMD} -e 's|find_library(GENPLUS_LIB.*|add_subdirectory(depends/common/genplus)|g' \
		${WRKSRC}/CMakeLists.txt

post-install:
	rm -rf ${STAGEDIR}${PREFIX}/lib/libretro

.include <bsd.port.mk>
