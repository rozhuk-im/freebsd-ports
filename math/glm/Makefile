# Created by: demon@FreeBSD.org
# $FreeBSD$

PORTNAME=	glm
PORTVERSION=	0.9.9.7
PORTEPOCH=	1
CATEGORIES=	math graphics

MAINTAINER=	amdmi3@FreeBSD.org
COMMENT=	C++ mathematics library for software based on the OpenGL GLSL

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/copying.txt

USE_GITHUB=	yes
GH_ACCOUNT=	g-truc

NO_ARCH=	yes

OPTIONS_DEFINE=	TEST
TEST_USES=		cmake compiler:c++17-lang
TEST_CMAKE_BOOL=	GLM_TEST_ENABLE
TEST_TEST_TARGET=	test

OPTIONS_SUB=	yes

.include <bsd.port.options.mk>

.if !${PORT_OPTIONS:MTEST}
NO_BUILD=	yes
.endif

post-patch-TEST-on:
	@${REINPLACE_CMD} -e 's|-Werror||g' \
		${WRKSRC}/test/CMakeLists.txt

do-install:
	@(cd ${WRKSRC} && ${COPYTREE_SHARE} glm ${STAGEDIR}${PREFIX}/include)
	@${MKDIR} ${STAGEDIR}${PREFIX}/lib/cmake/glm/
	@${CP} -f ${FILESDIR}/glmConfig.cmake ${STAGEDIR}${PREFIX}/lib/cmake/glm/
	@${CP} -f ${FILESDIR}/glmConfig-version.cmake ${STAGEDIR}${PREFIX}/lib/cmake/glm/

.include <bsd.port.mk>
