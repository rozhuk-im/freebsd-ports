PORTNAME=	rbvmomi2
PORTVERSION=	3.8.0
CATEGORIES=	net rubygems
MASTER_SITES=	RG

MAINTAINER=	sunpoet@FreeBSD.org
COMMENT=	Ruby interface to the VMware vSphere API
WWW=		https://github.com/ManageIQ/rbvmomi2

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/LICENSE

RUN_DEPENDS=	rubygem-builder>=3.2<4:devel/rubygem-builder \
		rubygem-json>=2.3<3:devel/rubygem-json \
		rubygem-nokogiri>=1.12.5<2:textproc/rubygem-nokogiri \
		rubygem-optimist>=3.0<4:devel/rubygem-optimist

USES=		gem

NO_ARCH=	yes

PLIST_FILES=	bin/rbvmomish

.include <bsd.port.mk>
