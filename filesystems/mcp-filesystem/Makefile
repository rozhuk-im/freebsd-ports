PORTNAME=	mcp-filesystem
DISTVERSION=	20250814
CATEGORIES=	filesystems

MAINTAINER=	rozhuk.im@gmail.com
COMMENT=	Go implementation of MCP server filesystem
WWW=		https://github.com/ad/mcp-filesystem

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/LICENSE

USES=		go

USE_GITHUB=	yes
GH_ACCOUNT=	ad
GH_TAGNAME=	74b3d59237ea913a5ae8b923e0f153a4113e840f

PLIST_FILES=	bin/mcp-filesystem

# make gomod-vendor > Makefile.gomod
.include "${.CURDIR}/Makefile.gomod"

post-extract:
	${MKDIR} ${WRKSRC}/vendor/github.com/ad/
	${LN} -s ${WRKSRC} ${WRKSRC}/vendor/github.com/ad/mcp-filesystem

.include <bsd.port.mk>
