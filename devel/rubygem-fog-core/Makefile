PORTNAME=	fog-core
PORTVERSION=	2.6.0
CATEGORIES=	devel rubygems
MASTER_SITES=	RG

MAINTAINER=	sunpoet@FreeBSD.org
COMMENT=	Shared classes and tests for fog providers and services
WWW=		https://github.com/fog/fog-core

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/LICENSE.md

RUN_DEPENDS=	rubygem-builder>=0:devel/rubygem-builder \
		rubygem-excon>=1.0<2:devel/rubygem-excon \
		rubygem-formatador>=0.2<2.0:devel/rubygem-formatador \
		rubygem-mime-types>=0:misc/rubygem-mime-types

USES=		gem

NO_ARCH=	yes

.include <bsd.port.mk>
