PORTNAME=	freetype-gl
DISTVERSIONPREFIX=	v
DISTVERSION=	1.0
CATEGORIES=	graphics

MAINTAINER=	yuri@FreeBSD.org
COMMENT=	C OpenGL Freetype engine library
WWW=		https://github.com/rougier/freetype-gl

LICENSE=	BSD2CLAUSE
LICENSE_FILE=	${WRKSRC}/LICENSE

LIB_DEPENDS=	libfreetype.so:print/freetype2

USES=		cmake:noninja gl magick:test,nox11
USE_GL=		gl glew glu
USE_LDCONFIG=	yes

USE_GITHUB=	yes
GH_ACCOUNT=	rougier

CMAKE_ON=	freetype-gl_BUILD_SHARED
CMAKE_OFF=	freetype-gl_BUILD_APIDOC freetype-gl_BUILD_TESTS \
		FIND_LIBRARY_USE_LIB64_PATHS

LDFLAGS+=	-L${LOCALBASE}/lib -lGLEW -lfreetype # https://github.com/rougier/freetype-gl/issues/236

OPTIONS_DEFINE=		DEMOS
OPTIONS_SUB=		yes

DEMOS_DESC=		Build and install demo programs
DEMOS_CMAKE_BOOL=	freetype-gl_BUILD_DEMOS
DEMOS_LIB_DEPENDS=	libAntTweakBar.so:graphics/anttweakbar \
			libfontconfig.so:x11-fonts/fontconfig \
			libglfw.so:graphics/glfw

post-patch-DEMOS-on:
	@${REINPLACE_CMD} -i '' 's|"data/|"${DATADIR}/data/|g ; s|"fonts/|"${DATADIR}/fonts/|g ; s|"shaders/|"${DATADIR}/shaders/|g' ${WRKSRC}/demos/*.c

do-test: # build breaks: https://github.com/rougier/freetype-gl/issues/234
	@cd ${BUILD_WRKSRC} && \
		${SETENV} ${CONFIGURE_ENV} ${CMAKE_BIN} ${CMAKE_ARGS} -Dfreetype-gl_BUILD_TESTS:BOOL=ON ${CMAKE_SOURCE_PATH} && \
		${SETENV} ${MAKE_ENV} ${MAKE_CMD} ${MAKE_ARGS} ${ALL_TARGET} && \
		${SETENV} ${MAKE_ENV} ${MAKE_CMD} ${MAKE_ARGS} test

do-install-DEMOS-on:
.for e in ansi atb-agg benchmark cartoon console cube distance-field distance-field-2 distance-field-3 embedded-font font gamma glyph lcd markup outline subpixel texture
	${INSTALL_PROGRAM} ${BUILD_WRKSRC}/demos/${e} ${STAGEDIR}${PREFIX}/bin/ftgl-demo-${e}
.endfor
	cd ${BUILD_WRKSRC}/demos && ${COPYTREE_SHARE} "data fonts shaders" ${STAGEDIR}${DATADIR}

.include <bsd.port.mk>
