PORTNAME=	opentelemetry-instrumentation-mysql2
PORTVERSION=	0.29.1
CATEGORIES=	devel rubygems
MASTER_SITES=	RG

MAINTAINER=	sunpoet@FreeBSD.org
COMMENT=	MySQL2 instrumentation for the OpenTelemetry framework
WWW=		https://opentelemetry.io/ \
		https://github.com/open-telemetry/opentelemetry-ruby-contrib/tree/main/instrumentation/mysql2 \
		https://github.com/open-telemetry/opentelemetry-ruby-contrib

LICENSE=	APACHE20
LICENSE_FILE=	${WRKSRC}/LICENSE

RUN_DEPENDS=	rubygem-opentelemetry-api>=1.0<2:devel/rubygem-opentelemetry-api \
		rubygem-opentelemetry-helpers-mysql>=0:devel/rubygem-opentelemetry-helpers-mysql \
		rubygem-opentelemetry-helpers-sql>=0:devel/rubygem-opentelemetry-helpers-sql \
		rubygem-opentelemetry-helpers-sql-obfuscation>=0:devel/rubygem-opentelemetry-helpers-sql-obfuscation \
		rubygem-opentelemetry-instrumentation-base>=0.23.0<0.24:devel/rubygem-opentelemetry-instrumentation-base

USES=		gem

NO_ARCH=	yes

.include <bsd.port.mk>
