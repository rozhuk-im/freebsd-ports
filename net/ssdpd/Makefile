PORTNAME=	ssdpd
PORTVERSION=	1.8.0
CATEGORIES=	net

MAINTAINER=	rozhuk.im@gmail.com
COMMENT=	SSDP announcer daemon for UPnP/DLNA and PHP UPnP/DLNA Media server
WWW=		https://github.com/rozhuk-im/ssdpd

LICENSE=	BSD3CLAUSE

USE_GITHUB=	yes
GH_ACCOUNT=	rozhuk-im:DEFAULT \
		rozhuk-im:lib_lcb
GH_PROJECT=	ssdpd:DEFAULT \
		liblcb:lib_lcb
GH_TAGNAME=	a086b27ec1ce0b0eda87bff2b841a44837fa91aa:DEFAULT \
		154cf601a061c06ccc3ec3642c578e5c5ac40c90:lib_lcb
GH_SUBDIR=	src/liblcb:lib_lcb

USES=		cmake
PKGMESSAGE=	${WRKSRC}/pkg-message
SUB_FILES=	pkg-message

OPTIONS_DEFINE=	INSTALL_MEDIA_SRV
OPTIONS_DEFAULT=INSTALL_MEDIA_SRV
OPTIONS_SUB=	yes

INSTALL_MEDIA_SRV_DESC=		Install PHP UPnP/DLNA Media server
INSTALL_MEDIA_SRV_CMAKE_BOOL=	INSTALL_PHP_MEDIA_SERVER
INSTALL_MEDIA_SRV_RUN_DEPENDS=	nginx:www/nginx

.include <bsd.port.options.mk>

.if ${PORT_OPTIONS:MINSTALL_MEDIA_SRV}
USES+=		php
USE_PHP=	fileinfo soap xml
SHAREOWN=	${WWWOWN}
SHAREGRP=	${WWWGRP}
.endif

post-install-INSTALL_MEDIA_SRV-on:
	@${FIND} ${STAGEDIR}${ETCDIR}/ -type f -name '*.conf' -exec ${MV} {} {}.sample \;
	@${MV} ${STAGEDIR}${ETCDIR}/../php-fpm.d/upnp-server.conf ${STAGEDIR}${ETCDIR}/../php-fpm.d/upnp-server.conf.sample

.include <bsd.port.mk>
