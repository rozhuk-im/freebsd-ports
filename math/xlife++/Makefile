PORTNAME=	xlife++
DISTVERSION=	2.3
CATEGORIES=	math
MASTER_SITES=	https://uma.ensta-paristech.fr/soft/XLiFE++/downloads/binaries/
DISTNAME=	xlifepp-sources-v${DISTVERSION}-2022-04-22

MAINTAINER=	yuri@FreeBSD.org
COMMENT=	XLiFE++: eXtended Library of Finite Elements in C++
WWW=		https://xlifepp.pages.math.cnrs.fr/ \
		https://uma.ensta-paristech.fr/soft/XLiFE++/

LICENSE=	GPLv3
LICENSE_FILE=	${WRKSRC}/LICENSE.txt

BROKEN_FreeBSD_15=	compilation fails with clang-19, e-mailed to authors on 2024-11-03

USES=		cmake compiler:c++11-lang eigen:3 fortran tar:tbz
USE_CXXSTD=	c++11
USE_LDCONFIG=	yes

CMAKE_OFF=	XLIFEPP_ENABLE_ARPACK # should be ON, but it fails to build. Reported to their bugs ML.

CXXFLAGS+=	-I${LOCALBASE}/include/eigen3/Eigen -I${LOCALBASE}/include/ARPACK++

PORTDOCS=	*
PORTEXAMPLES=	*

OPTIONS_DEFINE=	DOCS EXAMPLES

post-extract: # delete bundled packages
	@${RM} -r ${WRKSRC}/ext/Eigen ${WRKSRC}/ext/ARPACK ${WRKSRC}/ext/ARPACK++

post-configure:
	@${REINPLACE_CMD} -E 's/.*(ARPACK|Eigen)/#&/' ${CONFIGURE_WRKSRC}/cmake_install.cmake

post-install:
	@cd ${STAGEDIR}${PREFIX} && ${RM} -r CMakeLists.txt VERSION.txt etc/visuTermVec.m etc/templates etc/gmsh

.include <bsd.port.mk>
