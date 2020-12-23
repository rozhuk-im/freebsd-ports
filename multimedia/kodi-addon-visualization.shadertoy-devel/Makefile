# Created by: Rozhuk Ivan <rozhuk.im@gmail.com>
# $FreeBSD: head/multimedia/kodi-addon-visualization.shadertoy-devel/Makefile 528699 2020-03-19 07:54:02Z tobik $

PORTNAME=	visualization.shadertoy
PORTVERSION=	2.1.1
DISTVERSIONSUFFIX=	-Matrix
CATEGORIES=	multimedia
PKGNAMEPREFIX=	kodi-addon-
PKGNAMESUFFIX=	-devel

MAINTAINER=	rozhuk.im@gmail.com
COMMENT=	Shadertoy visualizer for Kodi

LICENSE=	GPLv2+

BUILD_DEPENDS=	kodi-devel>=19.0.a20200530:multimedia/kodi-devel \
		glm>=0.9.9.7:math/glm
LIB_DEPENDS=	libp8-platform.so:devel/p8-platform
RUN_DEPENDS=	kodi-devel>=19.0.a20200530:multimedia/kodi-devel

USES=		cmake localbase
USE_GITHUB=	yes
GH_ACCOUNT=	xbmc
USE_GL=		egl gl glu

PLIST_SUB=	SOVERSION=${PORTVERSION}

CMAKE_ARGS=	-DADDONS_TO_BUILD=${PORTNAME}

post-patch:
	@${REINPLACE_CMD} -e 's|delete buffer;|delete[] buffer;|g' \
		${WRKSRC}/src/main.cpp

.include <bsd.port.mk>
