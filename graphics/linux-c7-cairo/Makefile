PORTNAME=	cairo
PORTVERSION=	1.15.12
DISTVERSIONSUFFIX=	-4.el7
PORTREVISION=	2
CATEGORIES=	graphics linux

MAINTAINER=	emulation@FreeBSD.org
COMMENT=	Vector graphics library Cairo (Linux CentOS ${LINUX_DIST_VER})
WWW=		https://www.cairographics.org/

USES=		cpe linux:c7
USE_LDCONFIG=	yes
USE_LINUX=	dri fontconfig imageformats-libs pixman xorglibs
USE_LINUX_RPM=	yes
CPE_VENDOR=	cairographics

CONFLICTS=	linux-c6-${PORTNAME}
DESCR=		${.CURDIR}/../${PORTNAME}/pkg-descr

OPTIONS_DEFINE=	DOCS

.include <bsd.port.mk>
