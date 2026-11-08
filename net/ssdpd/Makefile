PORTNAME=	ssdpd
PORTVERSION=	1.9.1
CATEGORIES=	net

MAINTAINER=	rozhuk.im@gmail.com
COMMENT=	SSDP announcer daemon for UPnP/DLNA and PHP UPnP/DLNA Media server
WWW=		https://github.com/rozhuk-im/ssdpd

LICENSE=	BSD3CLAUSE

USE_GITHUB=	yes
GH_ACCOUNT=	rozhuk-im:DEFAULT \
		rozhuk-im:liblcb \
		rozhuk-im:ssbs
GH_PROJECT=	ssdpd:DEFAULT \
		liblcb:liblcb \
		ssbs:ssbs
GH_TAGNAME=	c694689237b2eaa2f2c31f00da5ed6e8015e4234:DEFAULT \
		416814f4ea9bfbd74c7da49364b53262bb7baf2b:liblcb \
		2579b9e8fcb5aaa2a6cdd3101d0ee7f990d44b5e:ssbs
GH_SUBDIR=	3rdparty/liblcb:liblcb \
		3rdparty/ssbs:ssbs

USE_RC_SUBR=	ssdpd
PKGMESSAGE=	${WRKSRC}/pkg-message
SUB_FILES=	pkg-message

OPTIONS_DEFINE=	INSTALL_MEDIA_SRV
OPTIONS_DEFAULT=INSTALL_MEDIA_SRV
OPTIONS_SUB=	yes

INSTALL_MEDIA_SRV_DESC=		Install PHP UPnP/DLNA Media server
INSTALL_MEDIA_SRV_RUN_DEPENDS=	nginx:www/nginx

.include <bsd.port.options.mk>

.if ${PORT_OPTIONS:MINSTALL_MEDIA_SRV}
USES+=		php
USE_PHP=	fileinfo soap xml
SHAREOWN=	${WWWOWN}
SHAREGRP=	${WWWGRP}
.endif

do-build:
	@${WRKSRC}/make.sh

do-install:
	@${MKDIR} ${STAGEDIR}${PREFIX}/etc/ssdpd
	@${INSTALL_PROGRAM} ${WRKSRC}/build-release/ssdpd ${STAGEDIR}${PREFIX}/bin
	@${INSTALL_DATA} ${WRKSRC}/ssdpd.conf ${STAGEDIR}${PREFIX}/etc/ssdpd/ssdpd.conf.sample

post-install-INSTALL_MEDIA_SRV-on:
	@${MKDIR} ${STAGEDIR}${PREFIX}/etc/php-fpm.d \
		${STAGEDIR}/${DATADIR}/www/upnpdata
	@${INSTALL_DATA} ${WRKSRC}/php/upnp-server.conf ${STAGEDIR}${ETCDIR}/../php-fpm.d/upnp-server.conf.sample
	@(cd ${WRKSRC}/nginx && ${COPYTREE_SHARE} . ${STAGEDIR}${PREFIX}/etc/ssdpd/)
	@(cd ${WRKSRC}/www && ${COPYTREE_SHARE} . ${STAGEDIR}${DATADIR}/www)
	@${FIND} ${STAGEDIR}${ETCDIR}/ -type f -name '*.conf' -exec ${MV} {} {}.sample \;

.include <bsd.port.mk>
