# $FreeBSD$

PORTNAME=	pycognito
PORTVERSION=	0.1.4
CATEGORIES=	devel python
MASTER_SITES=	CHEESESHOP
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	rozhuk.im@gmail.com
COMMENT=	Python class to integrate Boto3's Cognito client so it is easy to login users. With SRP support

LICENSE=	APACHE20

RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}boto3>0:www/py-boto3@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}envs>0:devel/py-envs@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}python-jose>0:security/py-python-jose@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}requests>0:www/py-requests@${PY_FLAVOR}

USES=		python:3.6+
USE_PYTHON=	distutils autoplist

post-patch:
	@${REINPLACE_CMD} -e 's|==|>=|g' \
		${WRKSRC}/setup.py

.include <bsd.port.mk>
