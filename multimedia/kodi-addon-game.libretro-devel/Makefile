# Created by: Rozhuk Ivan <rozhuk.im@gmail.com>
# $FreeBSD: head/multimedia/kodi-addon-game.libretro-devel/Makefile 528699 2020-03-19 07:54:02Z tobik $

PORTNAME=	game.libretro
PORTVERSION=	2.2.0
DISTVERSIONSUFFIX=	-Matrix
CATEGORIES=	multimedia games
PKGNAMEPREFIX=	kodi-addon-
PKGNAMESUFFIX=	-devel

MAINTAINER=	rozhuk.im@gmail.com
COMMENT=	Libretro compatibility layer for the Kodi Game API

LICENSE=	GPLv2+

BUILD_DEPENDS=	kodi-devel>=19.0.a20200530:multimedia/kodi-devel
LIB_DEPENDS=	libtinyxml.so:textproc/tinyxml \
		libp8-platform.so:devel/p8-platform
RUN_DEPENDS=	kodi-devel>=19.0.a20200530:multimedia/kodi-devel

USES=		cmake localbase compiler:c++14-lang
USE_GITHUB=	yes
USE_CXXSTD=	c++14
GH_ACCOUNT=	kodi-game

PLIST_SUB=	SOVERSION=${PORTVERSION}

.include <bsd.port.mk>
