PORTNAME=	DateTime-Locale
PORTVERSION=	1.45
CATEGORIES=	devel perl5
MASTER_SITES=	CPAN
PKGNAMEPREFIX=	p5-

MAINTAINER=	sunpoet@FreeBSD.org
COMMENT=	Localization support for DateTime
WWW=		https://metacpan.org/release/DateTime-Locale

LICENSE=	ART10 GPLv1+
LICENSE_COMB=	dual
LICENSE_FILE=	${WRKSRC}/LICENSE

BUILD_DEPENDS=	p5-File-ShareDir-Install>=0.06:devel/p5-File-ShareDir-Install \
		${RUN_DEPENDS}
RUN_DEPENDS=	p5-Dist-CheckConflicts>=0.02:devel/p5-Dist-CheckConflicts \
		p5-File-ShareDir>=0:devel/p5-File-ShareDir \
		p5-Params-ValidationCompiler>=0.13:devel/p5-Params-ValidationCompiler \
		p5-Specio>=0:devel/p5-Specio \
		p5-namespace-autoclean>=0.19:devel/p5-namespace-autoclean
TEST_DEPENDS=	p5-CPAN-Meta-Check>=0.011:devel/p5-CPAN-Meta-Check \
		p5-IPC-System-Simple>=0:devel/p5-IPC-System-Simple \
		p5-Path-Tiny>=0:devel/p5-Path-Tiny \
		p5-Test-File-ShareDir>=0:devel/p5-Test-File-ShareDir \
		p5-Test2-Plugin-NoWarnings>=0:devel/p5-Test2-Plugin-NoWarnings \
		p5-Test-Simple>=1.302200:devel/p5-Test-Simple

USES=		perl5
USE_PERL5=	configure

NO_ARCH=	yes

.include <bsd.port.mk>
