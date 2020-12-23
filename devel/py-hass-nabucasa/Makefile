# $FreeBSD$

PORTNAME=	hass-nabucasa
PORTVERSION=	0.38.0
CATEGORIES=	devel python
MASTER_SITES=	CHEESESHOP
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	rozhuk.im@gmail.com
COMMENT=	Home Assistant cloud integration by Nabu Casa, Inc.

LICENSE=	GPLv3

RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}pycognito>0:devel/py-pycognito@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}snitun>0:devel/py-snitun@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}acme>0:security/py-acme@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}cryptography>0:security/py-cryptography@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}attrs>0:devel/py-attrs@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}pytz>0:devel/py-pytz@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}aiohttp>0:www/py-aiohttp@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}atomicwrites>0:devel/py-atomicwrites@${PY_FLAVOR}

USES=		python:3.6+
USE_PYTHON=	distutils autoplist

post-patch:
	@${REINPLACE_CMD} -e 's|==|>=|g' \
		${WRKSRC}/setup.py

.include <bsd.port.mk>
