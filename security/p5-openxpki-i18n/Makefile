PORTNAME=	openxpki
DISTVERSIONPREFIX=	v
DISTVERSION=	3.24.2
CATEGORIES=	security perl5
PKGNAMEPREFIX=	p5-
PKGNAMESUFFIX=	-i18n

MAINTAINER=	svysh.fbsd@gmail.com
COMMENT=	Perl based trustcenter software for PKI: i18n tools
WWW=		https://www.openxpki.org/

LICENSE=	APACHE20
LICENSE_FILE=	${WRKSRC}/../../LICENSE

# We cannot go without NLS. Internationalization is needed even for English.
USES=		gettext-runtime gettext-tools gmake perl5

USE_GITHUB=	yes
MAKE_JOBS_UNSAFE=	yes

ALL_TARGET=	scan default
NO_ARCH=	yes

# Track stable versions.
PORTSCOUT=	limitw:1,even

WRKSRC_SUBDIR=	core/i18n

.include <bsd.port.mk>
