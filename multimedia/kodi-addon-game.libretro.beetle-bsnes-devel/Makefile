# Created by: Rozhuk Ivan <rozhuk.im@gmail.com>
# $FreeBSD: head/multimedia/kodi-addon-game.libretro.beetle-bsnes-devel/Makefile 528699 2020-03-19 07:54:02Z tobik $

PORTNAME=	game.libretro.beetle-bsnes
PORTVERSION=	0.9.26.7
DISTVERSIONSUFFIX=	-Leia
CATEGORIES=	multimedia games
PKGNAMEPREFIX=	kodi-addon-
PKGNAMESUFFIX=	-devel

MAINTAINER=	rozhuk.im@gmail.com
COMMENT=	Nintendo - SNES / SFC (Beetle bsnes) for Kodi

LICENSE=	GPLv2+

LIBRETRO_PORT=	libretro-beetle_bsnes

RUN_DEPENDS=	kodi-addon-game.libretro-devel>=0:multimedia/kodi-addon-game.libretro-devel \
		${LIBRETRO_PORT}>=0:games/${LIBRETRO_PORT}

NO_ARCH=	yes

USE_GITHUB=	yes
GH_ACCOUNT=	kodi-game

do-build:
	@LIBRARY_FILENAME=`${MAKE} -C ../../games/${LIBRETRO_PORT} -V PLIST_FILES | ${SED} 's| .*||g'` && \
	${REINPLACE_CMD} -e 's|@PLATFORM@|freebsd|g' \
		-e "s|@LIBRARY_FILENAME@|${LOCALBASE}/$${LIBRARY_FILENAME}|g" \
		${WRKSRC}/${PORTNAME}/addon.xml.in
	@${MV} ${WRKSRC}/${PORTNAME}/addon.xml.in ${WRKSRC}/${PORTNAME}/addon.xml
	@${RM} -f ${WRKSRC}/${PORTNAME}/addon.xml.in.bak

do-install:
	@${MKDIR} ${STAGEDIR}${PREFIX}/share/kodi/addons
	@(cd ${WRKSRC} && ${COPYTREE_SHARE} ${PORTNAME} ${STAGEDIR}${PREFIX}/share/kodi/addons)

post-stage:
	@${SETENV} ${CO_ENV} ${SH} ${SCRIPTSDIR}/check-stagedir.sh makeplist | \
		${GREP} -v ^\/ > ${TMPPLIST}

.include <bsd.port.mk>
