PORTNAME=	godot
DISTVERSION=	4.4.1
DISTVERSIONSUFFIX=	-stable
PORTREVISION?=	0
CATEGORIES=	devel games

MAINTAINER=	FreeBSD@Shaneware.biz
COMMENT?=	Game runtime engine
WWW=		https://godotengine.org/

LICENSE=	CC-BY-3.0 MIT
LICENSE_COMB=	multi
LICENSE_FILE_CC-BY-3.0=	${WRKSRC}/LOGO_LICENSE.txt
LICENSE_FILE_MIT=	${WRKSRC}/LICENSE.txt

BUILD_DEPENDS=	yasm:devel/yasm
LIB_DEPENDS=	libfreetype.so:print/freetype2 \
		libgraphite2.so:graphics/graphite2 \
		libharfbuzz-icu.so:print/harfbuzz-icu \
		libharfbuzz.so:print/harfbuzz \
		libpcre2-8.so:devel/pcre2 \
		libpng.so:graphics/png \
		libvpx.so:multimedia/libvpx
RUN_DEPENDS=	xdg-open:devel/xdg-utils \
		xdg-user-dir:devel/xdg-user-dirs \
		xmessage:x11/xmessage

USES=		compiler:c++17-lang cpe gl pkgconfig scons xorg
CPE_VENDOR=	godotengine
USE_GITHUB=	yes
GH_ACCOUNT=	godotengine

USE_GL=		gl glew glu
USE_XORG=	x11 xcursor xext xi xinerama xrandr xrender

MAKE_ARGS+=		platform=linuxbsd builtin_freetype=False \
			builtin_graphite=False builtin_harfbuzz=False \
			builtin_libpng=False builtin_libvpx=False \
			builtin_pcre2=False builtin_zlib=False verbose=True
MAKE_ARGS+=		${MAKE_ARGS_${CHOSEN_COMPILER_TYPE}}
MAKE_ARGS_clang=	use_llvm=True linker=lld
CXXFLAGS_i386=		${CXXFLAGS_i386_${CHOSEN_COMPILER_TYPE}}
CXXFLAGS_i386_gcc=	-march=i586

GODOTFILE=	${PORTNAME}${PKGNAMESUFFIX}
PLIST_FILES=	bin/${GODOTFILE}

OPTIONS_DEFINE=		EXAMPLES TEST TOOLS UDEV
OPTIONS_DEFAULT=	ALSA UDEV
OPTIONS_GROUP=		AUDIO
OPTIONS_GROUP_AUDIO=	ALSA PULSEAUDIO
# Moved to devel/godot-tools
OPTIONS_EXCLUDE?=	EXAMPLES TOOLS

AUDIO_DESC=	Audio support
TOOLS_DESC=	Include development tools (IDE)
UDEV_DESC=	Libudev support (Joystick)

ALSA_LIB_DEPENDS=		libasound.so:audio/alsa-lib
ALSA_MAKE_ARGS=			alsa=True
ALSA_MAKE_ARGS_OFF=		alsa=False
# master head at 6/3 - no branch made for 4.4 yet
EXAMPLES_GH_TUPLE=		godotengine:godot-demo-projects:fdb2f50a2088:DEMOS
EXAMPLES_PORTEXAMPLES=		*
PULSEAUDIO_LIB_DEPENDS=		libpulse.so:audio/pulseaudio
PULSEAUDIO_MAKE_ARGS=		pulseaudio=True
PULSEAUDIO_MAKE_ARGS_OFF=	pulseaudio=False
TEST_MAKE_ARGS=			tests=True
TOOLS_MAKE_ARGS=		target=editor
TOOLS_MAKE_ARGS_OFF=		target=template_release
TOOLS_DESKTOP_ENTRIES=	"Godot" "${COMMENT}" "${GODOTFILE}" \
			"${GODOTFILE}" "Development;IDE;" ""
TOOLS_PLIST_FILES=		share/pixmaps/${GODOTFILE}.png \
				share/pixmaps/${GODOTFILE}.svg
UDEV_BUILD_DEPENDS=		${PREFIX}/include/linux/input.h:devel/evdev-proto
UDEV_LIB_DEPENDS=		libudev.so:devel/libudev-devd
UDEV_MAKE_ARGS=			udev=True
UDEV_MAKE_ARGS_OFF=		udev=False

.ifmake makesum
# Always include optional distfiles
.MAKEFLAGS:	WITH="${OPTIONS_DEFINE}" OPTIONS_EXCLUDE=
.endif

.include <bsd.port.options.mk>

.if ${ARCH:Mpowerpc*} || ${ARCH:Mriscv64*}
MAKE_ARGS+=	module_embree_enabled=no \
		module_raycast_enabled=no \
		module_webm_enabled=no
.endif

post-patch:
	@${REINPLACE_CMD} -e 's|custom_build|${OPSYS}_Ports_build|' \
		${WRKSRC}/methods.py

# The official godot binary name reflects options used to compile
# We just want a simple name matching the portname
# This gives us bin/godot for runtime and bin/godot-tools for the IDE
do-install:
	@${RM} ${WRKSRC}/bin/*.debugsymbols
	cd ${WRKSRC}/bin && ${INSTALL_PROGRAM} godot.linuxbsd* \
		${STAGEDIR}/${PREFIX}/bin/${GODOTFILE}

do-install-EXAMPLES-on:
	(cd ${WRKSRC_DEMOS} && ${COPYTREE_SHARE} "${PORTEXAMPLES}" \
		${STAGEDIR}${EXAMPLESDIR})

do-install-TOOLS-on:
	${INSTALL_DATA} ${WRKSRC}/icon.png \
		${STAGEDIR}${PREFIX}/share/pixmaps/${GODOTFILE}.png
	${INSTALL_DATA} ${WRKSRC}/icon.svg \
		${STAGEDIR}${PREFIX}/share/pixmaps/${GODOTFILE}.svg

.if ${PORT_OPTIONS:MTEST}
do-test:
	${MKDIR} ~/.cache/godot
	cd ${TEST_WRKSRC} && bin/godot.linuxbsd* --verbose --test
.endif

.include <bsd.port.mk>
