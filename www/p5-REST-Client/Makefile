PORTNAME=	REST-Client
DISTVERSION=	281
CATEGORIES=	www perl5
MASTER_SITES=	CPAN
PKGNAMEPREFIX=	p5-

MAINTAINER=	perl@FreeBSD.org
COMMENT=	Simple client for interacting with RESTful http/https resources
WWW=		https://metacpan.org/release/REST-Client

LICENSE=	ART10 GPLv1+
LICENSE_COMB=	dual

BUILD_DEPENDS=	${RUN_DEPENDS}
RUN_DEPENDS=	p5-LWP-Protocol-https>=6.02:www/p5-LWP-Protocol-https \
		p5-URI>0:net/p5-URI \
		p5-libwww>0:www/p5-libwww

USES=		perl5
USE_PERL5=	configure

NO_ARCH=	yes

.include <bsd.port.mk>
