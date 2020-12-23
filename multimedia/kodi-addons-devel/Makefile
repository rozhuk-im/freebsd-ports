# Created by: Rozhuk Ivan <rozhuk.im@gmail.com>
# $FreeBSD: head/multimedia/kodi-addons-devel/Makefile 528699 2020-03-19 07:54:02Z tobik $

PORTNAME=	kodi-addons
PORTVERSION=	19.0
CATEGORIES=	multimedia
PKGNAMESUFFIX=	-devel

MAINTAINER=	rozhuk.im@gmail.com
COMMENT=	Kodi addons meta-port

USES=		metaport

GAME_ADDONS=	beetle-bsnes \
		beetle-psx \
		fceumm \
		genplus \
		pcsx-rearmed \
		picodrive

INPUTSTREAM_ADDONS=	adaptive

PERIPHERAL_ADDONS=	joystick

SCREENSAVER_ADDONS=	biogenesis \
			matrixtrails \
			stars

VFS_ADDONS=		libarchive

VISUALIZATION_ADDONS=	fishbmc \
			shadertoy \
			spectrum


.for _type in game inputstream peripheral screensaver vfs visualization
OPTIONS_GROUP+=		${_type:tu}
${_type:tu}_DESC=	${_type} addons
. for _addon in ${${_type:tu}_ADDONS}
OPTIONS_GROUP_${_type:tu}+=	${_addon:tu}
. endfor
.endfor


.include <bsd.port.options.mk>


.for _addon in ${GAME_ADDONS}
${_addon:tu}_DESC!=		${MAKE} -C ../kodi-addon-game.libretro.${_addon}-devel -V COMMENT
. if ${PORT_OPTIONS:M${_addon:tu}} != ""
RUN_DEPENDS+=	kodi-addon-game.libretro.${_addon}-devel>=0:multimedia/kodi-addon-game.libretro.${_addon}-devel
. endif
.endfor

.for _type in inputstream peripheral screensaver vfs visualization
. for _addon in ${${_type:tu}_ADDONS}
${_addon:tu}_DESC!=		${MAKE} -C ../kodi-addon-${_type}.${_addon}-devel -V COMMENT
.  if ${PORT_OPTIONS:M${_addon:tu}} != ""
RUN_DEPENDS+=	kodi-addon-${_type}.${_addon}-devel>=0:multimedia/kodi-addon-${_type}.${_addon}-devel
.  endif
. endfor
.endfor

.include <bsd.port.mk>
