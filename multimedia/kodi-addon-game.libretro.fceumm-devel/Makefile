# Created by: Rozhuk Ivan <rozhuk.im@gmail.com>
# $FreeBSD: head/multimedia/kodi-addon-game.libretro.fceumm-devel/Makefile 528699 2020-03-19 07:54:02Z tobik $

PORTNAME=	game.libretro.fceumm
PORTVERSION=	0.0.1.14
DISTVERSIONSUFFIX=	-Leia
CATEGORIES=	multimedia games
PKGNAMEPREFIX=	kodi-addon-
PKGNAMESUFFIX=	-devel

MAINTAINER=	rozhuk.im@gmail.com
COMMENT=	NES / Famicom (FCEUmm) for Kodi

LICENSE=	GPLv2+

BUILD_DEPENDS=	kodi-devel>=19.0.a20200318:multimedia/kodi-devel
LIB_DEPENDS=	libtinyxml.so:textproc/tinyxml
RUN_DEPENDS=	kodi-devel>=19.0.a20200318:multimedia/kodi-devel \
		kodi-addon-game.libretro-devel>=0:multimedia/kodi-addon-game.libretro-devel

USES=		cmake:noninja gmake localbase
USE_GITHUB=	yes
GH_ACCOUNT=	kodi-game \
		libretro:fceumm
GH_PROJECT=	libretro-fceumm:fceumm
# Keep in sync with: depends/common/fceumm/fceumm.txt
GH_TAGNAME=	0d569e9bab054f215f828184c1d63fa69f8abd0c:fceumm

PLIST_SUB=	SOVERSION=${PORTVERSION}

CMAKE_ARGS=	-DBUILD_SHARED_LIBS=1 \
		-DADDONS_TO_BUILD=${PORTNAME} \
		-DFCEUMM_LIB=depends/common/fceumm/fceumm_libretro.so

post-extract:
	@${MV} ${WRKSRC_fceumm}/* ${WRKSRC}/depends/common/fceumm/

post-patch:
	@${REINPLACE_CMD} -e 's|find_library(FCEUMM_LIB.*|add_subdirectory(depends/common/fceumm)|g' \
		${WRKSRC}/CMakeLists.txt

post-install:
	rm -rf ${STAGEDIR}${PREFIX}/lib/libretro

.include <bsd.port.mk>
