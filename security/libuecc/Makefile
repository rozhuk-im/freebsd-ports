PORTNAME=	libuecc
PORTVERSION=	7
PORTREVISION=	3
CATEGORIES=	security
MASTER_SITES=	https://git.universe-factory.net/libuecc/snapshot/ \
		http://git.universe-factory.net/libuecc/snapshot/

MAINTAINER=	crest_maintainer@rlwinm.de
COMMENT=	Very small Elliptic Curve Cryptography library
WWW=		https://git.universe-factory.net/libuecc

LICENSE=	BSD2CLAUSE
LICENSE_FILE=	${WRKSRC}/COPYRIGHT

LIB_DEPENDS=	libsodium.so:security/libsodium

USES=		cmake pkgconfig tar
USE_LDCONFIG=	yes

.include <bsd.port.mk>
