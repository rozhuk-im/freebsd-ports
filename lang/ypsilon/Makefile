PORTNAME=	ypsilon
PORTVERSION=	0.9.6.3
PORTREVISION=	13
CATEGORIES=	lang scheme

MAINTAINER=	vmagerya@gmail.com
COMMENT=	Scheme implementation for real-time applications
WWW=		http://www.littlewingpinball.net/mediawiki/index.php/Ypsilon

LICENSE=	BSD3CLAUSE
LICENSE_FILE=	${WRKSRC}/license.txt

USE_GITHUB=	yes
GH_TUPLE=	fujita-y:ypsilon:0.9.6-update3

USES=		gmake
USE_BINUTILS=	yes
TEST_TARGET=	check  # XXX: tests fail

MAKE_ARGS=	DATADIR="${DATADIR}"

ONLY_FOR_ARCHS=	i386 amd64

OPTIONS_DEFINE=	EXAMPLES

post-patch:
	@${REINPLACE_CMD} 's/-fno-[a-z-]*//g' ${WRKSRC}/Makefile

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/${PORTNAME} ${STAGEDIR}${PREFIX}/bin
	${INSTALL_MAN} ${WRKSRC}/${PORTNAME}.1 ${STAGEDIR}${PREFIX}/share/man/man1
	@${MKDIR} ${STAGEDIR}${DATADIR}
	(cd ${WRKSRC}/ && ${COPYTREE_SHARE} "sitelib stdlib" ${STAGEDIR}${DATADIR})

do-install-EXAMPLES-on:
	@${MKDIR} ${STAGEDIR}${EXAMPLESDIR}
	${INSTALL_DATA} ${WRKSRC}/example/*.scm ${STAGEDIR}${EXAMPLESDIR}

.include <bsd.port.mk>
