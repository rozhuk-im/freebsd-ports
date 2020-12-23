# Created by: Rozhuk Ivan <rozhuk.im@gmail.com>
# $FreeBSD: head/multimedia/kodi-addon-screensaver.matrixtrails-devel/Makefile 528699 2020-03-19 07:54:02Z tobik $

PORTNAME=	screensaver.matrixtrails
PORTVERSION=	2.4.2
DISTVERSIONSUFFIX=	-Matrix
CATEGORIES=	multimedia
PKGNAMEPREFIX=	kodi-addon-
PKGNAMESUFFIX=	-devel

MAINTAINER=	rozhuk.im@gmail.com
COMMENT=	Matrix trails screensaver for Kodi

LICENSE=	GPLv2+

BUILD_DEPENDS=	kodi-devel>=19.0.a20200530:multimedia/kodi-devel
RUN_DEPENDS=	kodi-devel>=19.0.a20200530:multimedia/kodi-devel

USES=		cmake
USE_GITHUB=	yes
GH_ACCOUNT=	xbmc
USE_GL=		egl gl glu

PLIST_SUB=	SOVERSION=${PORTVERSION}

CMAKE_ARGS=	-DADDONS_TO_BUILD=${PORTNAME}

.include <bsd.port.mk>
