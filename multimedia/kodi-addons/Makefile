PORTNAME=	kodi-addons
PORTVERSION=	21.0
CATEGORIES=	multimedia

MAINTAINER=	rozhuk.im@gmail.com
COMMENT=	Kodi addons meta-port

USES=		metaport

GAME_ADDONS=	beetle-psx \
		fceumm \
		pcsx-rearmed \
		picodrive

INPUTSTREAM_ADDONS=	adaptive

PERIPHERAL_ADDONS=	joystick

SCREENSAVER_ADDONS=	biogenesis \
			matrixtrails \
			stars

VISUALIZATION_ADDONS=	fishbmc \
			projectm \
			shadertoy \
			spectrum


.for _type in game inputstream peripheral screensaver visualization
OPTIONS_GROUP+=		${_type:tu}
${_type:tu}_DESC=	${_type} addons
. for _addon in ${${_type:tu}_ADDONS}
OPTIONS_GROUP_${_type:tu}+=	${_addon:tu}
. endfor
.endfor


.include <bsd.port.options.mk>


.for _addon in ${GAME_ADDONS}
${_addon:tu}_DESC!=		${MAKE} -C ../../games/kodi-addon-game.libretro.${_addon} -V COMMENT
. if ${PORT_OPTIONS:M${_addon:tu}} != ""
RUN_DEPENDS+=	kodi-addon-game.libretro.${_addon}>=0:games/kodi-addon-game.libretro.${_addon}
. endif
.endfor

.for _type in inputstream peripheral screensaver visualization
. for _addon in ${${_type:tu}_ADDONS}
${_addon:tu}_DESC!=		${MAKE} -C ../kodi-addon-${_type}.${_addon} -V COMMENT
.  if ${PORT_OPTIONS:M${_addon:tu}} != ""
RUN_DEPENDS+=	kodi-addon-${_type}.${_addon}>=0:multimedia/kodi-addon-${_type}.${_addon}
.  endif
. endfor
.endfor

.include <bsd.port.mk>
