PORTNAME=	libstatgrab
PORTVERSION=	0.17
CATEGORIES=	devel
MASTER_SITES=	http://ftp.mirrorservice.org/pub/i-scream/libstatgrab/ \
		http://dl.ambiweb.de/mirrors/ftp.i-scream.org/libstatgrab/ \
		http://ftp.i-scream.org/pub/i-scream/libstatgrab/
PKGNAMESUFFIX=	0

MAINTAINER=	tdb@FreeBSD.org
COMMENT=	Provides a useful interface to system statistics
WWW=		https://www.i-scream.org/libstatgrab/

DEPRECATED=	Use devel/libstatgrab instead.
EXPIRATION_DATE=2025-12-31

USE_LDCONFIG=	yes
GNU_CONFIGURE=	yes
USES=		pathfix pkgconfig libtool

CONFIGURE_ARGS=	--disable-examples \
		--disable-manpages \
		--disable-saidar \
		--disable-statgrab \
		--disable-deprecated

post-configure:
	${CP} ${WRKSRC}/libstatgrab.pc ${WRKSRC}/libstatgrab0.pc

post-install:
	${MV} ${STAGEDIR}${PREFIX}/include/statgrab.h ${STAGEDIR}${PREFIX}/include/statgrab0.h

.include <bsd.port.mk>
