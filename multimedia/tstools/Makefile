PORTNAME=	tstools
DISTVERSION=	1.13_20151030
CATEGORIES=	multimedia

MAINTAINER=	rozhuk.im@gmail.com
COMMENT=	MPEG transport, program, and elementary stream tools
WWW=		https://github.com/kynesim/tstools

LICENSE=	MPL11

USES=		gmake
USE_GITHUB=	yes
GH_ACCOUNT=	kynesim
GH_TAGNAME=	db1f79f409818fa0476ecf8593079a7ca3dbafd2
MAKE_ARGS=	CC="${CC}" CFLAGS="${CFLAGS} -fPIC -DTSTOOLS_VERSION=${DISTVERSION}"

PORTDOCS=	*

OPTIONS_DEFINE=	DOCS

post-patch:
	@${REINPLACE_CMD} -e 's| -lc -lm||' \
		${WRKSRC}/Makefile

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/bin/* ${STAGEDIR}${PREFIX}/bin
	${INSTALL_DATA} ${WRKSRC}/lib/*.a ${STAGEDIR}${PREFIX}/lib

do-install-DOCS-on:
	@${MKDIR} ${STAGEDIR}${DOCSDIR}
	${INSTALL_DATA} ${WRKSRC}/docs/mdoc/* ${STAGEDIR}${DOCSDIR}

.include <bsd.port.mk>
