PORTNAME=	sprockets
PORTVERSION=	4.2.2
CATEGORIES=	devel rubygems
MASTER_SITES=	RG

MAINTAINER=	sunpoet@FreeBSD.org
COMMENT=	Rack-based asset packaging system
WWW=		https://github.com/rails/sprockets

LICENSE=	MIT

RUN_DEPENDS=	rubygem-concurrent-ruby>=1.0<2:devel/rubygem-concurrent-ruby \
		rubygem-logger>=0:devel/rubygem-logger \
		rubygem-rack>=2.2.4,3<4,3:www/rubygem-rack

USES=		cpe gem

NO_ARCH=	yes

PLIST_FILES=	bin/sprockets

CPE_VENDOR=	sprockets_project

.include <bsd.port.mk>
