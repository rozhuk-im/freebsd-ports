# $FreeBSD$

PORTNAME=	astral1
PORTVERSION=	1.10.1
CATEGORIES=	astro python
MASTER_SITES=	CHEESESHOP
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}
DISTNAME=	astral-${PORTVERSION}

MAINTAINER=	rozhuk.im@gmail.com
COMMENT=	Calculations for the position of the sun and moon

LICENSE=	APACHE20
LICENSE_FILE=	${WRKSRC}/LICENSE

RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}pytz>0:devel/py-pytz@${PY_FLAVOR}

USES=		python:3.7+
USE_PYTHON=	autoplist concurrent distutils

.include <bsd.port.mk>
