PORTNAME=	phpvirtualbox
DISTVERSION=	6.1
PORTREVISION=	5
CATEGORIES=	www
PKGNAMESUFFIX=	${PHP_PKGNAMESUFFIX}

PATCH_SITES=	https://github.com/${GH_ACCOUNT}/${GH_PROJECT}/commit/
PATCHFILES+=	509134cdd22339b9c63decb8731119b639d21db3.patch:-p1 # https://github.com/phpvirtualbox/phpvirtualbox/pull/292
PATCHFILES+=	26b0e999c715e7b690fa85013ebee3a8b31ad8c2.patch:-p1 # https://github.com/phpvirtualbox/phpvirtualbox/pull/299

MAINTAINER=	vbox@FreeBSD.org
COMMENT=	AJAX Web Interface for VirtualBox
WWW=		https://sourceforge.net/projects/phpvirtualbox/

LICENSE=	GPLv3

USES=		dos2unix php:flavors
DOS2UNIX_REGEX=	.*\.(php|txt|js|css|html)
USE_GITHUB=	yes
GH_TAGNAME=	cf82d58f2
USE_PHP=	session simplexml soap xml

ETCDIR=		${WWWDIR}
NO_ARCH=	yes
NO_BUILD=	yes
PORTSCOUT=	limit:^6\.

post-patch:
	@${REINPLACE_CMD} -e 's#/usr/share/phpvirtualbox#${WWWDIR}#g' \
		${WRKSRC}/phpvirtualbox.conf

do-install:
	${MKDIR} ${STAGEDIR}${WWWDIR}
	(cd ${WRKSRC}/ && ${COPYTREE_SHARE} "*" ${STAGEDIR}${WWWDIR} \
	    "-not -name *.orig -not -name config.php-example")
	${INSTALL_DATA} ${WRKSRC}/config.php-example \
	    ${STAGEDIR}${WWWDIR}/config.php.sample

.include <bsd.port.mk>
