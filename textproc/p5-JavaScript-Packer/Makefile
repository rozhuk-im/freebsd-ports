PORTNAME=	JavaScript-Packer
PORTVERSION=	2.12
CATEGORIES=	textproc www perl5
MASTER_SITES=	CPAN
PKGNAMEPREFIX=	p5-

MAINTAINER=	sunpoet@FreeBSD.org
COMMENT=	Perl version of Dean Edwards' Packer.js
WWW=		https://metacpan.org/release/JavaScript-Packer

LICENSE=	ART10 GPLv1+
LICENSE_COMB=	dual

BUILD_DEPENDS=	${RUN_DEPENDS}
RUN_DEPENDS=	p5-Regexp-RegGrp>=1.001001:devel/p5-Regexp-RegGrp
TEST_DEPENDS=	p5-Test-Pod>=1.22:devel/p5-Test-Pod

USES=		perl5
USE_PERL5=	configure

NO_ARCH=	yes

.include <bsd.port.mk>
