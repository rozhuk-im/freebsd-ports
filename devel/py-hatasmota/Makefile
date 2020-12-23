# $FreeBSD$

PORTNAME=	HATasmota
PORTVERSION=	0.1.0
CATEGORIES=	devel python
MASTER_SITES=	CHEESESHOP
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	rozhuk.im@gmail.com
COMMENT=	Python module to help parse and construct Tasmota MQTT messages

LICENSE=	MIT

RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}attrs>0:devel/py-attrs@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}voluptuous>0:devel/py-voluptuous@${PY_FLAVOR}

USES=		python
USE_PYTHON=	distutils autoplist

post-patch:
	@${REINPLACE_CMD} -e 's|==|>=|g' \
		${WRKSRC}/requirements.txt

.include <bsd.port.mk>
