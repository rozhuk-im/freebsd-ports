# Created by: Rozhuk Ivan <rozhuk.im@gmail.com>
# $FreeBSD: head/multimedia/kodi-addon-visualization.spectrum-devel/Makefile 528699 2020-03-19 07:54:02Z tobik $

PORTNAME=	visualization.spectrum
PORTVERSION=	3.2.0
DISTVERSIONSUFFIX=	-Matrix
CATEGORIES=	multimedia
PKGNAMEPREFIX=	kodi-addon-
PKGNAMESUFFIX=	-devel

MAINTAINER=	rozhuk.im@gmail.com
COMMENT=	Spectrum visualizer for Kodi

LICENSE=	GPLv2+

BUILD_DEPENDS=	kodi-devel>=19.0.a20200530:multimedia/kodi-devel \
		glm>=0.9.9.7:math/glm
RUN_DEPENDS=	kodi-devel>=19.0.a20200530:multimedia/kodi-devel

USES=		cmake localbase compiler:c++14-lang
USE_CXXSTD=	c++14
USE_GITHUB=	yes
GH_ACCOUNT=	xbmc
USE_GL=		egl gl glu

PLIST_SUB=	SOVERSION=${PORTVERSION}

CMAKE_ARGS=	-DADDONS_TO_BUILD=${PORTNAME}

.include <bsd.port.mk>
