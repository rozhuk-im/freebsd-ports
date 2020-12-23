# Created by: Rozhuk Ivan <rozhuk.im@gmail.com>
# $FreeBSD: head/multimedia/kodi-addon-game.libretro.pcsx-rearmed-devel/Makefile 528699 2020-03-19 07:54:02Z tobik $

PORTNAME=	game.libretro.pcsx-rearmed
PORTVERSION=	22.0.0.9
DISTVERSIONSUFFIX=	-Leia
CATEGORIES=	multimedia games
PKGNAMEPREFIX=	kodi-addon-
PKGNAMESUFFIX=	-devel

MAINTAINER=	rozhuk.im@gmail.com
COMMENT=	Sony - PlayStation (PCSX ReARMed) for Kodi

LICENSE=	GPLv2+
LICENSE_FILE=	${WRKSRC}/depends/common/pcsx-rearmed/COPYING

BUILD_DEPENDS=	kodi-devel>=19.0.a20200318:multimedia/kodi-devel
LIB_DEPENDS=	libtinyxml.so:textproc/tinyxml
RUN_DEPENDS=	kodi-devel>=19.0.a20200318:multimedia/kodi-devel \
		kodi-addon-game.libretro-devel>=0:multimedia/kodi-addon-game.libretro-devel

USES=		cmake:noninja gmake
USE_GITHUB=	yes
GH_ACCOUNT=	kodi-game \
		libretro:pcsx_rearmed
GH_PROJECT=	pcsx_rearmed:pcsx_rearmed
# Keep in sync with: depends/common/pcsx-rearmed/pcsx-rearmed.txt
GH_TAGNAME=	3c4ac5bb44b41d23eec217369eaa34f4e155f733:pcsx_rearmed

PLIST_SUB=	SOVERSION=${PORTVERSION}

CMAKE_ARGS=	-DBUILD_SHARED_LIBS=1 \
		-DADDONS_TO_BUILD=${PORTNAME} \
		-DPCSX-REARMED_LIB=depends/common/pcsx-rearmed/pcsx_rearmed_libretro.so

post-extract:
	@${MV} ${WRKSRC_pcsx_rearmed}/* ${WRKSRC}/depends/common/pcsx-rearmed/

post-patch:
	@${REINPLACE_CMD} -e 's|find_library(PCSX-REARMED_LIB.*|add_subdirectory(depends/common/pcsx-rearmed)|g' \
		${WRKSRC}/CMakeLists.txt

post-install:
	rm -rf ${STAGEDIR}${PREFIX}/lib/libretro

.include <bsd.port.mk>
