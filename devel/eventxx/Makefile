PORTNAME=	eventxx
PORTVERSION=	1.0.1
PORTREVISION=	5
CATEGORIES=	devel
MASTER_SITES=	http://proj.llucax.com.ar/home/eventxx/releases/ \
		LOCAL/glarkin

MAINTAINER=	ports@FreeBSD.org
COMMENT=	C++ wrapper for libevent
WWW=		http://www.llucax.com.ar/~luca/eventxx/

DEPRECATED=	Upstream is gone, unmaintained for 10+ years in tree
EXPIRATION_DATE=2025-05-31

LIB_DEPENDS=	libevent.so:devel/libevent

NO_BUILD=	yes

OPTIONS_DEFINE=	EXAMPLES

post-extract:
	@${REINPLACE_CMD} -e 's|-I..|-I.. -I${LOCALBASE}/include -L${LOCALBASE}/lib|g' \
	    ${WRKSRC}/test/Makefile

do-install:
	${INSTALL_DATA} ${WRKSRC}/eventxx ${STAGEDIR}${PREFIX}/include
	${INSTALL} -d ${STAGEDIR}${EXAMPLESDIR}
	cd ${WRKSRC}/test && ${COPYTREE_SHARE} \*.cpp ${STAGEDIR}${EXAMPLESDIR}
	${INSTALL_DATA} ${WRKSRC}/test/Makefile ${STAGEDIR}${EXAMPLESDIR}

.include <bsd.port.mk>
