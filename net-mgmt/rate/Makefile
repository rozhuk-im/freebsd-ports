PORTNAME=	rate
PORTVERSION=	0.9
PORTREVISION=	4
CATEGORIES=	net-mgmt
MASTER_SITES=	http://s-tech.elsat.net.pl/bmtools/

MAINTAINER=	portmaster@bsdforge.com
COMMENT=	Traffic analysis command-line utility
WWW=		http://s-tech.elsat.net.pl/

LICENSE=	GPLv2
LICENSE_FILE=	${WRKSRC}/COPYING

MAKE_ARGS=	CC="${CC}" CFLAGS="${CFLAGS}" LDFLAGS="${LDFLAGS}"
LDFLAGS+=	-lcompat -lutil
CFLAGS+=	-DOPEN_BSD=1 -DHAVE_REGEX -DSTREAM_ANALYZER -DIOCTL_GETWINSIZE -DAUTOSENSE_DLH

PLIST_FILES=	bin/rate share/man/man1/rate.1.gz

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/rate ${STAGEDIR}${PREFIX}/bin/rate
	${INSTALL_MAN} ${WRKSRC}/doc/rate.1 ${STAGEDIR}${PREFIX}/share/man/man1

.include <bsd.port.mk>
